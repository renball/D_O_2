close all;
clc;
clear;

FontSize = 10;
filename1 = '/users/q/source/repos/D_O_2/result.txt';
filename2 = '/users/q/source/repos/D_O_2/lap.txt';
Data = importdata( [ filename1 ] );

p   = Data(:, 1);
x   = Data(:, 2);
y   = Data(:, 3);

Data = importdata( [ filename2 ] );
K   = Data(:, 1);
A1   = Data(:, 2);
A2   = Data(:, 3);
A3   = Data(:, 4);
A4   = Data(:, 5);


fig1 = figure('units', 'normalized', 'outerposition', [0 0 1 1]);
subplot(1, 1, 1);
scatter(p, x, 5, 'r','filled');
fig2 = figure('units', 'normalized', 'outerposition', [0 0 1 1]);
subplot(1, 1, 1);
scatter(p, y, 5, 'b','filled');
fig3 = figure('units', 'normalized', 'outerposition', [0 0 1 1]);
subplot(1, 1, 1);
scatter(x, y, 5, 'b','filled');

fig4 = figure('units', 'normalized', 'outerposition', [0 0 1 1]);
subplot(1, 1, 1);
plot(K, A4, 'r','LineWidth', 1);

fig5 = figure('units', 'normalized', 'outerposition', [0 0 1 1]);
subplot(1, 1, 1);
plot(K, A1, K, A2, K, A3, 'r','filled');



hold on;
grid on;
