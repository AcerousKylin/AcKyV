% F4_24b.m

close all
clear
clc

% -- 设置图片和坐标轴的属性 -------------------------------------------------
fs = 7.5;                                                  % FontSize  : 五号:10.5磅，小五号:9磅，六号:7.5磅
ms = 5;                                                    % MarkerSize: 五号:10.5磅，小五号:9磅，六号:7.5磅
set(gcf,'Units','centimeters','Position',[27 11 6 4.5]);   % 设置图片的位置和大小[left bottom width height],width:height=4:3
set(gca,'FontName','宋体','FontSize',fs);                  % 设置坐标轴(刻度、标签和图例)的字体和字号
set(gca,'Position',[.16 .12 .79 .75]);                     % 设置坐标轴所在的矩形区域在图片中的位置[left bottom width height]
   
img = [0 1 2 3
       1 2 3 1
       2 3 1 0
       3 1 0 2]

axisX = unique(img(:));
%hist(img(:), axisX);
myhist = hist(img(:), axisX)

bar(axisX, myhist, 0.5, 'grouped')
text(axisX-0.1, myhist+0.5, num2str(myhist'));
text(4,-0.5,'\itk');
text(-1.8,6.7,'\ith(k)');
