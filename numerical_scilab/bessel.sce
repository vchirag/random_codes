
clf;
clear;
clc;

n = 0 ;
n = input("How many polynomials do you want ? : ");

x = [0 : 0.01 : 20]';
i = 0 : n;
y = besselj(i , x);

plot2d(x,y);

xlabel('x');
ylabel('Ja(x)');
xtitle('Some Bessel Functions of the first kind');
