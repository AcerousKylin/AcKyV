close all
clear
clc

I = imread('tire.tif');
J = histeq(I);
subplot(2, 2, 1), imshow(I), xlabel('(a) 原始图像');
subplot(2, 2, 2), imhist(I), xlabel('(b) 原始图像的灰度统计直方图', 'Position', [120 -188]);
subplot(2, 2, 3), imshow(J), xlabel('(c) 均衡化图像');
subplot(2, 2, 4), imhist(J), xlabel('(d) 均衡化图像的灰度统计直方图', 'Position', [120 -238]);