
clf;
clear;
clc;

x1 = 0;
y1 = 0;
y2 = 0;
yi = 0;

x1 = input("Enter the initial value of x : ");
y1 = input("Enter the initial value of y : ");
xn = input("Enter the final value of x for which y is to be found out: ");
h = input("Enter the width: ");

n = (abs(xn-x1))/h;

for i = 1 : n
    count = 0;
    flag = 0;
    f = (x*y);
    
    y2 = y1 + (h*(x*y));
    
    do
end

