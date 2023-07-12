
clc;
clear;
clf;

//  Declaring constants (SI)

h = 6.626e-34;
c = 3e8;
k = 1.38e-23;

//  Declaring range of wavelengths (m)

x_start = 100e-9;
x_end   = 3000e-9;

x = linspace(x_start, x_end, 1000);


//  Declaring Temperatures (K)

T = [1000 1500 2000 2500];

//  Arrays to store maximum values

P_max = [0 0 0 0];
x_max = [0 0 0 0];


//  Planck's

for i = 1 : 1000
    P1(i) = ((8*%pi*h*c)/(x(i))^5)/(exp((h*c)/(x(i)*k*T(1)))-1);
    if P_max(1) <= P1(i) then
       P_max(1) = P1(i)
       x_max(1) = x(i)
    end
end


for i = 1 : 1000
    P2(i) = ((8*%pi*h*c)/(x(i))^5)/(exp((h*c)/(x(i)*k*T(2))) - 1);
    if P_max(2) <= P2(i) then
       P_max(2) = P2(i)
       x_max(2) = x(i)
    end
end

for i = 1 : 1000
    P3(i) = ((8*%pi*h*c)/(x(i))^5)/(exp((h*c)/(x(i)*k*T(3)))-1);
    if P_max(3) <= P3(i) then
       P_max(3) = P3(i)
       x_max(3) = x(i)
    end
end

for i = 1 : 1000
    P4(i) = ((8*%pi*h*c)/(x(i))^5)/(exp((h*c)/(x(i)*k*T(4)))-1);
    if P_max(4) <= P4(i) then
       P_max(4) = P4(i)
       x_max(4) = x(i)
    end
end



disp("The maximum value of wavelengths at the respective temperatures is (format: temp, wavelength): ");
disp([T(1), x_max(1)],[T(2), x_max(2)],[T(3), x_max(3)],[T(4), x_max(4)]);

//  Defining the inverse temperature array 
T_inv = [0 0 0 0]
for i=1:4
    T_inv(i)=1/T(i)
end

plot2d(T_inv, x_max, -2);
plot(T_inv, x_max);
xlabel("1/Temperature(K)");
ylabel("Wavelength(m)");
title("1/T VS WAVELENGTH")

printf("\n\tSince it is quite evident from the figure that the curve is a straight line,\n\tthe slope can be found by considering any 2 points on the line")

slope_xvalue = T_inv(4) - T_inv(2);
slope_yvalue = x_max(4) - x_max(2);
slope = slope_yvalue/slope_xvalue;

printf("\n\n\tThe value of the displacement constant is: \%lf m-K", slope);
