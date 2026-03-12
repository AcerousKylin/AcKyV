% F5_13.m

close all
clear
clc

I=imread('liftingbody.png');
subplot(2,3,1),imshow(I),xlabel('(a) 原始图像');

J=imnoise(I,'salt & pepper',0.02);
% J=imnoise(I,'poisson');
subplot(2,3,2),imshow(J),xlabel('(b) 噪声图像');

mask1=[1 2 1
       2 4 2
       1 2 1];
mask1=(1/16)*mask1;
K1=filter2(mask1,J);
subplot(2,3,3),imshow(uint8(K1)),xlabel('(c) 高斯模板均值滤波');

K2=filter2(fspecial('average',3),J);
subplot(2,3,4),imshow(uint8(K2)),xlabel('(d) 3*3模板均值滤波');

mask3=[0 1 0
      1 0 1
       0 1 0];
mask3=(1/4)*mask3;
K3=filter2(mask3,J);
subplot(2,3,5),imshow(uint8(K3)),xlabel('(e) 4邻域模板均值滤波');

mask4=[1 1 1
       1 0 1
       1 1 1];
mask4=(1/8)*mask4;
K4=filter2(mask4,J);
subplot(2,3,6),imshow(uint8(K4)),xlabel('(f) 8邻域模板均值滤波');
