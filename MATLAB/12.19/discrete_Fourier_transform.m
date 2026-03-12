close all
clear
clc

fxy = imread('F6_14_1.jpg');
fxy = rgb2gray(fxy);
subplot(2, 2, 1), imshow(fxy), xlabel('(a) 原始图像');

Fuv = fft2(fxy);
FftShiftAbs = fftshift(abs(Fuv));
subplot(2, 2, 2), imshow(FftShiftAbs, []), xlabel('(b) 傅里叶幅度谱图像'), colormap("gray"), colorbar;

LogFftShiftAbs = log(FftShiftAbs);
subplot(2, 2, 3), imshow(LogFftShiftAbs, []), xlabel('(c) 对称傅里叶幅度谱对数图像'), colormap("gray"), colormap;
subplot(2, 2, 4), mesh(LogFftShiftAbs), axis([0 50 0 50 0 300]), xlabel('(d) 傅里叶幅度谱三维图像'), colormap("gray"), colorbar;