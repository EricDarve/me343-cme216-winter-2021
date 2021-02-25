# Solving a Heat Equation using the Differentiable Kernel

This toolset includes an exemplary custom operator for ADCME. The list of files are 

- `CMakeLists.txt`: rules to build the binary product
- `HeatEquation.cpp` and `HeatEquation.h`: C++ source codes
- `example.jl`: a working example

This tutorial walks through solving 

$$u_t(x, y, t) = \kappa(x, y) \Delta u(x, y, t) + f(x, y, t),\quad (x, y)\in \Omega, t\in [0,T]$$

with boundary and initial conditions

$$\begin{aligned}
u(x, y, 0) &= u_0(x,y), \quad (x,y) \text{ in }  \Omega\\
u(x,y,t) &= 0 ,\quad (x,y) \text{ in } \partial \Omega
\end{aligned}$$


## Install 

See [Setup Guide](../Setup.md) for installation instruction.

## Numerical Methods

We apply the finite difference method to the problem. Consider $\Omega=[0,1]\times [0,1]$, we use a uniform grid and divide the domain into $m\times n$ squares, with length $\Delta  x$. We also divide $[0,T]$ into $N_T$ intervals of equal length The implicit scheme for the equation is 

$$\frac{u_{ij}^{k+1}-u_{ij}^k}{\Delta t} = \kappa_{ij}\frac{u_{i+1,j}^{k+1}+u_{i,j+1}^{k+1}+u_{i-1,j}^{k+1}+u_{i,j-1}^{k+1}-4u_{ij}^{k+1}}{\Delta x^2} + f_{ij}^{k+1} \tag{FD}$$

where $i=2,3,\ldots, m, j=2,3,\ldots, n, k=1,2,\ldots, N_T$.

Here $u_{ij}^k$ is an approximation to $u((i-1)h, (j-1)h, (k-1)\Delta t)$, and $f_{ij}^k = f((i-1)h, (j-1)h, (k-1)\Delta t)$.

We flatten $\{u_{ij}^k\}$ to a vector $U^k$, using $i$ as the leading dimension, i.e., the order is $u_{11}^k, u_{12}^k, \ldots$. We also flatten $f_{ij}^{k+1}$ to $F^{k+1}$ , and $\kappa_{ij}$ to $\Kappa$ in the same way

In `example.jl`, you will see a function

```julia
function heat_equation(u,f,kappa,dt,dx,m,n)
    heat_equation_ = load_op_and_grad("./build/libHeatEquation","heat_equation")
    u,f,kappa,dt,dx,m,n = convert_to_tensor([u,f,kappa,dt,dx,m,n], [Float64,Float64,Float64,Float64,Float64,Int64,Int64])
    heat_equation_(u,f,kappa,dt,dx,m,n)
end
```

This function implements Equation (FD), where the corresponding arguments are 

* `u`: $U^k$
* `f`: $\Delta tF^k$
* `kappa`: $\Kappa$
* `dt`: $\Delta t$
* `dx`: $\Delta x$
* `m`: $m$ 
* `n`: $n$
* Output: $U^{k+1}$

:warning: Make sure the path `./build/libHeatEquation` in the code contains the binary product you just build. You can also change it to other path as well. However, if you worked on `starter.jl` in this directory, there is no need to worry about the path. 

## Usage

`example.jl` shows an example for solving the heat equation with 

$$\begin{aligned}
u(x, y, t) &= (1-x)x(1-y)ye^{-t}\\
\kappa(x,y) &= 1+x+y
\end{aligned}$$

$f$ and $u_0$ can be inferred from the exact solution. 

