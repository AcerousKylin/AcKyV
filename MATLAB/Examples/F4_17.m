% F4_17.m

close all
clear
clc

I1=imread('A.bmp');
I2=imread('B.bmp');
I3=im2bw(I1);
I4=im2bw(I2);
I5=I3|I4;

subplot(1,3,1),imshow(I3),xlabel('(a) A');
subplot(1,3,2),imshow(I4),xlabel('(b) B');
subplot(1,3,3),imshow(I5),xlabel('(c) A OR B');

% imwrite(I1,'.\F4_17a.bmp');
% imwrite(I2,'.\F4_17b.bmp');
% imwrite(I5,'.\F4_17c.bmp');
