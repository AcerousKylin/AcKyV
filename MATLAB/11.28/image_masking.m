% Which is F4_11

close all
clear
clc

I1 = imread("rice.png");
I2 = imread("F4_11b_MASK.bmp");
I3 = immultiply(I1, I2);

subplot(1, 3, 1), imshow(I1), xlabel("(a) 原图像");
subplot(1, 3, 2), imshow(I2), xlabel("(b) 掩模图像");
subplot(1, 3, 3), imshow(I3), xlabel("(c) 掩模操作后的图像");