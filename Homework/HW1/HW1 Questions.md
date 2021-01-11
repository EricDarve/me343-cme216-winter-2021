---
layout: page
title: Homework 1 - SVM
---

If you need help setting up python on your local machine, please follow the [python setup guide](../../Python Setup Guide) posted separately. We recommend that you set up a virtual environment for this class. The python dependencies required for this homework are listed in **requirements.txt**. If you are using Anaconda, you can install them by running `conda install --file=requirements.txt`.

You will find the starter code for this homework in the folder [hw1-starter-code](https://github.com/EricDarve/me343-cme216-winter-2021/tree/main/Homework/HW1/hw1-starter-code).

In this homework, we will practice SVM using scikit-learn and build some intuition. The file you will modify is **svm.ipynb**, you can launch the notebook by running `jupyter notebook svm.ipynb`. The parts you need to implement are marked with TODO. You will submit the implemented **svm.ipynb** file and a pdf file with answers to non-coding questions to gradescope.

1. Fill in the **linear_SVM** function by creating and training a linear SVM. `data` is a dictionary with strings as keys, the next cell shows how it's populated.

2. Try your implementation on a linearly separable dataset. Run the corresponding cell to visualize the result, include the plots in your writeup.

3. Now try the linear SVM on some non-linearly separable datasets (circle and inner_circle). Run the corresponding cells to visualize. How does the SVM do? Include a brief explanation for the performance you see.

4. One way to use linear SVM for the datasets we saw above is to compute linearly separable feature(s) from the raw input coordinates, and input those features in the SVM instead. Notice the circle and inner_circle datasets are quite structured mathematically; using your geometric intuition, come up with simple features for the circle and inner_circle dataset. Fill in **circle_feature_linear_SVM** and **inner_circle_feature_linear_SVM** functions using your features.

5. Visualize your results by running the corresponding cells. You should get perfect or close to perfect accuracies. Include the plots in your writeup.

6. In your own words, explain how non-linear decision boundaries are achieved using linear SVMs.

7. While hand-crafting features is possible, it is not very generalizable and is difficult when the dimensionality of input is high. A better approach is to use kernels in SVM. We will classify the above datasets using SVM with RBF kernel. Fill in **rbf_SVM** function.

8. Visualize your results by running the corresponding cells, include plots in your writeup.

9. Now let's try a noisy dataset (moons); the random seed is fixed and you will get the same dataset every time. We will use this dataset to tune C and gamma for our SVM (RBF kernel) by performing cross validation on x_train and y_train. We will first tune C, holding gamma constant at the default value. Fill in the **cross_validation_tune_C** function to find an optimal C value. Sweep through large range of values for C to observe the trend (e.g., 1e-4, 1e-3, ..., 1e4). Use mean accuracy as your evaluation criteria. This [tutorial](https://scikit-learn.org/stable/modules/cross_validation.html) will be helpful.

10. Execute the corresponding cell to run your implementation. What is the optimal C you found? How did the mean accuracy vary as you vary C? Briefly explain the trend you saw by relating it to the effect of C.

11. Now let's tune gamma, holding C constant at the optimal value you found. Fill in the **cross_validation_tune_gamma** function.

12. What is the optimal gamma value you found? It's OK if you got slightly worse accuracy than above, the default gamma value is quite good. Describe and explain how the mean accuracy changed as you vary gamma.

We asked you to tune C and gamma sequentially to show the effect of each hyperparameter. In practice, it makes more sense to tune them together. Take a look at this [example](https://scikit-learn.org/stable/auto_examples/svm/plot_rbf_parameters.html#sphx-glr-auto-examples-svm-plot-rbf-parameters-py) to see how it can be done. You don't need to implement anything.
