# Instruction: Complete ____ and add additional codes as needed
using ADCME 
using PyPlot

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

# Below we use the Unicode character for the Greek kappa letter
# κ: kappa
κ = constant(2.0 .+ 1.5 * xi)

# TODO: Construct `A` using `spdiag`
#= 
Hint: the following syntax might be useful 
∘ Concatenate two tensors: [o1;o2]
∘ Elementwise multiplication: o1 .* o2 
∘ Indexing: o1[1], o1[1:3], o1[3:end-1] 
∘ https://kailaix.github.io/ADCME.jl/dev/api/ =#
A = spdiag(n, -1 => ____, 0 => ____, 1 => ____)

function condition(i, u_arr)
    i <= m + 1
end

function body(i, u_arr)
    u = read(u_arr, i - 1)
    # TODO: Compute u_next using u and F[i]
    rhs = ____
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

sess = Session(); init(sess)
u0 = run(sess, u)

plot(LinRange(0, 1, m + 1), u0[:,1])
xlabel("Time")
ylabel("Temperature")
grid("on")
savefig("ex1_reference.png")