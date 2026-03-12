close all
clear
clc

I1 = imread("1.png");
I2 = imrotate(I1, -45);
I3 = imrotate(I1, 60);

subplot(1, 3, 1), imshow(I1), xlabel("(a) 原始图像");
subplot(1, 3, 2), imshow(I2), xlabel("(b) 顺时针旋转45度");
subplot(1, 3, 3), imshow(I3), xlabel("(c) 逆时针旋转60度");