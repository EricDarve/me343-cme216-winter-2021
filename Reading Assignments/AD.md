---
layout: page
title: Automatic Differentiation Overview
--- 

Write your answers in a PDF and upload the document on [gradescope](https://www.gradescope.com/courses/102338) for submission. Each question is worth 10 points. Post on [Slack](https://stanford.enterprise.slack.com/) for questions.

Late day policy: 1 late day with a 20% grade penalty.

The next questions refer to video "4.1 Automatic Differentiation Overview."

Real numbers on a computer are represented using only a finite number of digits. The format that is used is called the floating point representation. Because of this, when representing numbers like $$\pi$$, the result of an operation (addition, subtraction) or even simply $$1/3$$, there is always a small error that is proportional to the unit roundoff $$u$$. Denote fl the floating point representation of a real number or the result of an operation. Then, for example:

$$ \text{fl}(\pi) \approx \pi + u \pi $$

Similarly: 

$$ \text{fl}(a+b) \approx a+b + u (a+b) $$

$$ \text{fl}(a*b) \approx a*b + u (a*b) $$

$$ \text{fl}(\sin(x)) \approx \sin(x) + u \sin(x) $$

and so on for all operations.

In single precision, $$u \approx 10^{-8}$$ and in double precision $$u \approx 10^{-16}$$.

See [What Every Computer Scientist Should Know About Floating-Point Arithmetic](https://docs.oracle.com/cd/E19957-01/806-3568/ncg_goldberg.html) for more details on this.

Assume we use a central difference scheme to approximate a derivative:

$$ f'(x) \approx \frac{f(x+h) - f(x-h)}{2h} $$

Take for example $$x=\pi/4$$ and $$f = \sin$$. Assume $$u = 10^{-8}$$ and $$h = 10^{-4}$$.

1. Estimate the error when computing $$x+h$$ and $$x-h$$ on a computer.
1. Estimate the error when computing $$f(x+h)$$ and $$f(x-h)$$. Account for the fact that at the previous step we made an error in $$x+h$$ and $$x-h.$$
1. Estimate the final error when computing 

$$ \frac{f(x+h) - f(x-h)}{2h} $$

Take into account errors from previous steps as they propagate.

{:start="4"}
1. What would happen if $$h = 10^{-6}$$? What would happen if $$h = 10^{-16}$$?

As a reference we chose $$h=10^{-5}$$ and computed the following in Python:

```
h = 1e-05
sin(x+h) 0.7071139
sin(x-h) 0.70709974
sin(x+h)-sin(x-h) 1.41859055e-05
(sin(x+h)-sin(x-h))/(2h) 0.7092952907454546
```

This can be compared with a calculation in extended precision where $$u \approx 10^{-20}$$:

```
sin(x+h) 0.70711385221900393297
sin(x-h) 0.70709971008338043772
sin(x+h)-sin(x-h) 0.000014142135623495248128
(sin(x+h)-sin(x-h))/(2h) 0.70710678117476240638
```

{:start="5"}
1. Calculate the symbolic derivative of 

$$ \tanh(x^2 + 1) $$

with respect to $$x$$.

In automatic differentiation, we use numerical values and we carry both the value of the variables and their derivatives as we process each operation.

Assume that $$x = 1$$ and $$x' = 8$$. This set up is the usual one in automatic differentiation. We don't need to specify the independent variable. From the numerical values of $$x$$ and its derivative $$x'$$, you can compute all the subsequent derivatives using automatic differentiation.

{:start="6"}
1. Calculate the value of $$x^2 + 1$$ and its derivative.
1. Calculate the value of $$\tanh(x^2 + 1)$$ and its derivative, using the result from the previous question.
