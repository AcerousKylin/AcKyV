% F4_15.m

close all
clear
clc

I=imread('F4_15a_BG.bmp');
J=imread('F4_15b_WT.bmp');
K=imdivide(I,J);
Ks=imsubtract(I,J);


subplot(2,2,1),imshow(I),xlabel('(a) 背景图像');
subplot(2,2,2),imshow(J),xlabel('(b) 有物体的图像');
subplot(2,2,3),imshow(K),xlabel('(c) 相除后的图像');
subplot(2,2,4),imshow(Ks),xlabel('(c) 相减后的图像');
% imwrite(K,'.\F4_15c.bmp');
