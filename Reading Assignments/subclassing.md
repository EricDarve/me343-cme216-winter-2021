---
layout: page
title: subclassing
---

These questions refer to the slide deck "2.6 Subclassing".

Write your answers in a PDF and upload the document on [gradescope](https://www.gradescope.com/courses/102338) for submission.

Each question is worth 10 points. The due date is given on [gradescope](https://www.gradescope.com/courses/102338). Post on [Slack](https://stanford.enterprise.slack.com/) for questions.

Late day policy: 1 late day with a 20% grade penalty.

1. Explain what the declarative and imperative styles of programming are. Try to give examples of both.
1. Explain what Python inheritance is.
1. Explain what the `__init__()` function does in Python.
1. Explain what `super()` does in Python.
1. In a notebook, run the following code:
```Python
import tensorflow as tf
inputs = tf.keras.Input(shape=(32,))
x = tf.keras.layers.Dense(64, activation='relu')(inputs)
outputs = tf.keras.layers.Dense(10)(x)
mlp = tf.keras.Model(inputs, outputs)
```
Describe the structure of this DNN.
1. Implement the same DNN using the subclassing interface. Follow the instructions below. Check that the output is correct by comparing with the solution given below.
1. Which interface between functional and subclassing appears to be the simplest? When would you recommend to use the functional API vs the subclassing API?

**Instructions**

Call your class `MLP`
```Python
class MLP(tf.keras.Model):
    [...]
```

You can set the name of your model to `mlp_subclassing` by calling:
```Python
super(MLP, self).__init__(name="mlp_subclassing", **kwargs)
```
in the constructor `__init__(self, **kwargs)`.

Run this code in your notebook _after creating the class:_
```Python
# Instantiate the model.
mlp_subc = MLP()
# The model doesn't have a state until it's called at least once.
_ = mlp_subc(tf.zeros((1, 32)))
mlp_subc.summary() # Print summary of model
```

Verify that the output is

    Model: "mlp_subclassing"
    _________________________________________________________________
    Layer (type)                 Output Shape              Param #   
    =================================================================
    dense (Dense)                multiple                  2112      
    _________________________________________________________________
    dense_1 (Dense)              multiple                  650       
    =================================================================
    Total params: 2,762
    Trainable params: 2,762
    Non-trainable params: 0

