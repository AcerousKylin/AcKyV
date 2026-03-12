close all
clear
clc

I=imread('eight.tif');
subplot(2,3,1),imshow(I),xlabel('(a) 原始图像');
% imwrite(I,'.\F5_14a.bmp');

J=imnoise(I,'salt & pepper',0.04);
subplot(2,3,2),imshow(J),xlabel('(b) 噪声图像');
% imwrite(J,'.\F5_14b.bmp');

K1=wiener2(J,[3,3]);
subplot(2,3,3),imshow(uint8(K1)),xlabel('(c) 3*3Wiener滤波');
% imwrite(K1,'.\F5_14c.bmp');

K2=wiener2(J,[5,5]);
subplot(2,3,4),imshow(uint8(K2)),xlabel('(d) 5*5Wiener滤波');
% imwrite(K2,'.\F5_14d.bmp');

K3=wiener2(J,[7,7]);
subplot(2,3,5),imshow(uint8(K3)),xlabel('(e) 7*7Wiener滤波');
% imwrite(K3,'.\F5_14e.bmp');

K4=wiener2(J,[9,9]);
subplot(2,3,6),imshow(uint8(K4)),xlabel('(f) 9*9Wiener滤波');
% imwrite(K4,'.\F5_14f.bmp');
