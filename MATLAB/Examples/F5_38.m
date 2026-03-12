% F5_38.m

close all
clear
clc

I=imread('liftingbody.png');
subplot(3,3,2),imshow(I),xlabel('(a) 原始图像');
% imwrite(I,'.\F5_38a.bmp');

MaskSobelV=fspecial('sobel')
MaskSobelH=MaskSobelV'

KB1=filter2(MaskSobelH,I);
subplot(3,3,4),imshow(uint8(KB1)),xlabel('(b) 水平模板滤波图像');
% imwrite(uint8(KB1),'.\F5_38b.bmp');
subplot(3,3,5),imshow(uint8(double(I)+KB1)),xlabel('(c) 水平模板加法叠加图像');
% imwrite(uint8(double(I)+KB1),'.\F5_38c.bmp');
subplot(3,3,6),imshow(uint8(double(I)-KB1)),xlabel('(d) 水平模板减法叠加图像');
% imwrite(uint8(double(I)-KB1),'.\F5_38d.bmp');

KB2=filter2(MaskSobelV,I);
subplot(3,3,7),imshow(uint8(KB2)),xlabel('(e) 垂直模板滤波图像');
% imwrite(uint8(KB2),'.\F5_38e.bmp');
subplot(3,3,8),imshow(uint8(double(I)+KB2)),xlabel('(f) 垂直模板加法叠加图像');
% imwrite(uint8(double(I)+KB2),'.\F5_38f.bmp');
subplot(3,3,9),imshow(uint8(double(I)-KB2)),xlabel('(g) 垂直模板减法叠加图像');
% imwrite(uint8(double(I)-KB2),'.\F5_38g.bmp');
