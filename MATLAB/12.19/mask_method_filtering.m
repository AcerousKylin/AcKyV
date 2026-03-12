close all
clear
clc

I = imread("lena.bmp");
subplot(2, 2, 1), imshow(I), xlabel('(a) 原始图像');

mask = ones(3) / 9;
J = filter2(mask, I);
subplot(2, 2, 2), imshow(uint8(J)), xlabel('(b) 3×3模板低通滤波图像');

K = double(I) - J;
subplot(2, 2, 3), imshow(uint8(K)), xlabel('(c) 掩模法滤波图像');

L = find(K < 5);
K(L) = 255;
subplot(2, 2, 4), imshow(uint8(K)), xlabel('(d) 突出对比度图像');