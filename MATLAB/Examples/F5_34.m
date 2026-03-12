% F5_34.m

close all
clear
clc

I=imread('lena.bmp');
subplot(3,3,2),imshow(I),xlabel('(a) 原始图像');
% imwrite(I,'.\F5_34a.bmp');

MaskPrewittV=fspecial('prewitt')
MaskPrewittH=MaskPrewittV'

KB1=filter2(MaskPrewittH,I);
subplot(3,3,4),imshow(uint8(KB1)),xlabel('(b) 水平模板滤波图像');
% imwrite(uint8(KB2),'.\F5_34b.bmp');
subplot(3,3,5),imshow(uint8(double(I)+KB1)),xlabel('(c) 水平模板加法叠加图像');
% imwrite(uint8(double(I)+KB2),'.\F5_34c.bmp');
subplot(3,3,6),imshow(uint8(double(I)-KB1)),xlabel('(d) 水平模板减法叠加图像');
% imwrite(uint8(double(I)-KB2),'.\F5_34d.bmp');

KB2=filter2(MaskPrewittV,I);
subplot(3,3,7),imshow(uint8(KB2)),xlabel('(e) 垂直模板滤波图像');
% imwrite(uint8(KB1),'.\F5_34e.bmp');
subplot(3,3,8),imshow(uint8(double(I)+KB2)),xlabel('(f) 垂直模板加法叠加图像');
% imwrite(uint8(double(I)+KB1),'.\F5_34f.bmp');
subplot(3,3,9),imshow(uint8(double(I)-KB2)),xlabel('(g) 垂直模板减法叠加图像');
% imwrite(uint8(double(I)-KB1),'.\F5_34g.bmp');
