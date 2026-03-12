% F5_42.m

close all
clear
clc

I=imread('lena.bmp');
subplot(2,2,1),imshow(I),xlabel('(a) 原始图像');
% imwrite(uint8(I),'.\F5_42a.bmp');

mask=ones(3)/9
J=filter2(mask,I);
subplot(2,2,2),imshow(uint8(J)),xlabel('(b) 3×3模板低通滤波图像');
% imwrite(uint8(J),'.\F5_42b.bmp');

K=double(I)-J;
subplot(2,2,3),imshow(uint8(K)),xlabel('(c) 掩模法滤波图像');
% imwrite(uint8(K),'.\F5_42c.bmp');

Q=find(K<5);
K(Q)=255;
subplot(2,2,4),imshow(uint8(K)),xlabel('(d) 突出对比度图像');
% imwrite(uint8(K),'.\F5_42d.bmp');
