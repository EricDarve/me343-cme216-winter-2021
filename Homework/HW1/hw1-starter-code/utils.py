import numpy as np
from sklearn.datasets import make_circles, make_moons, make_blobs
import os
import matplotlib.pyplot as plt
import plotly.graph_objects as go


def generate_data_lin(N=1000):
    x, y = make_blobs(N, centers=np.array(
        [[-1, -1], [1, 1]]), n_features=2, cluster_std=0.2)
    y[y == 0] = -1
    return x, y


def generate_data_basis(P, noise, N):
    if P == 'circle':
        phi = np.random.randn(N) * 2 * np.pi
        x1 = np.cos(phi)
        x2 = np.sin(phi)

        y = np.ones((N, 1))
        y[((x1 < 0) & (x2 > 0)) | ((x1 > 0) & (x2 < 0))] = -1

        x = np.stack((x1, x2), axis=1) + np.random.rand(N, 2) * noise

        return x, y.flatten()

    if P == 'inner_circle':
        x, y = make_circles(N, factor=0.2, noise=noise)
        y[y == 0] = -1

        return x, y


def generate_data_moons(noise):
    x_train, y_train = make_moons(500, noise=noise, random_state=75)
    y_train[y_train == 0] = -1
    x_test, y_test = make_moons(500, noise=noise, random_state=233)
    y_test[y_test == 0] = -1

    return x_train, y_train, x_test, y_test


def generate_data_non_lin(N=1000):
    x = np.random.randn(N, 2)
    w = np.array([-.00, 0.01, 0.1, -0.04, 0.09, 0.02])
    features = np.hstack([np.ones([N, 1]), x, x**2, x[:, :1]*x[:, 1:2]])
    f = np.dot(features, w)
    labels = 2*((f + np.random.randn(N)*0.02) > 0) - 1
    return x, labels


def maybe_makedirs(path_to_create):
    """This function will create a directory, unless it exists already,
    at which point the function will return.
    The exception handling is necessary as it prevents a race condition
    from occurring.
    Inputs:
        path_to_create - A string path to a directory you'd like created.
    """
    try:
        os.makedirs(path_to_create)
    except OSError:
        if not os.path.isdir(path_to_create):
            raise


def plot_data_decision_function(data, y_pred, clf, preprocessing=None):
    x_train = data['x_train']
    y_train = data['y_train']
    x_pred = data['x_pred']
    y_true = data['y_true']

    plt.figure()
    plt.subplot(1, 2, 1)
    c = ['powderblue' if lb == 1 else 'indianred' for lb in y_train]
    plt.scatter(x_train[:, 0], x_train[:, 1], c=c, alpha=0.5, s=50)
    plt.title("Training Set")

    plt.subplot(1, 2, 2)
    c = ['powderblue' if lb == 1 else 'indianred' for lb in y_pred]
    plt.scatter(x_pred[:, 0], x_pred[:, 1], c=c, s=50, alpha=0.5)
    # misclassified data
    d = y_pred - y_true
    misclass_idx = np.where(d != 0)[0]
    c = ['red' if lb == 2 else 'blue' for lb in d[misclass_idx]]
    plt.scatter(x_pred[misclass_idx, 0],
                x_pred[misclass_idx, 1], c=c, s=50, alpha=0.8)
    accuracy = 100 * (1 - len(misclass_idx) / float(x_pred.shape[0]))
    plt.title("Classification accuracy on test set: %.2f%%" % accuracy)
    plt.legend(handles=[plt.scatter([], [], c='powderblue', s=50, alpha=0.5),
                        plt.scatter([], [], c='indianred', s=50, alpha=0.5),
                        plt.scatter([], [], c='red', s=50, alpha=0.8),
                        plt.scatter([], [], c='blue', s=50, alpha=0.8)],
               labels=['Class A', 'Class B', 'Misclassified Class B', 'Misclassified Class A'])
    plt.show()

    fig = go.Figure()

    # plot the decision function
    xm = np.linspace(np.min(x_pred[:, 0]), np.max(x_pred[:, 0]), 20)
    ym = np.linspace(np.min(x_pred[:, 1]), np.max(x_pred[:, 1]), 20)
    xx, yy = np.meshgrid(xm, ym)

    inpoints = np.c_[xx.ravel(), yy.ravel()]
    if preprocessing:
        inpoints = preprocessing(inpoints)

    Z = clf.decision_function(inpoints)
    # Computes the decision function that separates the 1 labels
    # from the -1 labels
    # ravel() returns a contiguous flattened array
    # c_ concatenates arrays along the 2nd dimension
    Z = Z.reshape(xx.shape)

    fig.add_trace(go.Scatter(x=x_pred[:, 0], y=x_pred[:, 1],
                             mode='markers', showlegend=False,
                             marker=dict(color=y_pred, colorscale="RdBu", size=10)))
    fig.add_trace(go.Contour(x=xm, y=ym, z=Z, colorscale='RdBu'))
    fig.update_layout(title="Decision Function", width=600,
                      yaxis=dict(scaleanchor="x", scaleratio=1))
    fig.show()
