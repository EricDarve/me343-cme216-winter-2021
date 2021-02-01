---
layout: page
title: Reading Assignment 5
---

## Optimization methods

Write your answers in a PDF and upload the document on [Gradescope](https://www.gradescope.com/courses/222525) for submission. The due date is given on [Gradescope](https://www.gradescope.com/courses/222525).

Each question is worth 10 points. Please watch the videos and slides before answering these questions.

The next questions refer to slide deck "3.11 Stochastic Gradient Descent."

1. [3.11]. Explain the difference between a batch and an epoch in SGD.
1. [3.11]. Assume that a batch uses 10% of the training set. How many DNN weight updates will you have per epoch?

The next questions refer to slide deck "3.12 Saddle points."

{:start="3"}
1. [3.12]. Consider a critical point and assume that all the eigenvalues of the Hessian are negative. What type of point is it?
1. [3.12]. Assume now that in dimension $n=32$, we have 20 positive eigenvalues and 12 negative eigenvalues. What type of point is it?
1. [3.12]. Consider $L(x_1,\dots,x_{2n}) = \sum_{i=1}^n x_{2i-1} x_{2i}$. Consider the point 

$$x = (x_1,\dots,x_{2n}) = 0$$

Show that it is a critical point. What are all the eigenvalues of the Hessian at this point? What are all the eigenvectors? Is this point a local minimum, maximum, or saddle point?

{:start="6"}
1. [3.12]. Explain why gradient descent methods tend to slow down near saddle points.

The next questions refer to slide deck "3.13 Momentum."

Assume that

$$ x_{n+1} = \beta x_n + f_n $$

{:start="7"}
1. [3.13]. Show that:

$$ x_n = \beta^n x_0 + \sum_{k=0}^{n-1} \beta^k f_{n-1-k} $$

To prove this, use $y_n$ with 

$$ x_n = \beta^n y_n $$

{:start="8"}
1. [3.13]. Assume that $\lvert \beta \rvert \ll 1$ (very small compared to 1). Show that

$$ x_n \approx f_{n-1} $$

{:start="9"}
1. [3.13]. Assume now that $f_n = f$ is constant. Show that:

$$ x_n = \Big( x_0 - \frac{f}{1-\beta} \Big) \, \beta^n + \frac{f}{1-\beta} $$

The next questions refer to slide deck "3.14 Adagrad."

{:start="10"}
1. [3.14]. With $H_\beta = D_\beta H D_\beta$, give an expression for $[H\_\beta]\_{ij}$ in terms of $\beta$ and $H\_{ij}.$ Assume that $[D\_\beta]\_{ii} = \beta^{i-1}$.
1. [3.14]. Show that in ADAGRAD, $[s^{(k+1)}]_i \ge [s^{(k)}]_i$, that is the sequence is monotonically increasing; $k$ is the batch index.
1. [3.14]. Consider $x_n = A^n x_0$ for some symmetric matrix $A$. Denote $\lambda$ the eigenvalue of $A$ with the largest magnitude. Denote $u$ the corresponding eigenvector with norm 1. Show that 

$$x_n \approx \lambda^n (u^T x_0) u $$

{:start="13"}
1. [3.14]. Consider again $x_n = A^n x_0$ from the previous question, with $\lvert u^T x_0 \rvert = 1.$ Assume that the largest eigenvalue is $\lambda = 0.999$. Estimate the value of $n$ for which $\lVert x_n \rVert = 0.001$. Assume now that $\lambda = 0.9$. Estimate again the value of $n$ for which $\lVert x_n \rVert = 0.001$. Comment on your findings.

The next questions refer to slide deck "3.15 RMSProp and Adam."

RMSProp uses the following update formula for $s_i^{(k)}$ where $k$ is the batch index:

$$ s_i^{(k+1)} = \beta s_i^{(k)} + (1-\beta) \Big( \frac{\partial L_k}{\partial x_i} \Big)^2 $$

Assume that the gradient is constant:

$$ s_i^{(k+1)} = \beta s_i^{(k)} + (1-\beta) \, G_i^2 $$

{:start="14"}
1. [3.15]. Take $0 < \beta < 1$. Calculate the value of $ s_i^{(k)} $ when $k$ is very large.
1. [3.15]. Why is the Adam method applying this scaling to $m_i$:

$$ \hat{m}_i \leftarrow \frac{m_i}{1-\beta_1^k} $$

{:start="16"}
1. [3.15]. Give a heuristic explanation about why the use of momentum for the gradient (i.e., $m$) in Adam may accelerate convergence near saddle points in some cases?
1. [3.15]. Look at slide 25, the right figure. What do you observe for Rmsprop (black line) vs Adagrad (blue line) towards the end? Explain.
1. [3.15]. Look at slide 25, the right figure. Explain the sudden acceleration of Momentum (green line) towards the end.