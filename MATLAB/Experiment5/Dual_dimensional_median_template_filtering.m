close all
clear
clc

I = imread('eight.tif');
subplot(3, 5, 1), imshow(I), xlabel('(a) 原始图像');

J = imnoise(I, 'salt & pepper', 0.3);
subplot(3, 5, 2), imshow(J), xlabel('(b) 噪声图像');

mask1 = [1 0 0 0 1
         0 1 0 1 0
         0 0 1 0 0
         0 1 0 1 0
         1 0 0 0 1];
subplot(3, 5, 3), imshow(mask1), xlabel('(c-1) 对角邻域模板');

K1 = ordfilt2(J, 5, mask1);
uint8K1 = uint8(K1);
subplot(3 ,5, 4), imshow(uint8K1), xlabel('(c-2) 对角邻域模板滤波');

mask2 = [0 0 1 0 0
         0 0 1 0 0
         1 1 1 1 1
         0 0 1 0 0
         0 0 1 0 0];
subplot(3, 5, 5), imshow(mask2), xlabel('(d-1) 4邻域模板');

K2 = ordfilt2(J, 5, mask2);
uint8K2 = uint8(K2);
subplot(3, 5, 6), imshow(uint8K2), xlabel('(d-2) 4领域模板滤波');

mask3 = [0 1 0 1 0
         1 0 0 0 1
         0 0 1 0 0
         1 0 0 0 1
         0 1 0 1 0];
subplot(3, 5, 7), imshow(mask3), xlabel('(e-1) 16邻域模板');

K3 = ordfilt2(J, 5, mask3);
uint8K3 = uint8(K3);
subplot(3, 5, 8), imshow(uint8K3), xlabel('(e-2) 16领域模板滤波');

mask4 = [0 1 0 1 0
         1 0 1 0 1
         0 1 1 1 0
         1 0 1 0 1
         0 1 0 1 0];
subplot(3, 5, 9), imshow(mask4), xlabel('(f-1) 4-16邻域模板');

K4 = ordfilt2(J, 7, mask3);
uint8K4 = uint8(K4);
subplot(3, 5, 10), imshow(uint8K4), xlabel('(f-2) 4-16领域模板滤波');

mask5 = [0 0 1 0 0
         0 1 1 1 0
         1 1 1 1 1
         0 1 1 1 0
         0 0 1 0 0];
subplot(3, 5, 11), imshow(mask5), xlabel('(g-1) 城区距离模板');

K5 = ordfilt2(J, 7, mask5);
uint8K5 = uint8(K5);
subplot(3, 5, 12), imshow(uint8K5), xlabel('(g-2) 城区距离模板滤波');

mask6 = [0 1 1 1 0
         1 0 0 0 1
         1 0 1 0 1
         1 0 0 0 1
         0 1 1 1 0];
subplot(3, 5, 13), imshow(mask6), xlabel('(h-1) 欧氏距离模板');

K5 = ordfilt2(J, 7, mask6);
uint8K5 = uint8(K5);
subplot(3, 5, 14), imshow(uint8K5), xlabel('(h-2) 欧氏距离模板滤波');