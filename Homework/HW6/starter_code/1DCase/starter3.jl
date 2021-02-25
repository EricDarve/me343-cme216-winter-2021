# Instruction: Complete ____ and add additional codes at your will
using ADCME 
using PyPlot
using DelimitedFiles

m = 50
n = 50
dt = 1 / m
dx = 1 / n
F = zeros(m + 1, n)
xi = LinRange(0, 1, n + 1)[1:end - 1]
f = (x, t)->exp(-50(x - 0.5)^2)
for k = 1:m + 1
    t = (k - 1) * dt
    F[k,:] = dt * f.(xi, t)
end

xi_input = Array(reshape(xi, :, 1))
# TODO: Construct a neural network that maps xi_input to output
κ = squeeze(____)
# For squeeze: see the ADCME doc 
# https://kailaix.github.io/ADCME.jl/dev/tu_basic/
# and the corresponding function in TF
# https://www.tensorflow.org/api_docs/python/tf/squeeze

# We transform κ to a positive value
κ = log(1 + exp(κ))

A = spdiag(n, -1 => ____, 0 => ____, 1 => ____)

function condition(i, u_arr)
    i <= m + 1
end

function body(i, u_arr)
    u = read(u_arr, i - 1)
    rhs = u + F[i]
    u_next = A \ rhs
    u_arr = write(u_arr, i, u_next)
    i + 1, u_arr
end

F = constant(F)
u_arr = TensorArray(m + 1)
u_arr = write(u_arr, 1, zeros(n))
i = constant(2, dtype = Int32)
_, u = while_loop(condition, body, [i, u_arr])
u = set_shape(stack(u), (m + 1, n))

uc = readdlm("data_pcl.txt")

# we magnify the loss function by 1e10 so that the optimizer does not stop too early. 
loss = sum((uc - u[:,1:25])^2) * 1e10

sess = Session(); init(sess)
BFGS!(sess, loss)

close("all")
κval = run(sess, κ); plot(xi, κval)
xlabel("\$x\$"); ylabel("\$\\kappa\$")