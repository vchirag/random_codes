
clc;
clear;

n = 0 ;
n = input("How many polynomials do you want ? : ");

i = 0 : n;

x=[-1 : 0.001 : 1]';
y=legendre(i , 1 , x)';

plot2d(x,y,);
xtitle('The first n Legendre Polynomials')
ylabel('Pn(x)');
xlabel('x');
