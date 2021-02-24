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

The next question refers to video "5.3 Forward Mode."

In automatic differentiation (AD), at every step, we keep track of the result of the calculation up to that point, along with derivatives with respect to all the input variables.

For example, let's consider the graph $G$ that takes as input two independent variables $(x_1,x_2)$. The first node is $y_1 = x_1^2$, the second node is $y_2 = 2 x_2$, and the third node $y_3 = y_1 + y_2$.

In AD, we keep track of the numerical value of the node, along with the derivatives with respect to all the independent variables. This can be represented as a tuple of 3 values for each node. Assume that $x_1 = 1$ and $x_2 = -2$. For graph $G$:

- Node $y_1(x_1)$: $(y_1,\partial y_1 / \partial x_1, \partial y_1 / \partial x_2) = (1, 2, 0)$.
- Node $y_2(x_2)$: $(y_2,\partial y_2 / \partial x_1, \partial y_2 / \partial x_2) = (-4, 0, 2)$.
- Node $y_3(y_1,y_2)$: $(y_3,\partial y_3 / \partial x_1, \partial y_3 / \partial x_2) = (-3, 2, 2)$.

For example, the derivative $\partial y_3 / \partial x_1$ is evaluated using:

$$ \frac{\partial y_3}{\partial x_1} = \frac{\partial y_3}{\partial y_1} \frac{\partial y_1}{\partial x_1} + \frac{\partial y_3}{\partial y_2} \frac{\partial y_2}{\partial x_1} = 1 \times 2 + 1 \times 0 = 2 $$

Consider the following function:

$$ y(x_1,x_2,x_3) = x_3^2 \log ( x_1 + 2 x_2 ) $$

The computational graph $G_1$ to compute $y$ has 5 nodes, where $y = y_5$. Each node is one arithmetic operation or the calculation of log. Assume that $x_1 = e - 2$, $x_2 = 1$, $x_3 = 2$.

{:start="9"}
1. [5.3]. Using graph $G_1$, show the steps in forward-mode AD to compute the tuple for output node $y = y_5$:

$$ \Big( y, \frac{\partial y}{\partial x_1}, \frac{\partial y}{\partial x_2}, \frac{\partial y}{\partial x_3} \Big) $$

The next question refers to video "5.4 Reverse Mode."

Reverse-mode AD performs similar calculations but starting from the end and moving towards the input of the graph. Take for example graph $G$. The steps are:

- Step 1; node $y_3(y_1,y_2)$: $(y_3,\partial y_3 / \partial y_1, \partial y_3 / \partial y_2) = (-3, 1, 1)$.
- Step 2; node $y_2(x_2)$: $(y_2,\partial y_3 / \partial y_1, \partial y_3 / \partial x_2) = (-4, 1, 2)$.
- Step 3; node $y_1(x_1)$: $(y_1,\partial y_3 / \partial x_1, \partial y_3 / \partial x_2) = (1, 2, 2)$.

Reverse-mode requires that we have first traversed the graph in the forward direction to compute the derivatives of all the node values with respect to their inputs. This is called the forward pass. The derivatives of the output with respect to all the inputs are then computed using the backpropagation formula. For example, at Step 3 above, we used:

$$ \frac{\partial y_3}{\partial x_1} = \frac{\partial y_3}{\partial y_1} \frac{\partial y_1}{\partial x_1} = 1 \times 2 = 2 $$

$\partial y_3 / \partial y_1$ is from Step 2; $\partial y_1 / \partial x_1$ (node derivative) was computed during the forward pass.

The general rule is as follows. Assume we are at step $s$. At step $s+1$, we add node $y_j(y_{i_1},\dots, y_{i_k})$. For step $s+1$, we keep all the derivatives from step $s$ except $\partial y / \partial y_j$. This derivative is removed and replaced by all the derivatives $\partial y / \partial y_{i_l}$, $1 \le l \le k$, which are computed using

$$ \frac{\partial y}{\partial y_{i_l}} = \frac{\partial y}{\partial y_j} \frac{\partial y_j}{\partial y_{i_l}} $$

If the derivative $\partial y / \partial y_{i_l}$ was already present at step $s$, we add the new contribution

$$ \frac{\partial y}{\partial y_{i_l}} \leftarrow \frac{\partial y}{\partial y_{i_l}} + \frac{\partial y}{\partial y_j} \frac{\partial y_j}{\partial y_{i_l}} $$

Go back to the example above to make sure you understand how the process works.

If you return to the slides for the backpropagation algorithm for DNN, you will see that we followed exactly these steps, but specialized for sequential DNNs. There was a forward pass, followed by the backpropagation.

{:start="10"}
1. [5.4]. Return to the example with graph $G_1$. Redo the differentiation using reverse-mode. You should start from $y_5=y$, then go to $y_4$, &hellip;, $y_1$. For each $y_k$, list all the derivatives that are needed at that step, and their value. At the end of this process you should find the expression for $\partial y / \partial x_i$, $i=1,2,3.$ It should match your answer using forward mode. The intermediate steps however will be different from the forward-mode.

The next question refers to video "5.5 AD for Physical Simulations."

The discretization of the PDE is based on the idea of approximating a derivative using

$$ \frac{\partial u}{\partial x} \approx \frac{u(x+h) - u(x-h)}{2h} $$

If we use a uniform grid with spacing $\Delta x$, we get

$$ \frac{\partial u}{\partial x} \Big\lvert_i \approx \frac{u_{i+1} - u_{i-1}}{2 \Delta x} $$

To evaluate a second-order derivative like 

$$\triangle u = \frac{\partial^2 u}{\partial x^2}$$

we can use

$$ \triangle u(x_i) \approx \frac{u'(x + \Delta x / 2) - u'(x - \Delta x / 2)}{\Delta x} $$

where $u'$ is the derivative.

{:start="11"}
1. [5.5]. Use the approximation of the derivative and the previous equation to show that:

$$ \triangle u(x_i) \approx \frac{u_{i+1} - 2 u_i + u_{i-1}}{\Delta x^2} $$

{:start="12"}
1. [5.5]. Using the equation on Slide [36](https://ericdarve.github.io/me343-cme216-winter-2021/Slides/AD/5_AD.pdf#page=40), show that row $i$ of $A(a,b)$ (slide [37](https://ericdarve.github.io/me343-cme216-winter-2021/Slides/AD/5_AD.pdf#page=41)) is of the form (where $i$ is different from 1 and $n$):

$$ [ \cdots \; 0, \; -\lambda_i, \; 2 \lambda_i + 1, \; - \lambda_i, \; 0, \; \cdots] $$

with $\lambda_i = \kappa_i \frac{\Delta t}{\Delta x^2}$.

Consider the boundary condition on the right:

$$ u_{n+1} = 0 $$

{:start="13"}
1. [5.5]. Using this boundary condition, show that the last row of matrix $A(a,b)$ is 

$$ [ \cdots \; 0, \; -\lambda_n, \; 2 \lambda_n + 1] $$

Assume now that $\partial u / \partial x = 0$ at node $i = 1$ on the left. For this specific problem, we can prove that this condition implies that the solution $u(x)$ can be extended and made even about $x=0$. This is done by formulating an equivalent PDE problem on the interval $[-1,1]$ with Dirichlet BC at $x=-1$ and $x=1$. At $x=0$, we recover $\partial u / \partial x = 0$. This solution $u$ formulated over the interval $[-1,1]$ is even and matches the solution $u$ to our problem on $[0,1]$.

With our numbering we have that $x_1 = 0$ and $x_2 = \Delta x$. We introduce the point $x_0 = -\Delta x$. Since $u$ is even (a consequence of the $\partial u / \partial x = 0$ condition as discussed above), we get:

$$ \frac{u_2 - u_0}{2 \Delta x} \approx \frac{\partial u}{\partial x} \Big\rvert_{x=0} = 0, \text{ or } u_0 = u_2$$

{:start="14"}
1. [5.5]. Using this result, show that row 1 of matrix $A(a,b)$ is 

$$ [ 2 \lambda_1 + 1, \; - 2 \lambda_1, \; 0, \; \cdots ] $$

Note the difference with row $n$ and the factor of 2.

The next question covers video "5.6 AD for Implicit Solvers" and "5.7 Conclusion."

Assume that we have computed a solution $(x_0,y_0)$ of this equation:

$$ x^2 + \frac{y^2}{2} + \exp(x) = 3 $$ 

{:start="15"}
1. [5.6]. Calculate $dy/dx$ at $x=x_0$ using implicit differentiation. Give your result in terms of $(x_0,y_0)$.
