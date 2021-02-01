---
layout: page
title: Reading Assignment 6
---

## Second-order Optimization Methods

Write your answers in a PDF and upload the document on [Gradescope](https://www.gradescope.com/courses/222525) for submission. The due date is given on [Gradescope](https://www.gradescope.com/courses/222525).

Each question is worth 10 points. Please watch the videos and slides before answering these questions.

The next questions refer to slide deck "3.16 Trust region."

1. [3.16]. Prove that

$$ - B^{-1} g = \text{argmin}_p \; \big( g^T p + \frac{1}{2} p^T B p \big) $$

where $B$ is a symmetric positive definite matrix.

Consider the following constrained minimization problem: 

$$ p^* = \text{argmin}_p \; g^T p + \frac{1}{2} p^T B p $$

where $B$ is symmetric positive definite of size $n$, and $p^\*$ satisfies the constraint $\Vert p^\* \Vert_2^2 = 1$. Using the method of Lagrange multipliers, we can prove that there exists a real number $\lambda$ such that:

$$ g + B p^* = \lambda p^* $$

Assume that $B = Q \Lambda Q^T$ where $Q$ is orthogonal and $\Lambda$ is a diagonal matrix with positive real numbers $\lambda_j$ on the diagonal. We assume that $\lambda \neq \lambda_j$ for all $j$.

{:start="2"}
1. [3.16]. Prove that

$$ p^* = - \sum_{j=1}^n \frac{q_j^T g}{\lambda_j - \lambda} \; q_j $$

{:start="3"}
1. [3.16]. Prove that

$$ \Vert p^* \Vert_2^2 = \sum_{j=1}^n \Big( \frac{q_j^T g}{\lambda_j - \lambda} \Big)^2 $$

The next questions refer to slide deck "3.17 BFGS."

We define $P$ and $Q$ as

$$ P = I - \rho y s^T, \qquad Q = P^T$$

where $s$ and $y$ are vectors ($y^T s \neq 0$) and

$$\rho = \frac{1}{y^T s}$$

{:start="4"}
1. [3.17]. Show that $P^2 = P$ and that $Q^2 = Q$.
1. [3.17]. Show that $Px = 0$ for any $x$ parallel to $y$, and $Px = x$ for any $x$ orthogonal to $s$.
1. [3.17]. Show that $Qx = 0$ for any $x$ parallel to $s$, and $Qx = x$ for any $x$ orthogonal to $y$.

Define:

$$B = Q A P + \rho s s^T$$

for some matrix $A$.

{:start="7"}
1. [3.17]. Show that $By = s$.

The next questions refer to slide deck "3.18 L-BFGS."

Define

$$H_1 = (I-\rho s y^T) H_0 (I-\rho y s^T) + \rho s s^T$$

where $H_0$ and $H_1$ are matrices of size $n$, $s$ and $y$ are vectors, and $\rho$ is a real number.

{:start="8"}
1. [3.18]. Show that the pseudo-code below correctly calculates $H_1 q$ for some vector $q$.

`np.dot(x,y)` is the dot product between vectors `x` and `y`; `A.dot(x)` is the matrix-vector product `A*x`.

~~~Python
a = rho * np.dot(s,q)
q = q - a*y
r = H0.dot(q)
b = rho * np.dot(y,r)
r = r - b*s + a*s # Show that r = H1*q
~~~

Assume now that computing `H0.dot(q)` takes $O(n)$ ([big O notation](https://en.wikipedia.org/wiki/Big_O_notation)) floating point operations.

{:start="9"}
1. [3.18]. Show that the pseudo-code above allows computing `H1.dot(q)` in $O(n)$ floating point operations.
