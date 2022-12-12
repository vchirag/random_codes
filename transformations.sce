
clc;
clear;
clf;

// The points of a triangle.
// the last entry is redundant for the sake of completiion.
scaling_matrix = [0.3, 0, 0; 0, 0.3, 0; 0, 0 ,1];

//rotation by 90 deg in positive sense;
rotation_matrix = [0, -1, 0 ; 1, 0, 0; 0, 0 , 1];

//translation by (-0.5,2)
translation_matrix = [1, 0, -0.5; 0, 1, 2; 0, 0, 1];
disp(translation_matrix)
x = [-1, 1, 0, -1];
y = [0, 0, 2, 0];

// Shearing Matrix
shearing_matrix = [1, 0.25,0; 0, 1, 0; 0, 0, 1];

original_mat = [x;y;1,1,1,1];
disp(original_mat, "original matrix")

// Plotting the common set of axis, and retrieving the location of origin

plot2d(0,0,1,rect=[-5,-5,5,5]);        
a=gca();
a.x_location = "origin";
a.y_location = "origin";

// Plotting the original triangle
xfpoly(x, y, 2);
legend('Original Figure');

// A sleep counter
sleep(4, "s")


scaled_mat = scaling_matrix * original_mat;
disp(scaled_mat, "scaled matrix");

clf;
plot2d(0, 0, 1, rect=[-5, -5, 5, 5]);        
a=gca();
a.x_location = "origin";
a.y_location = "origin";

// Plotting the scaled triangle
xfpoly(scaled_mat(1, 1:4), scaled_mat(2, 1:4), 3);
legend('Scaled Figure');

sleep(4, "s");


rotated_mat = rotation_matrix*scaled_mat;
disp(rotated_mat, "rotated matrix");

clf;
plot2d(0, 0, 1, rect=[-5, -5, 5, 5]);        
a=gca();
a.x_location = "origin";
a.y_location = "origin";

// Rotated figure
xfpoly(rotated_mat(1, 1:4), rotated_mat(2, 1:4), 4);
legend('Rotated Figure');

sleep(4, "s");


translated_mat = translation_matrix*rotated_mat;
disp(translated_mat, "translated matrix");

clf;
plot2d(0, 0, 1, rect=[-5, -5, 5, 5]);        
a=gca();
a.x_location = "origin";
a.y_location = "origin";

// Translated Figure
xfpoly(translated_mat(1, 1:4), translated_mat(2, 1:4), 5);
legend('Translated Figure');

sleep(4,"s");

sheared_mat = shearing_matrix*translated_mat;
disp(sheared_mat, "sheared matrix");

clf;
plot2d(0, 0, 1, rect=[-5, -5, 5, 5]);        
a=gca();
a.x_location = "origin";
a.y_location = "origin";

// Sheared Figure
xfpoly(sheared_mat(1, 1:4), sheared_mat(2, 1:4), 6);
legend('Sheared Figure');
