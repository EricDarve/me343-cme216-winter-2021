---
layout: page
title: Backpropagation
--- 

Write your answers in a PDF and upload the document on [gradescope](https://www.gradescope.com/courses/102338) for submission.

Each question is worth 10 points. The due date is given on [gradescope](https://www.gradescope.com/courses/102338). Post on [Slack](https://stanford.enterprise.slack.com/) for questions.

Late day policy: 1 late day with a 20% grade penalty.

The next questions refer to slide decks "3.4 Backpropagation" and "3.5 Backpropagation formula".

1. Assume you have the vector $$z = [0, \pi, 3\pi/2]$$ and $$\phi(x) = \cos(x)$$. What is $$\phi \odot z$$ equal to?
1. Assume that $$y = a^T \phi \odot (w x + b)$$ where $$a$$, $$b$$, and $$x$$ are vectors of size $$n$$, and $$w$$ is a scalar. Calculate $$\partial y / \partial w$$ and $$\partial y / \partial b$$ (a vector).
1. Assume that $$L = (y - a^T \tanh \odot (W x + b))^2 $$ where $$y$$ is a scalar, $$a$$, $$x$$, and $$b$$ are vectors of size $$n$$, and $$W$$ is an $$n \times n$$ matrix. `tanh` is the [hyperbolic tangent function.](https://en.wikipedia.org/wiki/Hyperbolic_functions#Derivatives) Calculate $$\partial L / \partial W$$ (an $$n \times n$$ matrix) and $$\partial L / \partial b$$ (a column vector).
1. Assume we use the ReLU activation function for all layers. At some layer $$k$$, we have that $$[W^{(k)} a^{(k-1)} + b^{(k)}]_i < 0$$, for all $$i$$. Show that $$\partial y / \partial W^{(l)} = 0$$ for all $$1 \le l \le k+1$$. Note that $$l = k+1$$ is included.
1. Summarize the steps required to compute $$\partial y / \partial W^{(k)}$$ using a forward and backward pass in the backpropagation algorithm.