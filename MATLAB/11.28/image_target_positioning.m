close all
clear
clc

I = imread("F4_15a_BG.bmp");
J = imread("F4_15b_WT.bmp");
K = imdivide(I, J);

subplot(1, 3, 1), imshow(I), xlabel("(a) 背景图片");
subplot(1, 3, 2), imshow(J), xlabel("(b) 有物体的图像");
subplot(1, 3, 3), imshow(K), xlabel("(c) 相除后的图像");