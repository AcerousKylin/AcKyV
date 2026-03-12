% Which includes E4_13 15 17 19

close all
clear
clc

%% 13 15
X = uint8([0 0 1 1 ...
           0 0 2 3]);
Y = uint8([0 1 0 1 ...
           0 2 0 3]);
Z = X&Y;
Z1 = and(X, Y);
Z2 = X|Y;
Z3 = or(X, Y);
disp(Z), disp(Z1);
disp(Z2), disp(Z3);

%% 17
X = uint8([0 1 2 3]);
Y = ~X;
disp(Y);

%% 19
X = uint8([0 0 1 1 ...
           0 0 2 3]);
Y = uint8([0 1 0 1 ...
           0 2 0 3]);
Z = xor(X, Y);
disp(Z);