# Instruction: Complete ____ and add additional codes at your will
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

# simulation parameters 
m = 50
n = 50
NT = 50
h = 1 / m
dt = 1 / NT 

x = zeros((m + 1) * (n + 1))
y = zeros((m + 1) * (n + 1))
for i = 1:m + 1
    for j = 1:n + 1
        idx = (j - 1) * (m + 1) + i 
        x[idx] = (i - 1) * h 
        y[idx] = (j - 1) * h 
    end
end

F = zeros(NT + 1, (m + 1) * (n + 1))
κ = zeros((m + 1) * (n + 1))

# TODO: Populate values into F and κ
κ = ____
for i = 1:NT + 1
    t = (i - 1) * dt 
    F[i,:] = ____
end

########################### Simulation Loop ########################### 
function condition(i, u_arr)
    i <= NT + 1
end

function body(i, u_arr)
    u = read(u_arr, i - 1) # temperature vector at last step 
    # TODO: Compute u_next using heat_equation
    u_next = heat_equation(____)
    i + 1, write(u_arr, i, u_next)
end

u_arr = TensorArray(NT + 1)
u_arr = write(u_arr, 1, zeros((m + 1) * (n + 1)))
F = constant(F) # Must be converted to Tensor, so that you can call F[i] where i is a tensor 
i = constant(2, dtype = Int32)
_, u = while_loop(condition, body, [i, u_arr])
u = set_shape(stack(u), (NT + 1, (m + 1) * (n + 1))) # Reshape TensorArray to a usual tensor 

########################### Simulation Ends ############################ 

# TODO: Exact values at the center 

sess = Session(); init(sess)

# TODO: Plot the curve of the temperature at (0.5,0.5)