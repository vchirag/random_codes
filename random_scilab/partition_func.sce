
clc;
clear;
clf;

//  Declaring constants (SI)

k = 1.38e-23;

// Declaring the range of independent variable (temperature * constants)

x_start = 0;
x_end = 10;

x = linspace(x_start, x_end, 1000);

// Two level systems at energies -E/2 and +E/2
// x = kT/E

function y = f(x)
    y = exp(-1/(2*x)) + exp(1/(2*x));
endfunction


for i = 1 : 1000
    // Partition Function
    Z_level(i) = f(x(i));       
    // Logarithm of Partition Function 
    lnZ_level(i) = log(f(x(i)));
end

for i = 1 : 1000

    // Internal Energy
    U(i) = -(1/2)*tanh(1/(2*x(i)));
    
    // Sp. Heat
    C(i) = ((1/(2*x(i)))^2)*(sech(1/(2*x(i))))^2;
    
    // Entropy
    S(i) = log(2*cosh(1/(2*x(i)))) - (1/(2*x(i)))*tanh(1/(2*x(i)));
end

subplot(3, 2, 1);
plot2d(x, U, 5);
xlabel("$k_BT/\Delta$");
ylabel("$U/\Delta$");
xtitle("Two Level System");
xgrid();

subplot(3, 2, 3);
plot2d(x, S, 5);
xlabel("$k_BT/\Delta$");
ylabel("$S/k_B$");
xtitle("Two Level System");
xgrid();

subplot(3, 2, 5);
plot2d(x, C, 5);
xlabel("$k_BT/\Delta$");
ylabel("$C/k_B$");
xtitle("Two Level System");
xgrid();

// Harmonic Oscillator
// x = kT/hw


function y = f1(x)
    y = 0.5*csch(1/(2*x));
endfunction


for i = 1 : 1000
    // Partition Function
    Z_harm(i) = f1(x(i));       
    // Logarithm of Partition Function 
    lnZ_harm(i) = log(f1(x(i)));
end

for i = 1 : 1000
    
    // Internal Energy
    U1(i) = (1/2)*coth(1/(2*x(i)));
    
    // Specific Heat
    C1(i) = ((1/(2*x(i)))^2)*((csch(1/(2*x(i))))^2);
    
    // Entropy
    S1(i) = (1/(2*x(i)))*coth(1/(2*x(i))) + log((1/2)*csch(1/(2*x(i)))); 
end

subplot(3, 2, 2);
plot2d(x, U1, 2);
xlabel("$k_BT/\hbar \omega$");
ylabel("$U/\Delta$");
xtitle("Quantum Harmonic Oscillator");
xgrid();

subplot(3, 2, 4);
plot2d(x, S1, 2);
xlabel("$k_BT/\hbar \omega$");
ylabel("$S/k_B$");
xtitle("Quantum Harmonic Oscillator");
xgrid();

subplot(3, 2, 6);
plot2d(x, C1, 2);
xlabel("$k_BT/\hbar \omega$");
ylabel("$C/k_B$");
xtitle("Quantum Harmonic Oscillator");
xgrid();

