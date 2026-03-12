close all
clear
clc

I1 = imread("1.png");
I2 = imresize(I1, 0.25);
I3 = imresize(I1, 2);

figure, imshow(I1), xlabel("(a) 原图像");
figure, imshow(I2), xlabel("(b) 缩小后的图像");
figure, imshow(I3), xlabel("(c) 放大后的图像");

subplot(1, 3, 1), imshow(I1), title("原图像");
subplot(1, 3, 2), imshow(I2), title("缩小后的图像");
subplot(1, 3, 3), imshow(I3), title("放大后的图像");