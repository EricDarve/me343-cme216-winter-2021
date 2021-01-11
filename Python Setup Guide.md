---
layout: page
title: Python Setup Guide
---

We use python 3 for programming assignments in this course. We don't expect the specific version of python 3 to make a difference - anything 3.6 or later should work. This guide is intended to help you set up python on your local machine, if you haven't already. You don't have to follow this guide if you have other preferred ways to use python and manage dependencies. However, we will only provide support for using Anaconda.

## Installation
### Windows
Windows systems don't have python pre-installed, we recommend installing the Anaconda distribution. A few other options are listed, but we won't be providing support for those methods.
1. [Anaconda](https://www.anaconda.com/distribution/): Follow the link, download and install the appropriate version. The installed ***Powershell Prompt*** is the command line environment you want to use
2. Install python following this [documentation](https://docs.python.org/3/using/windows.html)
3. Install the Ubuntu 18.04 distribution of [Windows subsystem for Linux](https://docs.microsoft.com/en-us/windows/wsl/install-win10) and use the Ubuntu Bash terminal.
4. Set up a Linux virtual machine
5. Install a Linux OS alongside your current OS as a dual boot.
6. Install an integrated development environment (IDE) that can manage dependencies.

### MacOS and Linux
In your terminal, run `python3 --version` to see if python is already installed, and its version if installed. If not installed, click [Anaconda](https://www.anaconda.com/distribution/), download and install the appropriate version. You can use the conda commands directly in your regular terminal.

## Virtual Environment
We recommend maintaining a virtual environment for this course to separate the dependencies from your other python projects, though it's not required. When you are in a virtual environment, your command line path is prefixed by the environment name in parenthesis.

## Anaconda
This [page](https://docs.conda.io/projects/conda/en/latest/commands.html) describes the commands for Anaconda. Below are some common ones.
- Run `conda create -n <environment name>` to create an environment
- Run `conda activate <environment name>` to activate an environment
- Run `conda deactivate` to deactivate the current environment
- Run `conda install <package name>` to install a package, run `conda install --file=<filename>` to install packages listed in a file
