close all
clear
clc

I = imread('liftingbody.png');
subplot(2, 2, 1), imshow(I), xlabel('(a) 原始图像');

MaskLog = fspecial('log');
KB = filter2(MaskLog, I);
subplot(2, 2, 2), imshow(uint8(KB)), xlabel('(b) 滤波图像');
subplot(2, 2, 3), imshow(uint8(double(I) + KB)), xlabel('(c) 加法叠加图像');
subplot(2, 2, 4), imshow(uint8(double(I) - KB)), xlabel('(d) 减法叠加图像');