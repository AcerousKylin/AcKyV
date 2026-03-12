% Which includes F4_4 7
close all
clear
clc

I = imread("SS8.jpg");
I1 = imadd(I, 50);
I2 = imadd(I, -50);
I3 = imsubtract(I, -50);
I4 = imsubtract(I, 50);
I5 = immultiply(I, 1.5);
I6 = immultiply(I, 0.5);
I7 = imdivide(I, 0.5);
I8 = imdivide(I, 1.5);

subplot(3, 4, 1), imshow(I), ylabel("原图像");
subplot(3, 4, 2), imshow(I);
subplot(3, 4, 3), imshow(I);
subplot(3, 4, 4), imshow(I);
subplot(3, 4, 5), imshow(I1), xlabel("加法实现"), ylabel("增加亮度后的图像");
subplot(3, 4, 6), imshow(I3), xlabel("减法实现");
subplot(3, 4, 7), imshow(I5), xlabel("乘法实现");
subplot(3, 4, 8), imshow(I7), xlabel("除法实现");
subplot(3, 4, 9), imshow(I2), xlabel("加法实现"), ylabel("减弱亮度后的图像");
subplot(3, 4, 10), imshow(I4), xlabel("减法实现");
subplot(3, 4, 11), imshow(I6), xlabel("乘法实现");
subplot(3, 4, 12), imshow(I8), xlabel("除法实现");