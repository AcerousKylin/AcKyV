% F4_13.m

close all
clear
clc

I=imread('rice.png');
I1=imdivide(I,0.5);
I2=imdivide(I,1.5);

subplot(1,3,1),imshow(I),xlabel('(a) 原图像');
subplot(1,3,2),imshow(I1),xlabel('(b) 增强亮度后的图像');
subplot(1,3,3),imshow(I2),xlabel('(c) 减弱亮度后的图像');

% imwrite(I,'.\F4_13a.bmp');
% imwrite(I1,'.\F4_13b.bmp');
% imwrite(I2,'.\F4_13c.bmp');
