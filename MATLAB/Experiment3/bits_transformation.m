close all
clear
clc

I1 = imread("TOS.jpg");
I2 = rgb2gray(I1);
I3 = imbinarize(I2);

subplot(1, 3, 1), imshow(I1), xlabel("原RGB图像");
subplot(1, 3, 2), imshow(I2), xlabel("灰度图像");
subplot(1, 3, 3), imshow(I3), xlabel("二值图像");