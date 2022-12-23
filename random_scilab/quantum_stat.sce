
clc;
clear;
clf;

//  Declaring constants (SI)

h = 6.626e-34;
c = 3e8;
k = 1.38e-23;
R = 8.314;

//  Temperatures (K) at which the distributions are compared

T = [0 100 200];       //  [T1 T2 T3]
            
//  Energy Ranges (Joules)

E_start = 0;
E_end = 2e-19;
E = linspace(E_start, E_end, 1000);

//  Maxwell-Boltzmann Distribution

for i = 1 : 1000
    MB_dist_T1(i) = exp(-E(i)/(k*(T(1)+1e-19)));      //  T = 0 isn't numerically supported 
    MB_dist_T2(i) = exp(-E(i)/(k*T(2)));
    MB_dist_T3(i) = exp(-E(i)/(k*T(3)));
end

subplot(3,1,1)
plot2d(E,[MB_dist_T1, MB_dist_T2, MB_dist_T3], [3,2,5],leg="0K@100K@200K");
xtitle("MAXWELL-BOLTZMANN");
xlabel("Energy(J)");
ylabel("Occupancy");
xgrid;

//  Fermi-Dirac Distribution

E_f = 1.10e-19;         //  Computed from F.Reif. Pg 391 for Copper

for i = 1 : 1000
    FD_dist_T1(i) = 1/(exp((E(i) - E_f)/(k*T(1)))+1);
    FD_dist_T2(i) = 1/(exp((E(i) - E_f)/(k*T(2)))+1);
    FD_dist_T3(i) = 1/(exp((E(i) - E_f)/(k*T(3)))+1);
end

subplot(3,1,2);
plot2d(E,[FD_dist_T1, FD_dist_T2, FD_dist_T3], [3,2,5],leg="0K@100K@200K");
xtitle("FERMI-DIRAC");
xlabel("Energy(J)");
ylabel("Occupancy");
xgrid;


//  Bose-Einstein Distribution

chem = 0;               //  Considering the case when the chemical potential is zero

for i = 1 : 1000
    BE_dist_T1(i) = 1/(exp((E(i))/(k*(T(1)+1e-19)))-1);   //  T = 0 isn't numerically supported 
    BE_dist_T2(i) = 1/(exp((E(i))/(k*T(2)))-1);
    BE_dist_T3(i) = 1/(exp((E(i))/(k*T(3)))-1);
end

subplot(3,1,3);
plot2d(E,[BE_dist_T1, BE_dist_T2, BE_dist_T3], [3,2,5],leg="0K@100K@200K")
xtitle("BOSE-EINSTEIN");
xlabel("Energy (J)");
ylabel("Occupancy");
xgrid;




