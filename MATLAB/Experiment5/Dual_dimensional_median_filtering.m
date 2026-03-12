close all
clear
clc

I=imread('eight.tif');
subplot(2,3,1),imshow(I),xlabel('(a) 原始图像');
% imwrite(I,'.\F5_19a.bmp');

J=imnoise(I,'salt & pepper',0.02);
subplot(2,3,2),imshow(J),xlabel('(b) 噪声图像');
% imwrite(J,'.\F5_19b.bmp');

K1=medfilt2(J,[3,3]);
subplot(2,3,3),imshow(uint8(K1)),xlabel('(c) 3*3模板滤波');
% imwrite(K1,'.\F5_19c.bmp');

K2=medfilt2(J,[5,5]);
subplot(2,3,4),imshow(uint8(K2)),xlabel('(d) 5*5模板滤波');
% imwrite(K2,'.\F5_19d.bmp');

K3=medfilt2(J,[7,7]);
subplot(2,3,5),imshow(uint8(K3)),xlabel('(e) 7*7模板滤波');
% imwrite(K3,'.\F5_19e.bmp');

K4=medfilt2(J,[9,9]);
subplot(2,3,6),imshow(uint8(K4)),xlabel('(f) 9*9模板滤波');
% imwrite(K4,'.\F5_19f.bmp');