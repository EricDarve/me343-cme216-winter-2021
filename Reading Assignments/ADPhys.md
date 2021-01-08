---
layout: page
title: AD for Physical Simulations
--- 

Write your answers in a PDF and upload the document on [gradescope](https://www.gradescope.com/courses/102338) for submission. Each question is worth 10 points. Post on [Slack](https://stanford.enterprise.slack.com/) for questions.

Late day policy: 1 late day with a 20% grade penalty.

The next question refers to video "4.5 AD for Physical Simulations."

The discretization of the PDE is based on the idea of approximating a derivative using

$$ \frac{\partial u}{\partial x} \approx \frac{u(x+h) - u(x-h)}{2h} $$

If we use a uniform grid with spacing $$\Delta x$$, we get

$$ \frac{\partial u}{\partial x} \Big\lvert_i \approx \frac{u_{i+1} - u_{i-1}}{2 \Delta x} $$

To evaluate a second-order derivative like 

$$\triangle u = \frac{\partial^2 u}{\partial x^2}$$

we can use

$$ \triangle u(x_i) \approx \frac{u'(x + \Delta x / 2) - u'(x - \Delta x / 2)}{\Delta x} $$

where $$u'$$ is the derivative.

1. Use the approximation of the derivative and the previous equation to show that:

$$ \triangle u(x_i) \approx \frac{u_{i+1} - 2 u_i + u_{i-1}}{\Delta x^2} $$

{:start="2"}
1. Using the equation on Slide [36](https://ericdarve.github.io/cme216-spring-2020/Slides/AD/AD.pdf#page=40), show that row $$i$$ of $$A(a,b)$$ (slide [37](https://ericdarve.github.io/cme216-spring-2020/Slides/AD/AD.pdf#page=41)) is of the form (where $$i$$ is different from 1 and $$n$$):

$$ [ \hspace{3em} -\lambda_i, \; 2 \lambda_i + 1, \; - \lambda_i, \hspace{3em}] $$

with $$\lambda_i = \kappa_i \frac{\Delta t}{\Delta x^2}$$.

Consider the boundary condition on the right:

$$ u_{n+1} = 0 $$

{:start="3"}
1. Using this boundary condition, show that the last row of matrix $$A(a,b)$$ is 

$$ [ \hspace{3em} -\lambda_n, \; 2 \lambda_n + 1] $$

Assume now that $$\partial u / \partial x = 0$$ at node $$i = 1$$ on the left. For this specific problem, we can prove that this condition implies that the solution $$u(x)$$ can be extended and made even about $$x=0$$. This is done by formulating an equivalent PDE problem on the interval $$[-1,1]$$ with Dirichlet BC at $$x=-1$$ and $$x=1$$. At $$x=0$$, we recover $$\partial u / \partial x = 0$$. This solution $$u$$ formulated over the interval $$[-1,1]$$ is even and matches the solution $$u$$ to our problem on $$[0,1]$$.

With our numbering we have that $$x_1 = 0$$ and $$x_2 = \Delta x$$. We introduce the point $$x_0 = -\Delta x$$. Since $$u$$ is even (a consequence of the $$\partial u / \partial x = 0$$ condition as discussed above), we get:

$$ \frac{u_2 - u_0}{2 \Delta x} \approx \frac{\partial u}{\partial x} \Big\rvert_{x=0} = 0, \text{ or } u_0 = u_2$$

{:start="4"}
1. Using this result, show that row 1 of matrix $$A(a,b)$$ is 

$$ [ 2 \lambda_1 + 1, \; - 2 \lambda_1, \hspace{3em}] $$