% F4_9.m

close all
clear
clc

I1=imread('A.bmp');
I2=imread('B.bmp');
I3=rgb2gray(I1);
I4=rgb2gray(I2);
I5=immultiply(I3,I4);

subplot(1,3,1),imshow(I3),xlabel('A');
subplot(1,3,2),imshow(I4),xlabel('B');
subplot(1,3,3),imshow(I5),xlabel('A*B');

% imwrite(I5,'.\F4_9c.bmp');
