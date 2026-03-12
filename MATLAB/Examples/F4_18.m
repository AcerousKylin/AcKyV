% F4_18.m

close all
clear
clc

I1=imread('A.bmp');
I2=imread('B.bmp');
I3=im2bw(I1);
I4=~I3;
I5=im2bw(I2);
I6=~I5;

subplot(2,2,1),imshow(I3),xlabel('(a) A');
subplot(2,2,2),imshow(I4),xlabel('(b) NOT A');
subplot(2,2,3),imshow(I5),xlabel('(c) B');
subplot(2,2,4),imshow(I6),xlabel('(d) NOT B');

% imwrite(I1,'.\F4_18a.bmp');
% imwrite(I2,'.\F4_18b.bmp');
% imwrite(I4,'.\F4_18c.bmp');
% imwrite(I6,'.\F4_18d.bmp');
