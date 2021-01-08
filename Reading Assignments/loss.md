---
layout: page
title: Loss function
--- 

Write your answers in a PDF and upload the document on [gradescope](https://www.gradescope.com/courses/102338) for submission.

Each question is worth 10 points. The due date is given on [gradescope](https://www.gradescope.com/courses/102338). Post on [Slack](https://stanford.enterprise.slack.com/) for questions.

Late day policy: 1 late day with a 20% grade penalty.

The next questions refer to slide deck "3.1 Loss function for regression and classification".

1. What is the common choice of activation function for regression tasks?
1. Show that the Huber loss has a continuous derivative at $$\lvert x \rvert = \delta$$. Make sure that the signs are correct.
1. Explain how a DNN can produce a probability vector $$p_i$$, $$i = 1, \dots, n,$$ given some real numbers $$z_i,$$ $$i = 1, \dots, n.$$

The next questions refer to slide deck "3.2 Cross-entropy". 

The maximum of the entropy $$H(p) = - \sum_i p_i \ln p_i$$ is achieved when $$p_i$$ is constant and $$p_i = 1/n$$; $$n$$ is the number of states. Let's prove this result. 

We want to maximize $$H(p)$$ under the constraint that $$\sum_i p_i = 1$$. The constraint $$p_i \ge 0$$ is actually not required to find the solution in this case. 

To solve optimization problems under constraints, we can use the method of [Lagrange multipliers](https://en.wikipedia.org/wiki/Lagrange_multiplier). We define

$$ H_1(p,\lambda) = - \sum_i p_i \ln p_i + \lambda (\sum_i p_i - 1) $$

We can now maximize $$H_1(p,\lambda)$$ without having to worry about any constraint.

{:start="4"}
1. Since $$\partial H_1 / \partial \lambda = 0$$ at the optimum, show that this implies that $$\sum_i p_i = 1$$ at the optimum.
1. Calculate $$\partial H_1 / \partial p_i$$ in terms of $$p_i$$ and $$\lambda$$.
1. Use the fact that $$\partial H_1 / \partial p_i = 0$$, for all $$i$$, at the optimum to show that all the $$p_i$$ are equal to each other (it is a uniform probability). Conclude that $$p_i = 1/n$$ using $$\sum_i p_i = 1$$. This is the value at which the maximum is achieved.

We can use the same method to find the minimum of the cross-entropy with respect to $$q_i$$. 

We now use the following cost function with a Lagrange multiplier. The probability $$p$$ is now fixed for this problem.

$$ H_2(q,\lambda) = - \sum_i p_i \ln q_i + \lambda (\sum_i q_i - 1) $$

Don't get confused between $$p_i$$ and $$q_i$$ in this expression.

As before, we can prove that at the point of minimum, $$\sum_i q_i = 1$$.

{:start="7"}
1. Calculate $$\partial H_2 / \partial q_i$$ in terms of $$p_i$$, $$q_i$$, and $$\lambda$$.
1. Show that $$\partial H_2 / \partial q_i = 0$$ implies that $$q_i = p_i / \lambda$$. 
1. Since $$\sum_i q_i = \sum_i p_i = 1,$$ conclude that $$q_i = p_i$$ when the cross-entropy is minimum.