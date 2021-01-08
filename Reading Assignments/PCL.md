---
layout: page
title: Physics constrained learning
--- 

Write your answers in a PDF and upload the document on [gradescope](https://www.gradescope.com/courses/102338) for submission. Each question is worth 10 points. Post on [Slack](https://stanford.enterprise.slack.com/) for questions.

[Videos](https://stanford-pilot.hosted.panopto.com/Panopto/Pages/Viewer.aspx?id=09969705-c96b-4e87-8424-abb7004200f4)
[Slides](https://ericdarve.github.io/cme216-spring-2020/Slides/AD/Inverse.pdf)

Late day policy: 1 late day with a 20% grade penalty.

The next questions refer to video "5.6 Training Methods: Physics Constrained Learning."

Consider the case shown in the slides:

$$ L(\theta) = \lVert u_\theta - u_0 \rVert_2^2 $$

$$ B(\theta) \, u_\theta = y $$

$u_\theta$ is a vector and $B$ is a matrix.

1. Show that

$$ \frac{\partial u_\theta}{\partial \theta} 
= - B(\theta)^{-1} \frac{\partial B}{\partial \theta} u_\theta
$$

{:start="2"}
1. Use the previous result to show that

$$ \frac{\partial L}{\partial \theta} 
= - 2 (u_\theta - u_0)^T B(\theta)^{-1} \frac{\partial B}{\partial \theta} u_\theta
$$

Assume that you have a numerical algorithm, denoted `LinearSolve(A,b,x)`, to solve linear systems of the form $Ax=b$ where $A$ is a matrix.

{:start="3"}
1. Explain how you can use `LinearSolve` to calculate $- 2 (u_\theta - u_0)^T B(\theta)^{-1} \; ?$ What are the arguments of `LinearSolve(___,___,___)` ?