% F4_38.m

close all
clear
clc

I=imread('rice.png');
subplot(3,3,1),imshow(I),ylabel('原图像');
subplot(3,3,2),imhist(I);

%方法1-系统函数
J=imadjust(I,[40/255 204/255],[0/255 255/255]);    %图像的最小灰度值为40，最大灰度值为204
%J=imadjust(I);
subplot(3,3,4),imshow(J),ylabel('变换图像(方法1)');
subplot(3,3,5),imhist(J);

% %方法2-编程实现
% %把灰度值范围从[40,204]映射到[0,255]
% f0=0;g0=0;        %分段曲线的第1个点
% f1=40;g1=0;       %分段曲线的第2个点
% f2=204;g2=255;    %分段曲线的第3个点
% f3=255;g3=255;    %分段曲线的第4个点
% subplot(3,3,9),plot([f0,f1,f2,f3],[g0,g1,g2,g3]),xlabel('f'),ylabel('g'),axis([0 255 0 255]);
% 
% %绘制变换曲线
% r1=(g1-g0)/(f1-f0);    %曲线1的斜率
% b1=g0-r1*f0;           %曲线1的截距
% r2=(g2-g1)/(f2-f1);    %曲线2的斜率
% b2=g1-r2*f1;           %曲线2的截距
% r3=(g3-g2)/(f3-f2);    %曲线3的斜率
% b3=g2-r3*f2;           %曲线3的截距
% [m,n]=size(I);
% K=double(I);
% for i=1:m
%     for j=1:n
%         f=K(i,j);
%         g(i,j)=0;
%         if(f>=f0)&(f<=f1)
%             g(i,j)=r1*f+b1;    %曲线1的方程y=r1*x+b1
%         else
%             if (f>=f1)&(f<=f2)
%                 g(i,j)=r2*f+b2;    %曲线2的方程y=r2*x+b2
%             else
%                 if (f>=f2)&(f<=f3)
%                     g(i,j)=r3*f+b3;    %曲线3的方程y=r3*x+b3
%                 end
%             end
%         end
%     end
% end
% subplot(3,3,7),imshow(uint8(g)),ylabel('变换图像(方法2)');
% subplot(3,3,8),imhist(uint8(g));
