close
clear
clc

% 读入图像
img1 = imread("Sabaru 22B.png");
lighter = 2 * img1;

subplot(1, 2, 1);
imshow(img1);
title("Original");

subplot(1, 2, 2)
imshow(lighter);
title("Lighter");
imwrite(lighter, "Sabaru lighter.png");