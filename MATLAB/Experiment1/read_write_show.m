close all
clear
clc

I = imread('Sabaru 22B.png');
imwrite(I, 'Sabaru 22B.png');
imfinfo('Sabaru 22B.png');

C = [0 2 4 6; 8 10 12 14; 16 18 20 22];
image(C);

imshow(I);