---
layout: page
title: Tensorflow
---

These questions refer to the slide deck "2.3 TensorFlow/Keras", "2.4 Sequential API," and "2.5 Functional API".

Write your answers in a PDF and upload the document on [gradescope](https://www.gradescope.com/courses/102338) for submission.

Each question is worth 10 points. The due date is given on [gradescope](https://www.gradescope.com/courses/102338). Post on [Slack](https://stanford.enterprise.slack.com/) for questions.

Late day policy: 1 late day with a 20% grade penalty.

1. Explain the difference between Keras and `tf.keras`. This [blog](https://www.pyimagesearch.com/2019/10/21/keras-vs-tf-keras-whats-the-difference-in-tensorflow-2-0/) has a good summary of some of the main features of TensorFlow 2.0 and its relation to Keras.
1. Explain when you would use the Sequential API vs the Functional API in TensorFlow.
1. Write a few lines of Python to implement the DNN shown below using the Functional API. The input has dimension 8. The output has dimension 2. All layers are fully connected. The activation function is `tanh`.

Output of `keras.utils.plot_model(model)`

    Model: "model"
    __________________________________________________________________________________________________
    Layer (type)                    Output Shape         Param #     Connected to                     
    ==================================================================================================
    input_1 (InputLayer)            [(None, 8)]          0                                            
    __________________________________________________________________________________________________
    dense (Dense)                   (None, 32)           288         input_1[0][0]                    
    __________________________________________________________________________________________________
    dense_1 (Dense)                 (None, 16)           528         dense[0][0]                      
    __________________________________________________________________________________________________
    dense_2 (Dense)                 (None, 8)            136         dense_1[0][0]                    
    __________________________________________________________________________________________________
    concatenate (Concatenate)       (None, 48)           0           input_1[0][0]                    
                                                                     dense[0][0]                      
                                                                     dense_2[0][0]                    
    __________________________________________________________________________________________________
    dense_3 (Dense)                 (None, 2)            98          concatenate[0][0]                
    ==================================================================================================
    Total params: 1,050
    Trainable params: 1,050


![](DAG_functional.png)