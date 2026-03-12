close all
clear
clc

I = imread('rice.png');
imshow(I);
I1 = imadjust(I, [0 1], [1 0]);
figure, imshow(I1);