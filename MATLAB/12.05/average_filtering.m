close all
clear
clc

I = imread("eight.tif");
subplot(2, 3, 1), imshow(I), xlabel("(a) 原始图像");

J = imnoise(I, "salt & pepper", 0.04);
subplot(2, 3, 2)