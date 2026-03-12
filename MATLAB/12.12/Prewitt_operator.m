close all
clear
clc

I = imread('lena.bmp');
subplot(3, 3, 2), imshow(I), xlabel('(a) 原始图像');

MaskPrewittV = fspecial('prewitt');
MaskPrewittH = MaskPrewittV';

KB1 = filter2(MaskPrewittH, I);
subplot(3, 3, 4), imshow(uint8(KB1)), xlabel('(b) 水平模板滤波图像');
subplot(3, 3, 5), imshow(uint8(double(I) + KB1)), xlabel('(c) 水平模板加法叠加图像');
subplot(3, 3, 6), imshow(uint8(double(I) - KB1)), xlabel('(d) 水平模板减法叠加图像');

KB2 = filter2(MaskPrewittH, I);
subplot(3, 3, 7), imshow(uint8(KB2)), xlabel('(c) 垂直模板滤波图像');
subplot(3, 3, 8), imshow(uint8(double(I) + KB2)), xlabel('(e) 垂直模板加法叠加图像');
subplot(3, 3, 9), imshow(uint8(double(I) - KB2)), xlabel('(g) 垂直模板减法叠加图像');