---
layout: page
title: Reading Assignment 9
---

## Inverse Modeling using ADCME

Write your answers in a PDF and upload the document on [Gradescope](https://www.gradescope.com/courses/222525) for submission. The due date is given on [Gradescope](https://www.gradescope.com/courses/222525).

Each question is worth 10 points. Please watch the videos and slides before answering these questions.

The next questions refer to video "6.1 Inverse Problem Overview."

Assume that the unknown function $\kappa(x)$ is written in polynomial form:

$$ \kappa(x) = a_0 + a_1 x + \cdots + a_k x^k $$

1. [6.1]. Is this a parameter inverse problem, a function inverse problem, or stochastic inverse problem?

Assume now that $\kappa(x,u)$ is a function of the independent variable $x$ and the solution $u(x)$ of the PDE.

{:start="2"}
1. [6.1]. What type of inverse problem is it?

The next questions refer to video "6.2 Neural Networks as Function Approximators: Part I" and "6.3 Part II."

{:start="3"}
1. [6.2-3]. Can a DNN be written as a linear combination of basis functions $\phi_i(x)$?

We consider the unit cube in dimension $\mathbb R^d$. The unit cube is the set of all points $x=(x_1,\dots,x_d)$, such that $0 \le x_i \le 1$, $1 \le i \le d$. Assume that we discretize the unit cube using a Cartesian grid, made of small cubes, which we call elements; $h$ is the length of the sides of each element.

{:start="4"}
1. [6.2-3]. How many elements are required to cover the unit cube? Give your answer in terms of $h$ and $d.$
1. [6.2-3]. Check slide [20](https://ericdarve.github.io/me343-cme216-winter-2021/Slides/AD/6_Inverse.pdf#page=20)/50. Explain what it means that DNNs are robust to noise compared to RBF.

The next questions refer to video "6.4 Training Methods: Basic Idea."

Assume we have the following recurrence relation:

$$ a(\theta) u_{k+1} = u_k + f_{k+1}, \quad u_0 = 0, \quad a(\theta) > 0 \tag{1} $$

where all quantities are scalars; $f_k$ is a given sequence.

We want to calculate

$$ \frac{\partial u_n}{\partial \theta} $$

using reverse-mode AD, with $k$ going from $n-1$ to 0. This is the process ADCME and TensorFlow follow.

{:start="6"}
1. [6.4]. Show that at each step in reverse-mode, we need to keep track of these two derivatives:

$$ \frac{\partial u_n}{\partial u_k}, \quad
\frac{\partial u_n}{\partial \theta}
$$

Make sure you correctly identify the independent variables at each step of the reverse-mode AD process.

It is common in AD to use simplified notations like $u_n$ above. However, to explain this more rigorously, we need to make the notations more precise. This will help clarify the questions in this RA. At every step, we need to identify the independent variables. If you look at the computational graph, you will see that at each step, the independent variables are $\theta$ and $u_k$. To denote this, the correct notation is $u_{n,k}(\theta,u_k)$. The function $u_{n,k}(\theta,u_k)$ is defined by traversing the graph starting from $\theta$ and $u_k$ (the independent variables) until you reach the node $u_n$, and $u_{n,k}(\theta,u_k) = u_n$.

{:start="7"}
1. [6.4]. Using the $u_{n,k}(\theta,u_k)$ notation, show that the following formulas provide the recurrence to compute all the derivatives in reverse-mode

$$ \frac{\partial u_{n,k}}{\partial u_k}  =
\frac{\partial u_{n,k+1}}{\partial u_{k+1}} \frac{\partial u_{k+1}}{\partial u_k} $$

$$\frac{\partial u_{n,k}}{\partial \theta} =
\frac{\partial u_{n,k+1}}{\partial \theta} + \frac{\partial u_{n,k+1}}{\partial u_{k+1}} \frac{\partial u_{k+1}}{\partial \theta}
$$

Hint: recall that, using our full notations $u_{n,k}$, we have:

$$ u_{n,k}(\theta,u_k) = u_{n,k+1}(\theta,u_{k+1}(\theta,u_k)) $$

To prove the result above, use the chain rule.

<!-- $$ \frac{\partial u_{n,k}}{\partial \theta} = 
\frac{\partial u_{n,k+1}}{\partial \theta} \frac{\partial \theta}{\partial \theta} + 
\frac{\partial u_{n,k+1}}{\partial u_{k+1}} \frac{\partial u_{k+1}}{\partial \theta} $$ -->

{:start="8"}
1. [6.4]. Use the form of the recurrence relation for $u_{k+1}$ (Equation (1)) to show that

$$ \frac{\partial u_{n,k}}{\partial u_k} = \frac{1}{a(\theta)} \frac{\partial u_{n,k+1}}{\partial u_{k+1}} $$

$$\frac{\partial u_{n,k}}{\partial \theta} =
\frac{\partial u_{n,k+1}}{\partial \theta} - \frac{a'(\theta) u_{k+1}}{a(\theta)} \frac{\partial u_{n,k+1}}{\partial u_{k+1}}
$$

Make sure you identify the independent variables correctly.

Hint: if on the numerator you get the term $u_k + f_{k+1}$, use the definition of $u_{k+1}$ to simplify.

To start this recurrence, we use

$$ \frac{\partial u_n}{\partial \theta} = 0, \quad
\frac{\partial u_n}{\partial u_n} = 1 $$

Then have $k$ go from $n-1$ down to 0.

The next questions refer to video "6.5 Training Methods: Direct Method, Residual Minimization, and Penalty Method."

{:start="9"}
1. [6.5]. In the direct training method, are we using the PDE from slide [23](https://ericdarve.github.io/me343-cme216-winter-2021/Slides/AD/6_Inverse.pdf#page=23)?
1. [6.5]. In the penalty method, list the quantities that are known before the calculation starts and the variables that are being computed by the algorithm. In the penalty method, is the PDE satisfied exactly?
1. [6.5]. What penalty parameters are associated with (a) the boundary condition on the left side of the domain ($x=0$), (b) the right side of the domain ($x=1$), and (c) the initial condition at $t=0$?

The next questions refer to video "6.6 Training Methods: Physics Constrained Learning."

Consider the case shown in the slides:

$$ L(\theta) = \lVert u_\theta - u_0 \rVert_2^2, \qquad B(\theta) \, u_\theta = y $$

$u_\theta$ is a vector and $B$ is a matrix.

{:start="12"}
1. [6.6]. Show that

$$ \frac{\partial u_\theta}{\partial \theta} 
= - B(\theta)^{-1} \frac{\partial B}{\partial \theta} u_\theta
$$

{:start="13"}
1. [6.6]. Use the previous result to show that

$$ \frac{\partial L}{\partial \theta} 
= - 2 (u_\theta - u_0)^T B(\theta)^{-1} \frac{\partial B}{\partial \theta} u_\theta
$$

Assume that you have a numerical algorithm, denoted `LinearSolve(A,b,x)`, to solve linear systems of the form $Ax=b$ where $A$ is a matrix.

{:start="14"}
1. [6.6]. Explain how you can use `LinearSolve` to calculate $- 2 (u_\theta - u_0)^T B(\theta)^{-1} \; ?$ What are the arguments of `LinearSolve(___,___,___)` ?

The next questions refer to video "6.7 Training Methods: Summary".

{:start="15"}
1. [6.7]. Which methods apply when observations are sparse?
1. [6.7]. Which methods do not require optimizing over the state variable $u$?

The next questions refer to video "6.8 ADCME Overview".

{:start="17"}
1. [6.8]. Between TensorFlow (TF) eager and TensorFlow graph, which one has the best performance in terms of AD capabilities?
1. [6.8]. Besides ADCME, is there a Julia library that offers AD capabilities? Which one is it?
1. [6.8]. How does the performance of PyTorch compare with TF eager and TF graph?

See slides [44](https://ericdarve.github.io/me343-cme216-winter-2021/Slides/AD/6_Inverse.pdf#page=44) to [47](https://ericdarve.github.io/me343-cme216-winter-2021/Slides/AD/6_Inverse.pdf#page=47) for examples of applications of ADCME. These are not in the videos.

The next question refers to video "6.9 Physics informed learning conclusion".

{:start="20"}
1. [6.9]. What are the four training algorithms we covered in this module? See slide [50](https://ericdarve.github.io/me343-cme216-winter-2021/Slides/AD/6_Inverse.pdf#page=50).