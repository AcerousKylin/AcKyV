close all
clear
clc

I = imread("TOS.jpg");

T = [2, 0, 0;
     0, 2, 0;
     0, 0, 1];
tform = affine2d(T);
J1 = imwarp(I, tform);

T = [1, 0.5, 0;
  0, 1,   0;
  0, 0,   1];
tform = affine2d(T);
J2 = imwarp(I, tform);

T = [1,   0, 0;
     0.5, 1, 0;
     0,   0, 1];
tform = affine2d(T);
J3 = imwarp(I, tform);

T = [1,   0.5, 0;
  0.5, 1,   0;
  0,   0,   1];
tform = affine2d(T);
J4 = imwarp(I, tform);

subplot(2, 2, 1), imshow(J1), xlabel("(a) 原始图像");
subplot(2, 2, 2), imshow(J2), xlabel("(b) 垂直剪切");
subplot(2, 2, 3), imshow(J3), xlabel("(c) 水平剪切");
subplot(2, 2, 4), imshow(J4), xlabel("(d) 水平垂直剪切");