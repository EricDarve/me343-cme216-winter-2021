---
layout: page
title: Computational Graph
--- 

Write your answers in a PDF and upload the document on [gradescope](https://www.gradescope.com/courses/102338) for submission. Each question is worth 10 points. Post on [Slack](https://stanford.enterprise.slack.com/) for questions.

Late day policy: 1 late day with a 20% grade penalty.

The next questions refer to video "4.2 Computational Graph."

Consider the following function:

$$ f(x) = \cos(x^2) + x + 1 $$

1. Draw the computational graph used to compute this function. Each node in your graph should be an arithmetic operation, or the computation of $$\cos$$. The graph should have one input $$x$$ and one output $$y$$.

Consider the figure in slide [17](https://ericdarve.github.io/cme216-spring-2020/Slides/AD/AD.pdf#page=17)/47. Denote the input $$x$$ on the left and the output $$y$$ on the right. We will denote $$z_i$$ the output of node $$i$$. The nodes are numbered from 1 to $$n$$, going from left to right. Each node corresponds to some arithmetic operation. This graph is a linear graph. We will use it to illustrate a few concepts.

Using the chain rule, we have:

$$ \frac{\partial z_{i+1}}{\partial x} = \frac{\partial z_{i+1}}{\partial z_i} \frac{\partial z_i}{\partial x} $$

{:start="2"}
1. Use this equation and propose an algorithm to calculate 

$$ \frac{\partial y}{\partial x} $$ 

by traversing the graph from the **left to the right.** You should use a recurrence with $$i$$ going from 1 to $$n$$. This corresponds to *forward-mode* automatic differentiation (AD).

Using the chain rule again, we also have that

$$ \frac{\partial y}{\partial z_i} = \frac{\partial y}{\partial z_{i+1}} \frac{\partial z_{i+1}}{\partial z_i} $$

{:start="3"}
1. Use this equation and propose an algorithm to calculate to calculate $$\frac{\partial y}{\partial x}$$ by traversing the graph from the **right to the left.** You should use a recurrence with $$i$$ going from $$n$$ down to 1. This corresponds to *reverse-mode* AD.

Consider the figure in slide [18](https://ericdarve.github.io/cme216-spring-2020/Slides/AD/AD.pdf#page=18)/47. Assume that each node in the graph requires 1 microsec of computing time to both evaluate the function and its derivative. We denote each output as $$o_i$$, $$i = 1, \dots, 5$$ in the one-to-many case.

{:start="4"}
1. In the _one-to-many_ case, what is the computational cost of computing $$\frac{\partial o_i}{\partial x_1}$$ using _forward-mode_ AD, for all $$i = 1, \dots, 5$$?
1. In the one-to-many case, what is the computational cost of computing $$\frac{\partial o_i}{\partial x_1}$$ using _reverse-mode_ AD, for all $$i = 1, \dots, 5$$?
1. In the _many-to-one_ case, what is the computational cost of computing $$\frac{\partial o}{\partial x_i}$$ using forward-mode AD, for all $$i = 1, \dots, 5$$?
1. In the many-to-one case, what is the computational cost of computing $$\frac{\partial o}{\partial x_i}$$ using reverse-mode AD, for all $$i = 1, \dots, 5$$?