---
layout: page
title: Python Setup Guide
---

We use python 3 for programming assignments in this course. We don't expect the specific version of python 3 to make a difference - anything 3.6 or later should work. This guide is intended to help you set up python on your local machine, if you haven't already. You don't have to follow this guide if you have other preferred ways to use python and manage dependencies. However, we will only provide support for using Anaconda.

## 1. Install Anaconda

Follow this [link](https://www.anaconda.com/distribution/), download and install Anaconda compatible with your operating system. (For Windows: the installed ***Powershell Prompt*** is the command line environment you want to use.)

## 2. Virtual Environment
We recommend maintaining a virtual environment for this course to separate the dependencies from your other python projects, though it's not required. When you are in a virtual environment, your command line path is prefixed by the environment name in parenthesis.

First, create a virtual environment. For example, to create an environment named "cme216" with Python 3.7, run the following command in your terminal:

`conda create -n cme216 python=3.7`

Second, activate the environment you just created. Run

`conda activate cme216`

To confirm which Python you are using, run `which python`. The path should be something like `"XXX/anaconda3/envs/cme216/bin/python"`.

## 3. Package Management With Conda
With the virtual environment ***activated***, to install a package, run

`conda install <package name>`.

Specifically, for this course we will frequently use Jupyter Notebook, an open-source web application to edit and excute codes. To install Jupyter Notebook, run

`conda install -c conda-forge notebook`

To install packages listed in a file, run

`conda install --file=<filename>`.

To exit the current environment, run `conda deactivate`.

The full documentation for Anaconda commands can be found [here](https://docs.conda.io/projects/conda/en/latest/commands.html).
