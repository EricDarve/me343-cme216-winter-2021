---
layout: page
title: Forward and reverse modes
--- 

Write your answers in a PDF and upload the document on [gradescope](https://www.gradescope.com/courses/102338) for submission. Each question is worth 10 points. Post on [Slack](https://stanford.enterprise.slack.com/) for questions.

Late day policy: 1 late day with a 20% grade penalty.

The next question refers to video "4.3 Forward Mode."

In automatic differentiation (AD), at every step, we keep track of the result of the calculation up to that point, along with derivatives with respect to all the input variables.

For example, let's consider the graph $$G$$ that takes as input two independent variables $$(x_1,x_2)$$. The first node is $$y_1 = x_1^2$$, the second node is $$y_2 = 2 x_2$$, and the third node $$y_3 = y_1 + y_2$$.

In AD, we keep track of the numerical value of the node, along with the derivatives with respect to all the independent variables. This can be represented as a tuple of 3 values for each node. Assume that $$x_1 = 1$$ and $$x_2 = -2$$. For graph $$G$$:

- Node $$y_1(x_1)$$: $$(y_1,\partial y_1 / \partial x_1, \partial y_1 / \partial x_2) = (1, 2, 0)$$.
- Node $$y_2(x_2)$$: $$(y_2,\partial y_2 / \partial x_1, \partial y_2 / \partial x_2) = (-4, 0, 2)$$.
- Node $$y_3(y_1,y_2)$$: $$(y_3,\partial y_3 / \partial x_1, \partial y_3 / \partial x_2) = (-3, 2, 2)$$.

For example the derivative $$\partial y_3 / \partial x_1$$ is evaluated using:

$$ \frac{\partial y_3}{\partial x_1} = \frac{\partial y_3}{\partial y_1} \frac{\partial y_1}{\partial x_1} + \frac{\partial y_3}{\partial y_2} \frac{\partial y_2}{\partial x_1} = 1 \times 2 + 1 \times 0 = 2 $$

Consider the following function:

$$ y(x_1,x_2,x_3) = x_3^2 \log ( x_1 + 2 x_2 ) $$

The computational graph $$G_1$$ to compute $$y$$ has 5 nodes, where $$y = y_5$$. Each node is one arithmetic operation or the calculation of log. Assume that $$x_1 = e - 2$$, $$x_2 = 1$$, $$x_3 = 2$$.

1. Using graph $$G_1$$, show the steps in forward-mode AD to compute the tuple for output node $$y = y_5$$:

$$ \Big( y, \frac{\partial y}{\partial x_1}, \frac{\partial y}{\partial x_2}, \frac{\partial y}{\partial x_3} \Big) $$

The next question refers to video "4.4 Reverse Mode."

Reverse-mode AD performs similar calculations but starting from the end and moving towards the input of the graph. Take for example graph $$G$$. The steps are:

- Step 1; node $$y_3(y_1,y_2)$$: $$(y_3,\partial y_3 / \partial y_1, \partial y_3 / \partial y_2) = (-3, 1, 1)$$.
- Step 2; node $$y_2(x_2)$$: $$(y_2,\partial y_3 / \partial y_1, \partial y_3 / \partial x_2) = (-4, 1, 2)$$.
- Step 3; node $$y_1(x_1)$$: $$(y_1,\partial y_3 / \partial x_1, \partial y_3 / \partial x_2) = (1, 2, 2)$$.

Reverse-mode requires that we have first traversed the graph in the forward direction to compute the derivatives of all the node values with respect to their inputs. This is called the forward pass. The derivatives of the output with respect to all the inputs are then computed using the backpropagation formula. For example, at Step 3 above, we used:

$$ \frac{\partial y_3}{\partial x_1} = \frac{\partial y_3}{\partial y_1} \frac{\partial y_1}{\partial x_1} = 1 \times 2 = 2 $$

$$\partial y_3 / \partial y_1$$ is from Step 2; $$\partial y_1 / \partial x_1$$ (node derivative) was computed during the forward pass.

The general rule is as follows. Assume we are at step $$s$$. At step $$s+1$$, we add node $$y_j(y_{i_1},\dots, y_{i_k})$$. For step $$s+1$$, we keep all the derivatives from step $$s$$ except $$\partial y / \partial y_j$$. This derivative is removed and replaced by all the derivatives $$\partial y / \partial y_{i_l}$$, $$1 \le l \le k$$, which are computed using

$$ \frac{\partial y}{\partial y_{i_l}} = \frac{\partial y}{\partial y_j} \frac{\partial y_j}{\partial y_{i_l}} $$

If the derivative $$\partial y / \partial y_{i_l}$$ was already present at step $$s$$, we add the new contribution

$$ \frac{\partial y}{\partial y_{i_l}} \leftarrow \frac{\partial y}{\partial y_{i_l}} + \frac{\partial y}{\partial y_j} \frac{\partial y_j}{\partial y_{i_l}} $$

Go back to the example above to make sure you understand how the process works.

If you return to the slides for the backpropagation algorithm for DNN, you will see that we followed exactly these steps, but specialized for sequential DNNs. There was a forward pass, followed by the backpropagation.

{:start="2"}
1. Return to the example with graph $$G_1$$. Redo the differentiation using reverse-mode. You should start from $$y_5=y$$, then go to $$y_4$$, &hellip;, $$y_1$$. For each $$y_k$$, list all the derivatives that are needed at that step, and their value. At the end of this process you should find the expression for $$\partial y / \partial x_i$$, $$i=1,2,3.$$ It should match your answer using forward mode. The intermediate steps however will be different from the forward-mode.