% Which is F4_2 4 6 7 9 12 13.m

close all
clear
clc

I1 = imread('A.bmp');   I1_b = imbinarize(I1);
I2 = imread('B.bmp');   I2_b = imbinarize(I2);
I3 = rgb2gray(I1);
I4 = rgb2gray(I2);
I5 = imadd(I3, I4);
I6 = imsubtract(I3, I4);
I7 = imsubtract(I4, I3);
I8 = immultiply(I3, I4);
I9 = imdivide(I3, I4);
I10 = imdivide(I4, I3);
I11 = imdivide(I1_b, I2_b);
I12 = imdivide(I2_b, I1_b);

subplot(3, 4, 1), imshow(I3), xlabel('A');
subplot(3, 4, 2), imshow(I4), xlabel('B');
subplot(3, 4, 3), imshow(I5), xlabel('A+B');
subplot(3, 4, 4), imshow(I6), xlabel('A-B');
subplot(3, 4, 5), imshow(I7), xlabel('B-A');
subplot(3, 4, 6), imshow(I8), xlabel('A*B');
subplot(3, 4, 7), imshow(I9), xlabel('A/B');
subplot(3, 4, 8), imshow(I10), xlabel('B/A');
subplot(3, 4, 9), imshow(I11), xlabel('A/B 二值图像');
subplot(3, 4, 10), imshow(I12), xlabel('B/A 二值图像');