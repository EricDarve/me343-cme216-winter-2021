---
layout: page
title: SGD and saddle points
--- 

Write your answers in a PDF and upload the document on [gradescope](https://www.gradescope.com/courses/102338) for submission. Each question is worth 10 points. The due date is given on [gradescope](https://www.gradescope.com/courses/102338). Post on [Slack](https://stanford.enterprise.slack.com/) for questions.

Late day policy: 1 late day with a 20% grade penalty.

The next questions refer to slide deck "3.11 Stochastic Gradient Descent."

1. Explain the difference between a batch and an epoch in SGD.
1. Assume that a batch uses 10% of the training set. How many DNN weight updates will you have per epoch?

The next questions refer to slide deck "3.12 Saddle points."

{:start="3"}
1. Consider a critical point and assume that all the eigenvalues of the Hessian are negative. What type of point is it?
1. Assume now that in dimension $$n=32$$, we have 20 positive eigenvalues and 12 negative eigenvalues. What type of point is it?
1. Consider $$L(x_1,\dots,x_{2n}) = \sum_{i=1}^n x_{2i-1} x_{2i}$$. Consider the point 

$$x = (x_1,\dots,x_{2n}) = 0$$

Show that it is a critical point. What are all the eigenvalues of the Hessian at this point? What are all the eigenvectors? Is this point a local minimum, maximum, or saddle point?

{:start="6"}
1. Explain why gradient descent methods tend to slow down near saddle points.
