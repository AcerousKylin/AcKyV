close all
clear
clc

fxy = imread('lena.bmp');
subplot(2, 3, 1), imshow(fxy), xlabel('(a) 原始图像');

fxy = double(fxy);
Fuv = fft2(fxy);
ShiftFuv = fftshift(Fuv);
AbsShiftFuv = abs(ShiftFuv);
LogAbsShiftFuv = log(AbsShiftFuv);
subplot(2, 3, 2), imshow(LogAbsShiftFuv, []), xlabel('(b) 傅里叶幅度谱对数图像');

g = ILPF(ShiftFuv, 5);
subplot(2, 3, 3), imshow(g), xlabel('(c) 滤波图像(\itD0 = 5)');

g = ILPF(ShiftFuv, 12);
subplot(2 ,3 ,4), imshow(g), xlabel('(d) 滤波图像(\itD0 = 12)');

g = ILPF(ShiftFuv, 44);
subplot(2, 3, 5), imshow(g), xlabel('(e) 滤波图像(\itD0 = 44)');

g = ILPF(ShiftFuv, 68);
subplot(2, 3, 6), imshow(g), xlabel('(f) 滤波图像(\itD0 = 68)');