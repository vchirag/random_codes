
clear
clc
clf

// To find the infinite sum : 0.2 + 0.2^2 + 0.2^3 + ... 

printf("To sum : 0.2 + (0.2)^2 + (0.2)^3 + ... ")
disp(' '    ) 

a = 0.2
r = 0.2

S_dummy = string('a/(1-r)')
Sum = evstr(S_dummy)

printf("The sum of the given series is : %f", Sum)


// To evaluate the Fourier coefficients of a given periodic square wave

disp(' ',"To find the fourier coefficients of a square wave ", ' ')
n = 0
a0 = 0

n = int(input("Enter the number of terms that you want : "))    


an = zeros(n)
bn = zeros(n)

L = 2 * %pi

function y = f(x)
    y = squarewave(x)
endfunction

t = (-%pi: 0.01: %pi)'

a0 = (1/2*L)*intg(-%pi, %pi, f, 1e-2)

for i=1 : n
        function b=f1(x, f)
            b=f(x)*cos(i*%pi*x/L);
        endfunction
        function c=f2(x, f)
            c=f(x)*sin(i*%pi*x/L);
        endfunction
        an(i)=(1/L)*intg(-%pi, %pi, f1, 1e-2);
        bn(i)=(1/L)*intg(-%pi, %pi, f2, 1e-2);
end

disp(an, bn, a0)


// axis centered at (0,0)
a=gca(); // Handle on axes entity
a.x_location = "origin";
a.y_location = "origin";

Sum = 0
for i = 1: n  
    Sum = Sum + bn(i)*sin(i*%pi*t/L) 
    plot2d(t, Sum)
end 


plot(t, f(t), 'r')

