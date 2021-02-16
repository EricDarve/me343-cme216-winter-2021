---
layout: page
title: Reading Assignment 7
---

## Physics Informed Machine Learning

Write your answers in a PDF and upload the document on [Gradescope](https://www.gradescope.com/courses/222525) for submission. The due date is given on [Gradescope](https://www.gradescope.com/courses/222525).

Each question is worth 10 points. Please watch the videos and slides before answering these questions.

The next question refers to slide deck "4.1 Physics Informed Machine Learning."

Assume we want to solve the following ODE:

$$ y''(t) + t y'(t) + t^2 y(t) = \cos(t)$$

1. [4.1]. Propose a loss function to solve this ODE using Physics-Informed Learning.

The next questions refer to slide deck "4.2 TensorFlow Automatic Differentiation."

{:start="2"}
1. [4.2]. Write a few lines of TensorFlow code to compute the derivative of

$$ x(t) = 1 + t + \cos(t^2) $$

at $t = \pi / 2$ using automatic differentiation. Turn in your code.

[TensorFlow Math module documentation](https://www.tensorflow.org/api_docs/python/tf/math)

Consider the following Python code:

```Python
x = tf.Variable([0., 10.])
with tf.GradientTape() as g:
    y = [(1+x[0])**2 + x[1]**2, -2.*x[1]]
    
print(g.gradient(y, x))
```

{:start="3"}
1. [4.2]. What is the output? Explain the result.

Consider the following Python code:

```Python
x1 = tf.constant(0.)
x2 = tf.constant(3.)
with tf.GradientTape() as g:
    g.watch(x2)
    y = x1 + x2**3
    
print(g.gradient(y, [x1,x2]))
```

{:start="4"}
1. [4.2]. What is the output? Explain the result.

Consider the following Python code:

```Python
x1 = tf.Variable(10.)
x2 = tf.Variable(2.)
with tf.GradientTape() as g:
    y = x1 + x2**2
    z = x1**2 + x2
    
f = tf.math.add(g.gradient(y, [x1,x2]), g.gradient(z, [x1,x2]))
print(f.numpy())
```

{:start="5"}
1. [4.2]. Explain why this code fails to run and returns a `RuntimeError` message.
1. [4.2]. Modify the Python code above so that it runs correctly. Don't forget to include `del g` at the end. Turn in your code.

The next questions refer to slide deck "4.3 Physics Informed ML using TensorFlow."

We want to solve the following ODE:

$$ y'' = \exp(-x^2), \quad y(0) = 1, \quad y'(0) = 0 $$

We give you the following starter code:

```Python
class PI_Model(tf.keras.models.Model):
    def __init__(self):
        super(PI_Model, self).__init__()
        
        # Define all layers
        self.dense_1 = tf.keras.layers.Dense(8, activation=tf.keras.activations.tanh)
        self.dense_2 = tf.keras.layers.Dense(1, activation=tf.keras.activations.linear)
        
        # Loss function to use later on
        self.loss_fun = tf.keras.losses.MeanSquaredError()
            
    # Forward pass for model
    def call(self, inputs):
        x = self.dense_1(inputs)
        y = self.dense_2(x)
        return y             

    def get_derivatives(self, x_input):
        x = tf.constant(x_input)
        # Add Python code here
        # ...
        return y, y_x, y_xx
    
    def loss(self, X, Y):
        # Add Python code here 
        # ...
        return loss
    
# Initialize model    
model = PI_Model()
model.build((1,1))

# y(0)
x_obs = np.array([[0.]])
y_obs = np.array([[1.]])

# y'(0)
x_p_obs = np.array([[0.]])
y_p_obs = np.array([[0.]])

# y''(x) training points
def ypp_data(n):
    x = reshape_2d(np.linspace(0.,1.,n))
    y = np.exp(-x**2)
    return x, y

x_ode, y_ode = ypp_data(32)
x_val, y_val = ypp_data(128)

X_train = [x_obs,x_p_obs,x_ode]
Y_train = [y_obs,y_p_obs,y_ode]

X_val = [x_obs,x_p_obs,x_val]
Y_val = [y_obs,y_p_obs,y_val]

result = model_fit(model, X_train, Y_train,\
                   validation_data=(X_val,Y_val),\
                   epochs=200, iprint=10)

# Plot the solution
x_true = np.linspace(0.,1.,16)
x_test = reshape_2d(np.linspace(0.,1.,128))

y_pred, y_x_pred, y_xx_pred = model.get_derivatives(x_test)

plt.figure()
plt.plot(x_test,y_pred,'r',label='y')
plt.plot(x_test,y_x_pred,'k',label='y_x')
plt.plot(x_test,y_xx_pred,'b',label='y_xx')
plt.plot(x_true,np.exp(-x_true**2),'go',label='true')
plt.title('Exact solution and DNN model')
plt.legend()
```

Use also the code for `reshape_2d`, `model_fit` and the scipy optimizer from the notebook [PIML_advanced.ipynb](https://github.com/EricDarve/me343-cme216-winter-2021/blob/main/Code/PIML_advanced.ipynb). Don't forget to import the required modules.

{:start="7"}
1. [4.3]. Complete the code above to solve the ODE. Turn in your code.

Check that your solution satisfies the following:

- The final validation loss should be around $\approx 10^{-6}$. 
- Your solution should satisfy the initial conditions.
- In your plot, $y''$ should match $\exp(-x^2)$ in the interval $[0,1]$.

{:start="8"}
1. [4.3]. Turn in a plot of the training and validation losses, and the final plot with $y$, $y'$, $y''$, and the exact values for $y''$.