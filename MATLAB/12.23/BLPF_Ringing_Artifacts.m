close all
clear
clc

fxy = imread('lena.bmp');
subplot(2, 3, 1), imshow(fxy), xlabel('(a) 原始图像');

fxy = double(fxy);
Fuv = fft2(fxy);
ShiftFuv = fftshift(Fuv);

g = BLPF(ShiftFuv, 30, 1);
subplot(2, 2, 2), imshow(g), xlabel('(b) 滤波图像({\itn}=1, {\itD}0=30))')

g = BLPF(ShiftFuv, 30, 10);
subplot(2, 2, 3), imshow(g), xlabel('(c) 滤波图像({\itn}=10, {\itD}0=30))')

g = BLPF(ShiftFuv, 30, 20);
subplot(2, 2, 4), imshow(g), xlabel('(d) 滤波图像({\itn}=20, {\itD}0=30))')