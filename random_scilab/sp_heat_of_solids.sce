
clc;
clear;
clf;

//  Declaring constants (SI)

h = 6.626e-34;
c = 3e8;
k = 1.38e-23;
R = 8.314;

//  Declaring range of Temperature (K)

T_start = 1;        //  Not Declaring T = 0 as the program won't be able to calculate sp. heat as T -> 0
T_end = 1000;       //  High Temperature as compared to the room temperature

T = linspace(T_start, T_end, 1000);

//  Naming: 
//          C_DP:   specific heat as calculated from D-P's Therory
//          C_E:    specific heat as calculated from Einstein's Theory
//          C_D:    specific heat as calculated from Debye's Theory

//  Dulong-Petit's Theory

for i = 1 : 1000
    C_DP(i) = 3*R;
end

//  Einstein's Theory

f_E = 5e12;         //  Einstein's frequency (per second)
T_E = h*f_E/k;      //  Einstein's temperature

for i = 1 : 1000
    C_E(i) = (3*R*((T_E/T(i))^2)*exp(T_E/T(i)))/((exp(T_E/T(i))-1)^2);  
end

//  Debye's Theory

T_D = 345;          //  Debye's temperature

function y = f(x)
    y = (x^4*exp(x))/((exp(x)-1)^2);
endfunction

for i = 1 : 1000
    I(i) = intg(0, (T_D/T(i)), f);
    C_D(i) = 9*R*I(i)/((T_D/T(i))^3);
end

subplot(2,2,1)
plot2d(T,C_DP, 3);
xtitle("D-P");
xlabel("T");
ylabel("Sp. Heat");
xgrid;

subplot(2,2,2)
plot2d(T,C_E, 2);
xtitle("EINSTEIN");
xlabel("T");
ylabel("Sp. Heat");
xgrid;

subplot(2,2,3)
plot2d(T,C_D, 5);
xtitle("DEBYE");
xlabel("T");
ylabel("Sp. Heat");
xgrid;

subplot(2,2,4)
plot2d(T,[C_DP C_E C_D], [3,2,5],leg="D-P@EINSTEIN@DEBYE");
xlabel("T");
ylabel("Sp. Heat");
xtitle("COMPARISON")
xgrid;
