close all
clear
clc

img = [ 0 1 2 3
        1 2 3 1
        2 3 1 0
        3 1 0 2];

axisX = unique(img(:));
H = hist(img(:), axisX);

bar(axisX, H, 0.5, 'grouped');
text(axisX, H+0.25, num2str(H'));
text(4, -0.5, '\itk');
text(-1.8, 6.7, '\ith(k)');