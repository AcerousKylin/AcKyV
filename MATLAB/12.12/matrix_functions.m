close all
clear
clc

A = [4, 15, -45, 10, 6; 56, 0, 17, -45, 0];
% return index, column-prior
disp(find(A >= 10 & A <= 20));

B = [1 3 5 7];
disp(max(B));
disp(min(B));
disp(sum(B));
disp(mean(B));  % 求矩阵各元素均值
C = [1 2 3 4 5];
disp(median(C));    % 求矩阵各元素中位数