% F4_12.m

close all
clear
clc

I1=imread('A.bmp');
I2=imread('B.bmp');

I3=rgb2gray(I1);
I4=rgb2gray(I2);

I5=imdivide(I3,I4);
I10=imdivide(I4,I3);

I6=im2bw(I1);
I7=im2bw(I2);

I8=imdivide(I6,I7);
I11=imdivide(I7,I6);


subplot(3,2,1),imshow(I3),xlabel('(a) 图A');
subplot(3,2,2),imshow(I4),xlabel('(b) 图B');
subplot(3,2,3),imshow(I5),xlabel('(c) 灰度图象A/B');
subplot(3,2,4),imshow(I8),xlabel('(d) 二值图像A/B');
subplot(3,2,5),imshow(I10),xlabel('(c) 灰度图象B/A');
subplot(3,2,6),imshow(I11),xlabel('(d) 二值图像B/A');

% imwrite(I5,'.\F4_12c.bmp');
% imwrite(I8,'.\F4_12d.bmp');
