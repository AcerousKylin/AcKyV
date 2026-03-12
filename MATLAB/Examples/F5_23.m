% F5_23.m
%中值滤波鲜果最好，最小值滤波不能消除噪声，将图像整体变按；最大值滤波不能消除噪声，将图像整体变亮。%
close all
clear
clc

I=imread('eight.tif');
subplot(2,3,1),imshow(I),xlabel('(a) 原始图像');
% imwrite(I,'.\F5_23a.bmp');

J=imnoise(I,'salt & pepper',0.01);
subplot(2,3,2),imshow(J),xlabel('(b) 椒盐噪声图像');
% imwrite(J,'.\F5_23b.bmp');

mask=[0 1 0
      1 1 1
      0 1 0];
subplot(2,3,3),imshow(mask),xlabel('(c) 滤波模板');

K1=ordfilt2(J,3,mask);
uint8K1=uint8(K1);
subplot(2,3,4),imshow(uint8K1),xlabel('(d) 中值滤波图像');
% imwrite(K1,'.\F5_23d.bmp');

K2=ordfilt2(J,1,mask);
uint8K2=uint8(K2);
subplot(2,3,5),imshow(uint8K2),xlabel('(e) 最小值滤波图像');
% imwrite(K2,'.\F5_23e.bmp');

K3=ordfilt2(J,5,mask);
uint8K3=uint8(K3);
subplot(2,3,6),imshow(uint8K3),xlabel('(f) 最大值滤波图像');
% imwrite(K3,'.\F5_23f.bmp');
