% F4_7.m

close all
clear
clc

I=imread('rice.png');
I1=imsubtract(I,-50);
I2=imsubtract(I,50);

subplot(1,3,1),imshow(I),xlabel('(a) 原图像');
subplot(1,3,2),imshow(I1),xlabel('(b) 增强亮度后的图像');
subplot(1,3,3),imshow(I2),xlabel('(c) 减弱亮度后的图像');

% imwrite(I1,'.\F4_7b.bmp');
% imwrite(I2,'.\F4_7c.bmp');
