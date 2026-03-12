close all
clear
clc

I = imread('cameraman.tif');
imshow(I);
figure, imhist(I);
title('source')
figure;
subplot(2, 2, 1), imhist(I, 2);
subplot(2, 2, 2), imhist(I, 5);
subplot(2, 2, 3), imhist(I, 10);
subplot(2, 2, 4), imhist(I);
figure;
subplot(1, 2, 1); imhist(I, 10)
[count, x] = imhist(I, 10);
subplot(1, 2, 2), stem(x, count);