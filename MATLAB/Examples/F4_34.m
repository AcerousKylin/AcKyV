% F4_34.m

close all
clear
clc

I=imread('tire.tif');
subplot(2,3,1),imshow(I),xlabel('(a) 原始图像');
subplot(2,3,2),imhist(I),xlabel('(b) 原始图像的灰度统计直方图','position',[90,-160]);

%规定化为只有2个灰度级
J=histeq(I,2);
subplot(2,3,3),imshow(J),xlabel('(c) 规定化为2个灰度级');
subplot(2,3,4),imhist(J),xlabel('(d) 5个灰度级图像的灰度统计直方图','position',[90,-560]);

%规定化为有10个灰度级
K=histeq(I,10);
subplot(2,3,5),imshow(K),xlabel('(e) 规定化为10个灰度级');
subplot(2,3,6),imhist(K),xlabel('(f) 10个灰度级图像的灰度统计直方图','position',[90,-560]');
