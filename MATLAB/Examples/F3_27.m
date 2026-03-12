% F3_27.m

close all
clear
clc

I=imread('lena.bmp');
subplot(2,2,1),imshow(I),xlabel('(a) 原始图像');

times=4;
f=imresize(I,1/times);
subplot(2,2,2),imshow(f),xlabel('(b) 失真图像');

% 方法1
g1=interp2(double(f),'linear');
% g1=im2uint8(mat2gray(g1));
subplot(2,2,3),imshow(uint8(g1)),xlabel('(c) 双线性插值(方法1)');

