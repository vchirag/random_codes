# Use Romberg integratiion
# To Find: R(3, 3) for intg_1^1.5(x**2*ln(x))

def integrand(x):
    return x**2 * np.log(x)


a = 1
b = 1.5
n = 3

mat = np.zeros([n + 1, n + 1])

mat[0][0] = ((b - a) / 2) * (integrand(a) + integrand(b))

for i in range(1, n + 1):
    mat[i][0] = 0.5 * (mat[i - 1][0])
    h = (1 / (2**i)) * (b - a)

    for j in range(1, 1 + 2**(i - 1)):
        mat[i][0] += h * integrand(a + (2 * j - 1) * h)


for j in range(1, n + 1):
    factor = 1 / (4**j - 1)
    for i in range(j, n + 1):
        mat[i][j] = factor * (4**j * mat[i][j - 1] - mat[i - 1][j - 1])

print(mat)
