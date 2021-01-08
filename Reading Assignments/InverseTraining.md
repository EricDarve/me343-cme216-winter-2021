---
layout: page
title: Training for Inverse Problems
--- 

Write your answers in a PDF and upload the document on [gradescope](https://www.gradescope.com/courses/102338) for submission. Each question is worth 10 points. Post on [Slack](https://stanford.enterprise.slack.com/) for questions.

[Videos](https://canvas.stanford.edu/courses/118944/external_tools/3367)
[Slides](https://ericdarve.github.io/cme216-spring-2020/Slides/AD/Inverse.pdf)

Late day policy: 1 late day with a 20% grade penalty.

The next questions refer to video "5.4 Training Methods: Basic Idea."

Assume we have the following recurrence relation:

$$ a(\theta) u_{k+1} = u_k + f_{k+1}, \quad u_0 = 0, \quad a(\theta) > 0 \tag{1}$$

where all quantities are scalars; $f_k$ is a given sequence.

We want to calculate

$$ \frac{\partial u_n}{\partial \theta} $$

using reverse-mode AD, with $k$ going from $n-1$ to 0. This is the process ADCME and TensorFlow follow.

1. Show that at each step in reverse-mode, we need to keep track of these two derivatives:

$$ \frac{\partial u_n}{\partial u_k}, \quad
\frac{\partial u_n}{\partial \theta}
$$

Make sure you correctly identify the independent variables at each step of the reverse-mode AD process.

Hint: it is common in AD to use simplified notations like $u_n$ above. However, to explain this more rigorously, we need to make the notations more precise. This will help clarify the questions in this RA. At every step, we need to identify the independent variables. If you look at the computational graph, you will see that at each step, the independent variables are $\theta$ and $u_k$. To denote this, the correct notation is $u_{n,k}(\theta,u_k)$. The function $u_{n,k}(\theta,u_k)$ is defined by traversing the graph starting from $\theta$ and $u_k$ (the independent variables) until you reach the node $u_n$, and $u_{n,k}(\theta,u_k) = u_n$.

{:start="2"}
1. Show that the following formulas provide the recurrence to compute all the derivatives in reverse-mode

$$ \frac{\partial u_n}{\partial u_k}  =
\frac{\partial u_n}{\partial u_{k+1}} \frac{\partial u_{k+1}}{\partial u_k} $$

$$\frac{\partial u_n}{\partial \theta} \leftarrow
\frac{\partial u_n}{\partial \theta} + \frac{\partial u_n}{\partial u_{k+1}} \frac{\partial u_{k+1}}{\partial \theta}
$$

Hint: this step may be confusing because of the simplified notations for $u_n$. Using our full notations $u_{n,k}$ you can write:

$$ u_{n,k}(\theta,u_k) = u_{n,k+1}(\theta,u_{k+1}(\theta,u_k)) $$

The function $u_{k+1}(\theta,u_k)$ is defined using Equation (1). Then you can use the chain rule in the usual way:

$$ \frac{\partial u_{n,k}}{\partial \theta} = 
\frac{\partial u_{n,k+1}}{\partial \theta} \frac{\partial \theta}{\partial \theta} + 
\frac{\partial u_{n,k+1}}{\partial u_{k+1}} \frac{\partial u_{k+1}}{\partial \theta} $$

{:start="3"}
1. Use the form of the recurrence relation for $u_{k+1}$ (Equation (1)) to show that

$$ \frac{\partial u_n}{\partial u_k} = \frac{1}{a(\theta)} \frac{\partial u_n}{\partial u_{k+1}} $$

$$\frac{\partial u_n}{\partial \theta} \leftarrow
\frac{\partial u_n}{\partial \theta} - \frac{a'(\theta) u_{k+1}}{a(\theta)} \frac{\partial u_n}{\partial u_{k+1}}
$$

Make sure you identify the independent variables correctly.

Hint: if on the numerator you get the term $u_k + f_{k+1}$, use the definition of $u_{k+1}$ to simplify.

To start this recurrence, we use

$$ \frac{\partial u_n}{\partial \theta} = 0, \quad
\frac{\partial u_n}{\partial u_n} = 1 $$

Then have $k$ go from $n-1$ down to 0.

The next questions refer to video "5.5 Training Methods: Direct Method, Residual Minimization, and Penalty Method."

{:start="4"}
1. In the direct training method, are we using the PDE from slide [23](https://ericdarve.github.io/cme216-spring-2020/Slides/AD/Inverse.pdf#page=23)?
1. In the penalty method, list the quantities that are known before the calculation starts, and the variables that are being computed by the algorithm. In the penalty method, is the PDE satisfied exactly?
1. What penalty parameters are associated with (a) the boundary condition on the left size of the domain ($x=0$), (b) the right-side of the domain ($x=1$), and (c) the initial condition at $t=0$?