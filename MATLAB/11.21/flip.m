close all
clear
clc

I = imread("TOS.jpg");
I1 = flip(I, 2);
I2 = flip(I, 1);

subplot(1, 3, 1), imshow(I), xlabel("(a) 原始图像");
subplot(1, 3, 2), imshow(I1), xlabel("(b) 水平镜像图像");
subplot(1, 3, 3), imshow(I2), xlabel("(c) 垂直镜像图像");