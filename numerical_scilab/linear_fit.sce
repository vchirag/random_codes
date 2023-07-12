
clc;
clear;
clf;

n = 0 ;
sum_xx = 0;
sum_x = 0;
sum_y = 0;
sum_xy = 0;

n = input("How many points do you want to enter : ");

disp("Now enter the value of each point ---- ");

disp(" ");

x = []
y = []

for i = 1 : n
    printf("%s %d%s","Enter the value of the",i,"th point : ");
    x(i) = input("Enter x : ");
    y(i) = input("Enter y : ");     
    disp(" ");
end

sum_x = sum(x);
sum_y = sum(y);
sum_xx = sum(x.*x);
sum_xy = sum(x.*y);

a = 0;
b = 0; 

A = [ sum_xx sum_x ; sum_x n ];
B = [ sum_xy ; sum_y ];
X = [ a ; b ] ;

C = inv(A)*B;

a = C(1,1);
b = C(2,1);

disp("  ")
printf('%s%f%s%f' , "The line is y = a*x + b with a = " , a , " and b = " , b);
 
y_fit = [];

disp(" ");

for i = 1:n
    plot(x(i), y(i) , )
end

x = linspace(-1000, 1000, 2002);
y_fit = a*x + b;

plot(x , y_fit);
legend("Fitted Line")
xlabel("Values of X")
ylabel("Values of Y")

