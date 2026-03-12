% F4_42.m

close all
clear
clc

I=imread('rice.png');
subplot(2,3,1),imshow(I),ylabel('原图像');
subplot(2,3,2),imhist(I);

%方法1-系统函数
%把灰度值范围[0,255]映射到[255,0]
J=imadjust(I,[0/255 204/255],[255/255 0/255]);
subplot(2,3,4),imshow(J),ylabel('变换图像(方法1)');
subplot(2,3,5),imhist(J);

% %方法2-编程实现
% %把灰度值范围[0,255]映射到[255,0]
% f0=0;g0=255;        %分段曲线的第1个点
% f1=100;g1=155;      %分段曲线的第2个点
% f2=200;g2=55;       %分段曲线的第3个点
% f3=255;g3=0;        %分段曲线的第4个点
% subplot(2,3,6),plot([f0,f1,f2,f3],[g0,g1,g2,g3]),xlabel('f'),ylabel('g'),axis([0 255 0 255]);


