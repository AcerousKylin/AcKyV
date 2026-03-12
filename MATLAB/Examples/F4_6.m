% F4_6.m

close all
clear
clc

I1=imread('A.bmp');
I2=imread('B.bmp');
I3=rgb2gray(I1);
I4=rgb2gray(I2);
I5=imsubtract(I3,I4);
%I5=imsubtract(I4,I3);

subplot(1,3,1),imshow(I3),xlabel('A');
subplot(1,3,2),imshow(I4),xlabel('B');
subplot(1,3,3),imshow(I5),xlabel('A-B');
%subplot(1,3,3),imshow(I5),xlabel('B-A');
% imwrite(I5,'.\F4_6c.bmp');
