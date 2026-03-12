% F3_16.m

close all
clear
clc

I=imread('lena.bmp');

% T = [  1     0   0
%        0.5   1   0
%        0     0   1]

T = [ 2     0     0
     0    2     0
     0     0     1]

tform = maketform('affine',T);
J1 = imtransform(I,tform);

T = [1  0.5   0
     0   1   0
     0   0   1]
tform = maketform('affine',T);
J2 = imtransform(I,tform);

T = [  1 0.5   0
      0.5   1   0
        0   0   1]
tform = maketform('affine',T);
J3 = imtransform(I,tform);

subplot(2,2,1),imshow(I),xlabel('(a) 原始图像');
subplot(2,2,2),imshow(J1),xlabel('(b) 水平剪切');
subplot(2,2,3),imshow(J2),xlabel('(c) 垂直剪切');
subplot(2,2,4),imshow(J3),xlabel('(d) 水平垂直剪切');
