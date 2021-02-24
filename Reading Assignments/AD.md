---
layout: page
title: Reading Assignment 8
---

## Automatic Differentiation with ADCME

Write your answers in a PDF and upload the document on [Gradescope](https://www.gradescope.com/courses/222525) for submission. The due date is given on [Gradescope](https://www.gradescope.com/courses/222525).

Each question is worth 10 points. Please watch the videos and slides before answering these questions.

The next questions refer to video "5.1 Automatic Differentiation Overview."

Real numbers on a computer are represented using only a finite number of digits. The format that is used is called the floating-point representation. Because of this, when representing numbers like $\pi$, the result of an operation (addition, subtraction) or even simply $1/3$, there is always a small error that is proportional to the unit roundoff $u$. Denote fl the floating-point representation of a real number or the result of an operation. Then, for example:

$$ \text{fl}(\pi) \approx \pi + u \pi $$

Similarly: 

$$ \text{fl}(a+b) \approx a+b + u (a+b) $$

$$ \text{fl}(a*b) \approx a*b + u (a*b) $$

$$ \text{fl}(\sin(x)) \approx \sin(x) + u \sin(x) $$

and so on for all operations.

In single precision, $u \approx 10^{-8}$ and in double precision $u \approx 10^{-16}$.

See [What Every Computer Scientist Should Know About Floating-Point Arithmetic](https://docs.oracle.com/cd/E19957-01/806-3568/ncg_goldberg.html) for more details on this.

Assume we use a central difference scheme to approximate a derivative:

$$ f'(x) \approx \frac{f(x+h) - f(x-h)}{2h} $$

Take for example $x=\pi/4$ and $f = \sin$. Assume $u = 10^{-8}$.

As a reference, we chose $h=10^{-5}$ and computed the following in Python:

```
h = 1e-05
sin(x+h) 0.70711386
sin(x-h) 0.70709974
sin(x+h)-sin(x-h) 1.4126301e-05
(sin(x+h)-sin(x-h))/(2h) 0.70631504
```

This can be compared with a calculation in extended precision where $u \approx 10^{-20}$:

```
sin(x+h) 0.70711385221900393297
sin(x-h) 0.70709971008338043772
sin(x+h)-sin(x-h) 0.000014142135623495248128
(sin(x+h)-sin(x-h))/(2h) 0.70710678117476240638
```

You can try this on your computer. Use the type `numpy.float32` from numpy for your variables, which corresponds to single precision floating-point numbers with $u \approx 10^{-8}$.

{:start="1"}
1. [5.1]. Discuss the accuracy of 

```(sin(x+h)-sin(x-h))/(2h)```

to estimate $\sin'(x) = \cos(x)$, as a function of $h$. How does the accuracy change when $h$ is reduced from $10^{-5}$ to $10^{-7}$? What happens if $h = 10^{-9}$? 

{:start="2"}
1. [5.1]. Calculate the symbolic derivative of 

$$ \tanh(x^2 + 1) $$

with respect to $x$.

In automatic differentiation, we use numerical values, and we carry both the value of the variables and their derivatives as we process each operation.

Assume that $x = 1$ and $x' = 8$. This setup is the usual one in automatic differentiation. We don't need to specify the independent variable. From the numerical values of $x$ and its derivative $x'$, you can compute all the subsequent derivatives using automatic differentiation.

{:start="3"}
1. [5.1]. Calculate the value of $\tanh(x^2 + 1)$ and its derivative.

The next questions refer to video "5.2 Computational Graph."

Consider the following function:

$$ f(x) = \cos(x^2) + x + 1 $$

{:start="4"}
1. [5.2]. Draw the computational graph used to compute this function. Each node in your graph should be an arithmetic operation, or the computation of $\cos$. The graph should have one input $x$ and one output $y$.

Consider the figure in slide [17](https://ericdarve.github.io/me343-cme216-winter-2021/Slides/AD/5_AD.pdf#page=17)/47. Denote the input $x$ on the left and the output $y$ on the right. We will denote $z_i$ the output of node $i$. The nodes are numbered from 1 to $n$, going from left to right. Each node corresponds to some arithmetic operation. This graph is a linear graph. We will use it to illustrate a few concepts.

Using the chain rule, we have:

$$ \frac{\partial z_{i+1}}{\partial x} = \frac{\partial z_{i+1}}{\partial z_i} \frac{\partial z_i}{\partial x} $$

{:start="5"}
1. [5.2]. Use this equation and propose an algorithm to calculate 

$$ \frac{\partial y}{\partial x} $$ 

by traversing the graph from the **left to the right.** You should use a recurrence with $i$ going from 1 to $n$. This corresponds to *forward-mode* automatic differentiation (AD).

Using the chain rule again, we also have that

$$ \frac{\partial y}{\partial z_i} = \frac{\partial y}{\partial z_{i+1}} \frac{\partial z_{i+1}}{\partial z_i} $$

{:start="6"}
1. [5.2]. Use this equation and propose an algorithm to calculate to calculate $\frac{\partial y}{\partial x}$ by traversing the graph from the **right to the left.** You should use a recurrence with $i$ going from $n$ down to 1. This corresponds to *reverse-mode* AD.

Consider the figure in slide [18](https://ericdarve.github.io/me343-cme216-winter-2021/Slides/AD/5_AD.pdf#page=18)/47. Assume that each node in the graph requires 1 microsecond of computing time to both evaluate the function and its derivative. We denote each output as $o_i$, $i = 1, \dots, 5$ in the one-to-many case.

{:start="7"}
1. [5.2]. In the _one-to-many_ case, what is the computational cost of computing $\frac{\partial o_i}{\partial x_1}$ using _forward-mode_ AD, for all $i = 1, \dots, 5$?
1. [5.2]. In the one-to-many case, what is the computational cost of computing $\frac{\partial o_i}{\partial x_1}$ using _reverse-mode_ AD, for all $i = 1, \dots, 5$?