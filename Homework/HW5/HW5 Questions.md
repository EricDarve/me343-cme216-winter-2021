---
layout: page
title: Programming Homework 5
---

**Submission instructions**: Please use your Python notebook for your programming and written answers. Please do so by including “text cells” or “markdown cells” in your Python notebook. To submit, save the notebook as PDF and submit this PDF as your answer. We will also accept other formats for your submission if this does not work for you.

[PIML.ipynb starter code](https://github.com/EricDarve/me343-cme216-winter-2021/blob/main/Homework/HW5/hw5-starter-code/PIML.ipynb)

In this homework, you will implement and train a neural network to solve an ordinary differential equation (ODE) using Physics-Informed Learning. The ODE we will investigate is as follows:

$$ \frac{d}{dx} ( k(x) \frac{du}{dx} ) + a(x) \frac{du}{dx} + u(x) = f(x) $$

where $u(x) = \cos(-x^2)$, $k(x) = 1 + x^2$, $a(x) = x$ and 

$$ f = (-8x^2 - 2)\sin(x^2) + (-4x^4 - 4x^2 + 1)\cos(x^2) $$

Launch `PIML.ipynb` to get started. Same as in HW3, in this homework, to accelerate the training, we will use the optimizer [L-BFGS-B](https://docs.scipy.org/doc/scipy/reference/optimize.minimize-lbfgsb.html) from [SciPy](https://www.scipy.org/) to update the neural network.

The code for data generation has been provided to you. Make sure you understand the function `generate_data`. 

Your task is to complete the class methods in the class `PI_NN`.

{:start="1"}
1. Complete the `__init__` method in `PI_NN`. You will initialize some TensorFlow Keras layers for the forward pass and define the [Mean Squared Error](https://www.tensorflow.org/api_docs/python/tf/keras/losses/MeanSquaredError) loss function. Check the following [code example](https://github.com/EricDarve/me343-cme216-winter-2021/blob/main/Code/PIML_advanced.ipynb) for reference, e.g., the `__init__` method in the class `PI_Model_1D` used to solve the second order ODE $u'' = -\cos(x)$. Note that in the forward pass, you will compute $u$, $k$ and $a$. Therefore the size of the final layer is 3. Turn in your implementation.

{:start="2"}
2. Complete the `call` method in `PI_NN`. Use the layers defined in `__init__` for the forward pass. In the end, split the output from the final layer to $u(x)$, $k(x)$ and $a(x)$. An example code is provided in the notebook. Turn in your implementation.

{:start="3"}
3. Complete the `get_derivatives` method in `PI_NN`. Given the `x_input`, you need to compute `u(x_input)`, `k(x_input)`, `a(x_input)` (hint: use the `call` function you just implemented), $\frac{du}{dx}$ and the right-hand-side (RHS) of the ODE, i.e. 

$$\frac{d}{dx} ( k(x) \frac{du}{dx} ) + a(x) \frac{du}{dx} + u(x)$$

For reference, check the `get_derivatives` method of the class `PI_Model_1D` in [PIML_advanced.ipynb](https://github.com/EricDarve/me343-cme216-winter-2021/blob/main/Code/PIML_advanced.ipynb). Turn in your implementation.

{:start="4"}
4. Complete the `loss` method in `PI_NN`. The training loss is a weighted sum of losses in $u(x)$, $k(x)$ and $a(x)$ and the ODE (the difference between the RHS and LHS of the ODE): 

`loss = alpha_u*loss_u + alpha_k*loss_k + alpha_a*loss_a + alpha_ode*loss_ode`

An example code of how to compute `loss_u` is provided in the starter code. You may need to explore several weighting schemes to achieve good performance.

Now it is time a train the Physics-Informed Neural Network (PINN) to solve the ODE!

{:start="5"}
5. The first scenario (mode 1) we will explore is that we have a lot of data (observations) for $k$, $a$, $f$. However, we have limited observations for $u$. We want to learn $u$. We are basically solving the ODE. Train your model with the data provided to you. After training, plot the solutions and errors (plotting codes have been provided to you). Turn in the code for training and the plots for the solutions and errors.

{:start="6"}
6. The second scenario (mode 2) is that we have a lot of observations for $u$ and the RHS of the ODE. We have very limited observation for $k(x)$ and $a(x)$. The goal is to learn $k$ and $a$. This is an inverse modeling problem. For example, we are modeling the properties of the "material" or the physical model from measurements and observations. Train your model with the data provided to you. After training, plot the solutions and errors. Turn in the code for training and the plots for the solutions and errors.

{:start="7"}
7. The third scenario (mode 3) is that we have partial observations for all variables. Train your model with the data provided to you. After training, plot the solutions and errors. Turn in the code for training and the plots for the solutions and errors.