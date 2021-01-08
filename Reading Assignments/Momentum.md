---
layout: page
title: Momentum and ADAGRAD
--- 

Write your answers in a PDF and upload the document on [gradescope](https://www.gradescope.com/courses/102338) for submission. Each question is worth 10 points. Post on [Slack](https://stanford.enterprise.slack.com/) for questions.

Late day policy: 1 late day with a 20% grade penalty.

The next questions refer to slide deck "3.13 Momentum."

Assume that

$$ x_{n+1} = \beta x_n + f_n $$

1. Show that:

$$ x_n = \beta^n x_0 + \sum_{k=0}^{n-1} \beta^k f_{n-1-k} $$

To prove this, use $$y_n$$ with 

$$ x_n = \beta^n y_n $$

{:start="2"}
1. Assume that $$\lvert \beta \rvert \ll 1$$ (very small compared to 1). Show that

$$ x_n \approx f_{n-1} $$

{:start="3"}
1. Assume now that $$f_n = f$$ is constant. Show that:

$$ x_n = \Big( x_0 - \frac{f}{1-\beta} \Big) \, \beta^n + \frac{f}{1-\beta} $$

The next questions refer to slide deck "3.14 Adagrad."

{:start="4"}
1. With $$H_\beta = D_\beta H D_\beta$$, give an expression for $$[H_\beta]_{ij}$$ in terms of $$\beta$$ and $$H_{ij}.$$ Assume that $$[D_\beta]_{ii} = \beta^{i-1}$$.
1. Show that in ADAGRAD, $$[s^{(k+1)}]_i \ge [s^{(k)}]_i$$, that is the sequence is monotonically increasing; $$k$$ is the batch index.
1. Consider $$x_n = A^n x_0$$ for some symmetric matrix $$A$$. Denote $$\lambda$$ the eigenvalue of $$A$$ with the largest magnitude. Denote $$u$$ the corresponding eigenvector with norm 1. Show that 

$$x_n \approx \lambda^n (u^T x_0) u $$

{:start="7"}
1. Consider again $$x_n = A^n x_0$$ from the previous question, with $$\lvert u^T x_0 \rvert = 1.$$ Assume that the largest eigenvalue is $$\lambda = 0.999$$. Estimate the value of $$n$$ for which $$\lVert x_n \rVert = 0.001$$. Assume now that $$\lambda = 0.9$$. Estimate again the value of $$n$$ for which $$\lVert x_n \rVert = 0.001$$. Comment on your findings.