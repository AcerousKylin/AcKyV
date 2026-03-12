% F5_10.m

close all
clear
clc

I=imread('eight.tif');
subplot(2,3,1),imshow(I),xlabel('(a) 原始图像');

J=imnoise(I,'salt & pepper',0.04);
subplot(2,3,2),imshow(J),xlabel('(b) 噪声图像');

K1=filter2(fspecial('average',3),J);
subplot(2,3,3),imshow(uint8(K1)),xlabel('(c) 3*3模板均值滤波');

K2=filter2(fspecial('average',5),J);
subplot(2,3,4),imshow(uint8(K2)),xlabel('(d) 5*5模板均值滤波');

mask1=[0 1 0
       1 0 1
       0 1 0];
mask1=(1/4)*mask1;
K3=filter2(mask1,J);
subplot(2,3,5),imshow(uint8(K3)),xlabel('(e) 4邻域模板均值滤波');

mask2=[1 1 1
       1 0 1
       1 1 1];
mask2=(1/8)*mask2;
K4=filter2(mask2,J);
subplot(2,3,6),imshow(uint8(K4)),xlabel('(f) 8邻域模板均值滤波');
