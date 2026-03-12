close all
clear
clc

img = [0 1 2 3
       1 2 3 1
       2 3 1 0
       3 1 0 2];
axisX = unique(img(:));
H = hist(img(:), axisX);
for i=2 : length(H)
    H(i) = H(i) + H(i-1);
end

bar(axisX ,H, 0.5, 'grouped');
text(axisX-0.1, H+0.5, num2str(H'));