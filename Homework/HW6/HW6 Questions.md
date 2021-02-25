---
layout: page
title: Programming Homework 6
---

**Submission instructions**: Please use your Python notebook for your programming and written answers. You can do that by including “text cells” or “markdown cells” in your Python notebook. You can just type in your answers in these cells as text. At the end, you will have one document (the notebook) with all your answers. To submit, save the notebook as PDF and submit this PDF as your answer. We will also accept other formats for your submission if this does not work for you.

[Starter code](./starter_code.zip)

Kailai prepared a complete set of videos for this homework. Please go to the folder [Homework 6](https://stanford-pilot.hosted.panopto.com/Panopto/Pages/Sessions/List.aspx?folderID=c9d36ce3-e747-4a50-a866-acd801729122) on Canvas. You will find 10 videos in that folder.

![](assets/hw_videos.png){:width="50%"}

You should watch these videos before doing the homework. Each video covers different parts of the homework, so you can start working on this homework after watching the first few videos.

For this homework, you will need to install Julia and ADCME. See this [installation guide](./ADCME_setup.md) for detail setup. The first three videos on [Canvas](https://stanford-pilot.hosted.panopto.com/Panopto/Pages/Sessions/List.aspx?folderID=c9d36ce3-e747-4a50-a866-acd801729122) will give you a step-by-step demonstration.

- [ADCME tutorial pages](https://kailaix.github.io/ADCME.jl/dev/tutorial/)
- [ADCME basics](https://kailaix.github.io/ADCME.jl/dev/tu_basic/)
- [ADCME API reference](https://kailaix.github.io/ADCME.jl/dev/api/)

If you are not familiar with Julia, this language is similar to Python and Matlab. It's a scripting language. The syntax is different from Python, but the functionalities are similar to numpy and scipy in Python to some extent. The examples in the videos should be sufficient to do this homework. You don't need to know much more. There are many more features in Julia that are available, but they are not needed for this homework. 

- [Main differences between Julia and Python](https://docs.julialang.org/en/v1/manual/noteworthy-differences/#Noteworthy-differences-from-Python-1)
- [Julia documentation](https://docs.julialang.org)

There are many excellent Julia tutorials. We are providing the links below for _reference_ but you should _not_ have to read this to do the homework.

- [The Julia Express](http://bogumilkaminski.pl/files/julia_express.pdf)
- [Julia language: a concise tutorial](https://syl1.gitbook.io/julia-language-a-concise-tutorial/)
- [Other learning resources](https://julialang.org/learning/)

If you have some difficulties with this homework and you have a question, make sure it is not already covered in one of the videos. If not, please ask your question on [Slack](https://stanford-3kml.slack.com).

# Inverse Modeling with ADCME

## Background

The **thermal diffusivity** is the measure of the ease with which heat can diffuse through a material. Let $u$ be the temperature, and $\kappa$ be the thermal diffusivity. The heat transfer process is described by the Fourier law 

$$\frac{\partial u(\mathbf{x}, t)}{\partial t} = \kappa\Delta u(\mathbf{x}, t) + f(\mathbf{x}, t), \quad t\in (0,T), x\in \Omega \tag{1}$$

Here $f$ is the heat source, and $\Omega$ is the domain.

To make use of the heat equation, we need additional information. 

- **Initial Condition**: the initial temperature distribution is given by $u(\mathbf{x}, 0) = u_0(\mathbf{x})$. 

- **Boundary Conditions**: the temperature of the material is affected by what happens on the boundary. There are several possible boundary conditions. In this exercise, we consider two of them:

  (1) Temperature fixed at a boundary,

  $$u(\mathbf{x}, t) = 0, \quad \mathbf{x}\in \Gamma_D \tag{2}$$

  (2) Insulated boundary. The heat flow can be prescribed (known as the _no flow_ boundary condition)

  $$-\kappa\frac{\partial u(\mathbf{x},t)}{\partial n} = 0, \quad \mathbf{x}\in \Gamma_N \tag{3}$$

  Here $n$ is the outward normal vector. 

  The boundaries $\Gamma_D$ and $\Gamma_N$ satisfy $\partial \Omega = \Gamma_D \cup \Gamma_N, \Gamma_D\cap \Gamma_N = \emptyset$.

Assume that we want to experiment with a piece of new material. The thermal diffusivity coefficient of the material is an unknown function of the space. Our goal of the experiment is to find out the thermal diffusivity coefficient. To this end, we place some sensors in the domain or on the boundary. The measurements are sparse in the sense that only the temperature from those sensors---but nowhere else---are collected. Namely, let the sensors be located at $\\{\mathbf{x}\_i\\}\_{i=1}^M$, then we can observe $\\{\hat u(\mathbf{x}\_i, t)\\}\_{i=1}^M$, i.e., the measurements of $\\{ u(\mathbf{x}\_i, t) \\}\_{i=1}^M$. We also assume that the boundary conditions, initial conditions, and the source terms are known. 

![](./assets/ex_figure.png) 

## Problem 1: Parameter Inverse Problem in 1D

We first consider the 1D case. In this problem, the material is a rod $\Omega=[0,1]$. We consider a homogeneous (zero) fixed boundary condition on the right side and an insulated boundary on the left side. The initial temperature is zero everywhere, i.e., $u(x, 0)=0$, $x\in [0,1]$. The source term is 

$$f(x, t) = \exp(-50(x-0.5)^2)$$

and $\kappa(x)$ is a function of space

$$\kappa(x) = a + bx$$

Our task is to estimate the coefficient $a$ and $b$ in $\kappa(x)$. To this end, we place a sensor at $x=0,$ and the sensor records the temperature as a time series $u_0(t)$, $t\in (0,1)$. 

Recall that in lecture slide [35](https://ericdarve.github.io/me343-cme216-winter-2021/Slides/AD/5_AD.pdf#page=39)/47 of `AD.pdf`, we formulate the inverse modeling problem as a PDE-constrained optimization problem

$$\begin{aligned}
\min_{a, b}\ & \int_{0}^t ( u(0, t)- u_0(t))^2 dt\\
\mathrm{s.t.}\ & \frac{\partial u(x, t)}{\partial t} = \kappa(x)\Delta u(x, t) + f(x, t), \quad t\in (0,T), x\in (0,1) \\
& -\kappa(0)\frac{\partial u(0,t)}{\partial x} = 0, t>0\\
& u(1, t) = 0, t>0\\
& u(x, 0) = 0, x\in [0,1]\\
& \kappa(x) = a x + b
\end{aligned}$$

We consider the discretization of the above forward problem. We divide the domain $[0,1]$ into $n$ equispaced intervals. We consider the time horizon $T = 1$, and divide the time horizon $[0,T]$ into $m$ equispaced intervals. We use a finite difference scheme to solve the 1D heat equation Equations (1)--(3). Specifically, we use an implicit scheme for stability:

$$\frac{u^{k+1}_i-u^k_i}{\Delta t} = \kappa_i \frac{u^{k+1}_{i+1}+u^{k+1}_{i-1}-2u^{k+1}_i}{\Delta x^2} + f_i^{k+1},$$

$$k=1,2,\ldots,m, i=1,2,\ldots, n \tag{4}$$

where $\Delta t$ is the time interval, $\Delta x$ is the space interval, $u_i^k$ is the numerical approximation to $u((i-1)\Delta x, (k-1)\Delta t)$, $\kappa_i$ is the numerical approximation to 

$$\kappa((i-1)\Delta x) = a + b(i-1)\Delta x$$

and $f_i^{k} = f((i-1)\Delta x, (k-1)\Delta t)$.

For the insulated boundary, we introduce the ghost node $u_0^k$ at location $x=-\Delta x$, and the insulated boundary condition can be numerically discretized by 

$$-\kappa_1 \frac{u_2^{k}-u_0^k}{2\Delta x} = 0\tag{5}$$

Let

$$U^k = \begin{bmatrix}u_1^k\\u_2^k\\\vdots \\u_n^k\end{bmatrix}$$

The index starts from 1 and ends with $n$. Using the finite difference scheme, together with eliminating the boundary values $u_0^k$, $u_{n+1}^k$, we have the following formula

$$AU^{k+1} = U^k + F^{k+1}$$

1. Express the matrix $A\in \mathbb{R}^{n\times n}$ in terms of $\Delta t$, $\Delta x$ and $\\{\kappa\_i\\}\_{i=1}^{n}$. What is $F^{k+1}\in \mathbb{R}^n$ ?

Hint: Can you eliminate $u_0^k$ and $u_{n+1}^k$ in Eq. (4) using Eq. (5) and $u_{n+1}^k=0$ ?

The starter code `Case1D/starter1.jl` precomputes the force vector $F^k$ and packs it into a matrix $F\in \mathbb{R}^{(m+1)\times n}$. 

{:start="2"}
1. Use `spdiag`[^spdiag]  to construct `A` as a `SparseTensor` (see the starter code for details). `spdiag` is an ADCME function. See the documentation[^spdiag] for the syntax. Turn in your code.

$\kappa(x)$ is given by

$$\kappa(x) = 2+1.5x$$

[^spdiag]: [API Reference](https://kailaix.github.io/ADCME.jl/dev/api/#ADCME.spdiag-Tuple{Integer,Vararg{Pair,N}%20where%20N})

For debugging, check that your $A_{ij}$ is tridiagonal. You can use `run(sess, A)` to evaluate the `SparseTensor` `A`. You should get the following values:

$A_{11}$ | $201$
$A_{12}$ | $-200$
$A_{21}$ | $-101.5$
$A_{33}$ | $207$
$A_{10,10}$ | $228$

The computational graph of the dynamical system can be efficiently constructed using `while_loop`. 

{:start="3"}
1. Implement the forward computation using `while_loop`. Turn in your code.

For debugging, you can plot the temperature on the left side, i.e., $u(0,t)$. You should have something similar to the following plot 

![ex1_reference](./assets/ex1_reference.png)

Now we are ready to perform inverse modeling. 

{:start="4"}
1. Read the starter code `Case1D/starter2.jl` carefully and complete the missing implementations. Turn in your code. What is your estimate for `a` and `b`?

## Problem 2: Function Inverse Problem

Let us consider the function inverse problem, where we do not know the form of $\kappa(x)$. To this end, we substitute $\kappa(x)$ using a neural network. We will use physics constrained learning (PCL) to train $\kappa(x)$ from the temperature data $u_0(x, t)$, where $x$ is the location of a sensor.

Since we do not know the form of $\kappa(x)$, we need more data to solve the inverse problem. Therefore, we assume that we place sensors at the first 25 locations in the discretized grid. The observation data `data_pcl.txt` is a $(m+1)\times 25$ matrix; each column corresponds to the observation at one sensor. 

In this problem, let us parametrize $\kappa(x)$ with a fully connected neural network with 3 hidden layers, 20 neurons per layer, and $\tanh$ activation functions. In ADCME, such a neural network can be constructed using 

```julia
y = fc(x, [20,20,20,1])
```

Here x is a $n \times 1$ input, y is a $n \times 1$ output, $[20,20,20,1]$ is the number of neurons per layer (last output layer only has 1 neuron), and fc stands for "fully-connected". 

Assume that the neural network is written as $\kappa_\theta(x)$, where $\theta$ is the weights and biases.

{:start="5"} 
1. Write down the mathematical optimization problem for the inverse modeling. What variables are we optimizing for this problem?
1. Complete the starter code `Case1D/starter3.jl` for conducting physics constrained learning. The observation data is provided as `data_pcl.txt`. Run the program several times to ensure you do not terminate early at a bad local minimum. Turn in your code.
1. Plot your estimated $\kappa_\theta$ curve. 

Hint: Your curve should look like the following

![](./assets/kappa.png)

{:start="8"} 
1. Add 1% and 10% Gaussian noise to the dataset and redo (7). Plot the estimated $\kappa_\theta$ curve. Comment on your observations.

Hint: You can add noise using

```julia
uc =  uc .* (1 .+ 0.01*randn(size(uc)...))
uc =  uc .* (1 .+ 0.1*randn(size(uc)...))
```

Here `.` is for elementwise operations. 

## Problem 3: Parameter Inverse Problem in 2D

In this problem, we will explore more deeply how ADCME works with numerical solvers. We will use an important technique, custom operators, for incorporating C++ codes. This will be useful when you want to accelerate a performance-critical part, or you want to reuse existing codes. To make the problem simple, the `C++` kernel has been prepared for you. For this homework, you will be working with `Case2D/starter.jl`. 

We consider the 2D case and $T=1 $. We assume that $\Omega=[0,1]^2$. We impose zero boundary conditions on the entire boundary $\Gamma_D=\partial\Omega$. Additionally, we assume that the initial condition is zero everywhere. Two sensors are located at $(0.2,0.2)$ and $(0.8,0.8)$ and these sensors record time series of the temperature $u_1(t)$ and $u_2(t)$. The thermal diffusivity coefficient is a linear function of the space coordinates

$$\kappa(x, y) = a + bx + cy$$

where $a, b$ and $c$ are three coefficients we want to find out from the data $u_1(t)$ and $u_2(t)$. 

{:start="9"}
1. Write down the mathematical optimization problem for the inverse modeling. As before, explain what variables we are optimizing for this problem.

We use the finite difference method to discretize the PDE. Consider $\Omega=[0,1]\times [0,1]$, we use a uniform grid and divide the domain into $m\times n$ squares, with length $\Delta  x$. We also divide $[0,T]$ into $N_T$ intervals of equal length. The implicit scheme for the equation is 

$$\frac{u_{ij}^{k+1}-u_{ij}^k}{\Delta t} = \kappa_{ij}\frac{u_{i+1,j}^{k+1}+u_{i,j+1}^{k+1}+u_{i-1,j}^{k+1}+u_{i,j-1}^{k+1}-4u_{ij}^{k+1}}{\Delta x^2} + f_{ij}^{k+1}$$

where $i=2,3,\ldots, m, j=2,3,\ldots, n, k=1,2,\ldots, N_T$.

Here $u_{ij}^k$ is an approximation to 

$$u((i-1)h, (j-1)h, (k-1)\Delta t)$$

and $f_{ij}^k = f((i-1)h, (j-1)h, (k-1)\Delta t)$.

We flatten $\\{u_{ij}^k\\}$ to a 1D vector $U^k$, using $i$ as the leading dimension, i.e., the ordering of the vector is $u_{11}^k, u_{12}^k, $&hellip; We also flatten $f_{ij}^{k+1}$ and $\kappa_{ij}$ as well. 

In this problem, we extend the AD framework using custom operators (also known as _external function support_ in the AD community). In the starter code `Case2D/starter.jl`, we provide a function, `heat_equation`, a differentiable heat equation solver, which is already implemented for you using C++. By using custom operators, we replace the PDE solver node in the computational graph with our own, more efficient, implementation. 

Read the [instructions](./ADCME_setup.md) on how to compile the custom operator, and answer the following two questions. 

{:start="10"}
1. Similar to Problem 1, implement the forward computation using `while_loop` with the starter code `Case2D/starter.jl`. Plot the curve of the temperature at $(0.5,0.5)$. 

Hint: you should obtain something similar to

![ex2_reference](./assets/ex2_reference.png)

The parameters used in this problem are: $m=50$, $n=50$, $T=1$, $N_T=50$, 

$$f(\mathbf{x},t) = e^{-t}\exp(-50((x-0.5)^2+(y-0.5)^2))$$

$a = 1.5$, $b=1.0$, $c=2.0$. 

The data file `data.txt` is a $(N_T+1)\times 2$ matrix, where the first and the second columns are $u_1(t)$ and $u_2(t)$ respectively. 

{:start="11"}
1. Use these data to do inverse modeling and report the values $a, b$, and $c$. We do not provide a starter code intentionally, but the forward computation codes in `Case2D/starter.jl` and neural-network-based inverse modeling codes in `Case1D/starter3.jl` will be helpful. 

Hint: 

- For checking your program, you can save your own `data.txt` from Question 10. Try to estimate $a$, $b$, and $c$, and check if you can recover the true values. 
- If the optimization stops too early, you can multiply your loss function by a large number (e.g., $10^{10}$) and run your `BFGS!` optimizer again. An alternative approach is to use a smaller tolerance. See the `BFGS!` function documentation for details. 