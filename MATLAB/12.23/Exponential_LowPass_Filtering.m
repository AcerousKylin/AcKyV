close all
clear
clc

f1xy = imread('eight.tif');
subplot(2, 3, 1), imshow(f1xy), xlabel('(a) 原始图像');

f2xy = imnoise(f1xy, 'salt & pepper', 0.05);
subplot(2, 3, 2), imshow(f2xy), xlabel('(b) 噪声图像');

fxy = double(f2xy);
Fuv = fft2(fxy);
FftShift = fftshift(Fuv);
AbsFftShift = abs(FftShift);
LogAbsFftShift = log(AbsFftShift);
subplot(2, 3, 3), imshow(LogAbsFftShift, []), xlabel('(c) 噪声图像的傅里叶幅度谱对数图像');
colormap("gray"), colorbar;

g = ELPF(FftShift, 30, 2);
subplot(2, 3, 4), imshow(g), xlabel('(d) 滤波图像(n=2, D0 = 30');

g = ELPF(FftShift, 60, 2);
subplot(2, 3, 6), imshow(g), xlabel('(d) 滤波图像(n=2, D0 = 60');