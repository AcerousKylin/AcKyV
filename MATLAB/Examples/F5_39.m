% F5_39.m

close all
clear
clc

I=imread('liftingbody.png');
subplot(2,2,1),imshow(I),xlabel('(a) Ô­Ê¼Í¼Ïñ');
% imwrite(I,'.\F5_39a.bmp');

MaskLog=fspecial('log')
KB=filter2(MaskLog,I);
subplot(2,2,2),imshow(uint8(KB)),xlabel('(b) ÂË²¨Í¼Ïñ');
% imwrite(uint8(KB),'.\F5_39b.bmp');
subplot(2,2,3),imshow(uint8(double(I)+KB)),xlabel('(c) ¼Ó·¨µþ¼ÓÍ¼Ïñ');
% imwrite(uint8(double(I)+KB),'.\F5_39c.bmp');
subplot(2,2,4),imshow(uint8(double(I)-KB)),xlabel('(d) ¼õ·¨µþ¼ÓÍ¼Ïñ');
% imwrite(uint8(double(I)-KB),'.\F5_39d.bmp');
