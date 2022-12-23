# To implement Lagrange interpolation formuala

# Given (x1, y1), ..., (xn, yn):  points with different x coordinates
#     Then P(x) = sum_1^n (y_i prod_(j!=i)(x-x_j)/(x_i - x_j))
#     is the only polynomical of degree <= n-1 that goes through all of them. 

# Lists to store the x, y coordinates
X = [5, 6 , 9, 11]
Y = [12, 13, 14, 16]
n = len(X)

x = float(input("Enter the value at which the function is to be interpolated: "))

def fracCalc(x, X_i, X_j):
    return ((x - X_j)/(X_i - X_j))

sum_ = 0
prod_ = 1

for i in range (0, n):
    prod_ = 1
    for j in range(0, n):
        if i != j:
            prod_ = prod_ * fracCalc(x, X[i], X[j])
    sum_ += Y[i]*prod_
    
print("The interpolated value is: ", sum_)
