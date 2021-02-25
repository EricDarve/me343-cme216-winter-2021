using ADCME
using PyCall
using LinearAlgebra
using PyPlot
using Random
Random.seed!(233)

"""
u - temperature (the state variable)
f - source term 
kappa - diffusivity coefficient 
dt - time step 
dx - space step 
m, n - #intervals for x and y directions
see README.md for detailed explaination. 
"""
function heat_equation(u, f, kappa, dt, dx, m, n)
    libpath = joinpath(@__DIR__, "./cpp/build/libHeatEquation")
    heat_equation_ = load_op_and_grad(libpath, "heat_equation")
    u, f, kappa, dt, dx, m, n = convert_to_tensor([u,f,kappa,dt,dx,m,n], [Float64,Float64,Float64,Float64,Float64,Int64,Int64])
    heat_equation_(u, f, kappa, dt, dx, m, n)
end


m = 10
n = 10
NT = 50
h = 1/m
dt = 1/NT 

x = zeros((m+1)*(n+1))
y = zeros((m+1)*(n+1))
for i = 1:m+1
    for j = 1:n+1
        idx = (j-1)*(m+1)+i 
        x[idx] = (i-1)*h 
        y[idx] = (j-1)*h 
    end
end

u0 = @. (1-x)*x*(1-y)*y
F = zeros(NT+1, (m+1)*(n+1))
U = zeros(NT+1, (m+1)*(n+1))
κ = @. 1 + x + y 
for i = 1:NT+1
    t = (i-1)*dt 
    U[i,:] = @. (1-x)*x*(1-y)*y*exp(-t)
    F[i,:] = dt * (@. -U[i,:] - κ*(-2y*(1-y)-2x*(1-x))*exp(-t))
end

function condition(i, u)
    i <= NT+1
end

function body(i, u_arr)
    u = read(u_arr, i-1)
    unext = heat_equation(u,F[i],κ,dt,h,m,n)
    i+1, write(u_arr, i, unext)
end

u_arr = TensorArray(NT+1)
u_arr = write(u_arr, 1, u0)
F = constant(F) # Must be converted to Tensor, so that you can call F[i] where i is a tensor 
i = constant(2, dtype=Int32)
_, u = while_loop(condition, body, [i, u_arr])
u = set_shape(stack(u) , (NT+1, (m+1)*(n+1))) # Reshape TensorArray to a usual tensor 

err = sqrt(mean((u[end,:] - U[end,:])^2))
sess = Session(); init(sess)
Uest = run(sess, u)
@show run(sess, err)

mesh(reshape(Uest[end,:], m+1, n+1))
mesh(reshape(U[end,:], m+1, n+1), color="orange")