% F4_21.m

close all
clear
clc

figure
% -- 设置图片和坐标轴的属性 -------------------------------------------------
fs=7.5;                                                  % FontSize  : 五号:10.5磅，小五号:9磅，六号:7.5磅
ms=5;                                                    % MarkerSize: 五号:10.5磅，小五号:9磅，六号:7.5磅
set(gcf,'Units','centimeters','Position',[25 2 13.5 18]);  % 设置图片的位置和大小[left bottom width height],width:height=3:4
set(gca,'FontName','宋体','FontSize',fs);                % 设置坐标轴(刻度、标签和图例)的字体和字号
set(gca,'Position',[0 0 1 1]);                           % 设置坐标轴所在的矩形区域在图片中的位置

% -------------------------------------------------------------------------
% 原始图像数据
Pic=[0 0 0 0 0 0 0
     0 0 1 0 0 0 0
     0 1 1 1 0 0 0
     0 1 1 1 1 0 0
     0 0 1 1 0 0 0
     0 0 0 0 0 0 0
     0 0 0 0 0 0 0];
PicSize=size(Pic);
row=PicSize(1,1);    % 行数
col=PicSize(1,2);    % 列数

% -------------------------------------------------------------------------
% 第1步: 左移
PicLA=Pic;
h=subplot(5,4,1),imshow(PicLA),xlabel('(a1) 原始图像'),ylabel('第1步: 左移');;
% set(h,'position',[0.03 0.6 0.1 0.3])    % 四个参数分别是子图的x位置，y位置，宽度，高度

PicLB=PicLA;
PicLB(:,1)=[];
PicLB=[PicLB zeros(row,1)];
h=subplot(5,4,2),imshow(PicLB),xlabel('(b1) 左移1个像素');

PicLC=PicLA | PicLB;
subplot(5,4,3),imshow(PicLC),xlabel('(c1) a OR b');

PicLD=xor(PicLA,PicLC);
subplot(5,4,4),imshow(PicLD),xlabel('(d1) a XOR c');

% -------------------------------------------------------------------------
% 第2步: 右移
PicRA=Pic;
subplot(5,4,5),imshow(PicRA),xlabel('(a2) 原始图像'),ylabel('第2步: 右移');

PicRB=PicRA;
PicRB(:,col)=[];
PicRB=[zeros(row,1) PicRB];
subplot(5,4,6),imshow(PicRB),xlabel('(b2) 右移1个像素');

PicRC=PicRA | PicRB;
subplot(5,4,7),imshow(PicRC),xlabel('(c2) a OR b');

PicRD=xor(PicRA,PicRC);
subplot(5,4,8),imshow(PicRD),xlabel('(d2) a XOR c');

% -------------------------------------------------------------------------
% 第3步: 上移
PicUA=Pic;
subplot(5,4,9),imshow(PicUA),xlabel('(a3) 原始图像'),ylabel('第3步: 上移');

PicUB=PicUA;
PicUB(1,:)=[];
PicUB=[PicUB;zeros(1,col)];
subplot(5,4,10),imshow(PicUB),xlabel('(b3) 上移1个像素');

PicUC=PicUA | PicUB;
subplot(5,4,11),imshow(PicUC),xlabel('(c3) a OR b');

PicUD=xor(PicUA,PicUC);
subplot(5,4,12),imshow(PicUD),xlabel('(d3) a XOR c');

% -------------------------------------------------------------------------
% 第4步: 下移
PicDA=Pic;
subplot(5,4,13),imshow(PicDA),xlabel('(a4) 原始图像'),ylabel('第4步: 下移');

PicDB=PicDA;
PicDB(row,:)=[];
PicDB=[zeros(1,col);PicDB];
subplot(5,4,14),imshow(PicDB),xlabel('(b4) 下移1个像素');

PicDC=PicDA | PicDB;
subplot(5,4,15),imshow(PicDC),xlabel('(c4) a OR b');

PicDD=xor(PicDA,PicDC);
subplot(5,4,16),imshow(PicDD),xlabel('(d4) a XOR c');

% -------------------------------------------------------------------------
% 第5步: 结果或
subplot(5,4,17),imshow(ones(7)),ylabel('第5步: 结果或');
subplot(5,4,20),imshow(imresize(PicLD | PicRD | PicUD | PicDD,2)),xlabel('(e) 边缘检测结果');
