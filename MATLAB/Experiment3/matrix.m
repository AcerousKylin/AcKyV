close all
clear
clc

b1 = zeros(2, 4);
b2(:) = 1:8;
b3([2 5 8]) = [10 20 30];
b4(:,[2 3]) = ones(2);

disp(b1);
disp(b2);
disp(b3);
disp(b4);