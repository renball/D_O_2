close all;
clc;
clear;

FontSize = 10;
filename1 = '/users/q/source/repos/D_O_2/result.txt';


Data = importdata( [ filename1 ] );
p   = Data(:, 1);
x   = Data(:, 2);
y   = Data(:, 3);


fig1 = figure('units', 'normalized', 'outerposition', [0 0 1 1]);
subplot(1, 1, 1);
scatter3(x, y, p, 'b','filled');
ylim([-6.28 6.28]);
xlim([-6.28 6.28]);
fig2 = figure('units', 'normalized', 'outerposition', [0 0 1 1]);
plot3(x,y,p);
hold on;
grid on;
