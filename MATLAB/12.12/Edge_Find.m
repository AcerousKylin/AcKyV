close all
clear
clc

I=imread('liftingbody.png');
subplot(2, 3, 1), imshow(I), xlabel('(a) 原始图像');

BW1=edge(I,'Prewitt');
subplot(2, 3, 2), imshow(BW1), xlabel('(b) Prewitt边缘算子');

BW2=edge(I,'log');
subplot(2, 3, 3), imshow(BW2), xlabel('(c) LOG边缘算子');

BW3 = edge(I,'Sobel');
subplot(2, 3, 4), imshow(BW3), xlabel('(d) Sobel边缘算子');

BW4 = edge(I,'Canny');
subplot(2, 3, 6), imshow(BW4), xlabel('(e) Canny边缘算子');