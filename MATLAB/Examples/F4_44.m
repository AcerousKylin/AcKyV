% F4_44.m

close all
clear
clc

I=imread('rice.png');
subplot(2,3,1),imshow(I),ylabel('原图像');
subplot(2,3,2),imhist(I);

%图像的最小灰度值为40，最大灰度值为204
f0=0;g0=0;        %分段曲线的第1个点
f1=90;g1=30;      %分段曲线的第2个点
f2=150;g2=225;    %分段曲线的第3个点
f3=255;g3=255;    %分段曲线的第4个点
subplot(2,3,6),plot([f0,f1,f2,f3],[g0,g1,g2,g3]),xlabel('f'),ylabel('g'),axis([0 255 0 255]);

%绘制变换曲线
r1=(g1-g0)/(f1-f0);    %曲线1的斜率
b1=g0-r1*f0;           %曲线1的截距
r2=(g2-g1)/(f2-f1);    %曲线2的斜率
b2=g1-r2*f1;           %曲线2的截距
r3=(g3-g2)/(f3-f2);    %曲线3的斜率
b3=g2-r3*f2;           %曲线3的截距
[m,n]=size(I);
 K=I;
for i=1:m
    for j=1:n
        f=K(i,j);
        g(i,j)=0;
        if(f>=f0)&(f<=f1)
            g(i,j)=r1*f+b1;    %曲线1的方程y=r1*x+b1
        else
            if (f>=f1)&(f<=f2)
                g(i,j)=r2*f+b2;    %曲线2的方程y=r2*x+b2
            else
                if (f>=f2)&(f<=f3)
                    g(i,j)=r3*f+b3;    %曲线3的方程y=r3*x+b3
                end
            end
        end
    end
end
subplot(2,3,4),imshow(uint8(g)),ylabel('对比拉伸变换图像');
subplot(2,3,5),imhist(uint8(g));
