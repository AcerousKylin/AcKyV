close all
clear
clc

I = imread("lena.bmp");
subplot(2, 2, 1), imshow(I), xlabel('(a) 原始图像');

mask1 = [ 0 -1  0
         -1  5 -1
          0 -1  0];
KB1 = filter2(mask1, I);
subplot(2, 2, 2), imshow(KB1), xlabel('(b) 模板1滤波图像');

mask2 = [-1 -1 -1
         -1  9 -1
         -1 -1 -1];
KB2 = filter2(mask2, I);
subplot(2, 2, 3), imshow(KB2), xlabel('(c) 模板2滤波图像');

mask3 = [ 1 -2  1
         -2  5 -2
          1 -2  1];
KB3 = filter2(mask3, I);
subplot(2, 2, 4), imshow(KB3), xlabel('(d) 模板3滤波图像');