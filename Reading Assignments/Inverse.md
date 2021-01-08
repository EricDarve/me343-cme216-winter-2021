---
layout: page
title: Inverse problems
--- 

Write your answers in a PDF and upload the document on [gradescope](https://www.gradescope.com/courses/102338) for submission. Each question is worth 10 points. Post on [Slack](https://stanford.enterprise.slack.com/) for questions.

[Videos](https://canvas.stanford.edu/courses/118944/external_tools/3367)
[Slides](https://ericdarve.github.io/cme216-spring-2020/Slides/AD/Inverse.pdf)

Late day policy: 1 late day with a 20% grade penalty.

The next questions refer to video "5.1 Inverse Problem Overview."

Assume that the unknown function $\kappa(x)$ is written in polynomial form:

$$ \kappa(x) = a_0 + a_1 x + \cdots + a_k x^k $$

1. Is this a parameter inverse problem, a function inverse problem, or stochastic inverse problem?

Assume now that $\kappa(x,u)$ is a function of the independent variable $x$ and the solution $u(x)$ of the PDE.

{:start="2"}
1. What type of inverse problem is it?

The next questions refer to video "5.2 Neural Networks as Function Approximators: Part I" and "5.3 Part II."

{:start="3"}
1. Can a DNN be written as a linear combination of basis functions $\phi_i(x)$ in general? Provide a justification for your answer.

We consider the unit cube in dimension $\mathbb R^d$. The unit cube is the set of all points $x=(x_1,\dots,x_d)$, such that $0 \le x_i \le 1$, $1 \le i \le d$. Assume that we discretize the unit cube using a Cartesian grid, made of small cubes, which we call elements; $h$ is the length of the sides of each element.

{:start="4"}
1. How many elements are required to cover the unit cube? Give your answer in terms of $h$ and $d.$
1. Check slide [20](https://ericdarve.github.io/cme216-spring-2020/Slides/AD/Inverse.pdf#page=20)/50. Explain what it means that DNNs are robust to noise compared to RBF.