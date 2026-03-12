% F3_15.m

close all
clear
clc

I = imread('lena.bmp');
I1 = flipdim(I,2);
I2 = flipdim(I,1);

subplot(1,3,1),imshow(I),xlabel('(a) Ô­Ê¼Í¼Ïñ');
subplot(1,3,2),imshow(I1),xlabel('(b) Ë®Æ½¾µÏñÍ¼Ïñ');
subplot(1,3,3),imshow(I2),xlabel('(c) ´¹Ö±¾µÏñÍ¼Ïñ');
