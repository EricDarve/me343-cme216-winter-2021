---
layout: page
title: RMSProp and Adam
--- 

Write your answers in a PDF and upload the document on [gradescope](https://www.gradescope.com/courses/102338) for submission. Each question is worth 10 points. Post on [Slack](https://stanford.enterprise.slack.com/) for questions.

Late day policy: 1 late day with a 20% grade penalty.

The next questions refer to slide deck "3.15 RMSProp and Adam."

RMSProp uses the following update formula for $$s_i^{(k)}$$ where $$k$$ is the batch index:

$$ s_i^{(k+1)} = \beta s_i^{(k)} + (1-\beta) \Big( \frac{\partial L_k}{\partial x_i} \Big)^2 $$

Assume that the gradient is constant:

$$ s_i^{(k+1)} = \beta s_i^{(k)} + (1-\beta) \, G_i^2 $$

1. Take $$0 < \beta < 1$$. Calculate the value of $$ s_i^{(k)} $$ when $$k$$ is very large.
1. Why is the Adam method applying this scaling to $$m_i$$:

$$ \hat{m}_i \leftarrow \frac{m_i}{1-\beta_1^k} $$

{:start="3"}
1. Give a heuristic explanation about why the use of momentum for the gradient (i.e., $$m$$) in Adam may accelerate convergence near saddle points in some cases?
1. Look at slide 25, the right figure. What do you observe for Rmsprop (black line) vs Adagrad (blue line) towards the end? Explain.
1. Look at slide 25, the right figure. Explain the sudden acceleration of Momentum (green line) towards the end.