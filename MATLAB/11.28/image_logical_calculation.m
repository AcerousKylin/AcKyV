% Which includes F4_16 17 18 19

close all
clear
clc

I1 = imread('A.bmp');   I1 = rgb2gray(I1);
I2 = imread('B.bmp');   I2 = rgb2gray(I2);
I3 = imbinarize(I1);    %im2bw
I4 = imbinarize(I2);    %im2bw
I5 = I3 & I4;
I6 = I3 | I4;
I7 = ~I3;
I8 = ~I4;
I9 = xor(I3, I4);

subplot(2, 4, 1), imshow(I3), xlabel("(a) A");
subplot(2, 4, 2), imshow(I4), xlabel("(b) B");
subplot(2, 4, 3), imshow(I5), xlabel("(c) A AND B");
subplot(2, 4, 4), imshow(I6), xlabel("(d) A OR B");
subplot(2, 4, 5), imshow(I7), xlabel("(e) NOT A");
subplot(2, 4, 6), imshow(I8), xlabel("(f) NOT B");
subplot(2, 4, 7), imshow(I9), xlabel("(g) ${A}\oplus{B}$", "Interpreter","latex");