% F4_46.m

close all
clear
clc

I=imread('rice.png');
subplot(3,3,1),imshow(I),ylabel('原图像');
subplot(3,3,2),imhist(I),axis([0 255 1 3500]);

%######第1种方法######
%图像的最小灰度值为40，最大灰度值为204
f0=0;g0=100;        %分段曲线的第1个点
f1=100;g1=100;      %分段曲线的第2个点
f2=100;g2=240;      %分段曲线的第3个点
f3=140;g3=240;      %分段曲线的第4个点
f4=140;g4=100;      %分段曲线的第5个点
f5=255;g5=100;      %分段曲线的第6个点
subplot(3,3,6),plot([f0,f1,f2,f3,f4,f5],[g0,g1,g2,g3,g4,g5]),xlabel('f'),ylabel('g'),axis([0 255 0 255]);

%绘制变换曲线
r1=(g1-g0)/(f1-f0);    %曲线1的斜率
b1=g0-r1*f0;           %曲线1的截距
r2=(g2-g1)/(f2-f1);    %曲线2的斜率
b2=g1-r2*f1;           %曲线2的截距
r3=(g3-g2)/(f3-f2);    %曲线3的斜率
b3=g2-r3*f2;           %曲线3的截距
r4=(g4-g3)/(f4-f3);    %曲线4的斜率
b4=g3-r4*f3;           %曲线4的截距
r5=(g5-g4)/(f5-f4);    %曲线5的斜率
b5=g4-r5*f4;           %曲线5的截距
[m,n]=size(I);
K=double(I);
for i=1:m
    for j=1:n
        f=K(i,j);
        g(i,j)=0;
        if(f>=f0)&(f<f1)
            g(i,j)=r1*f+b1;    %曲线1的方程y=r1*x+b1
        else
            if (f>=f1)&(f<f2)
                g(i,j)=r2*f+b2;    %曲线2的方程y=r2*x+b2
            else
                if (f>=f2)&(f<f3)
                    g(i,j)=r3*f+b3;    %曲线3的方程y=r3*x+b3
                else
                    if (f>=f3)&(f<f4)
                        g(i,j)=r4*f+b4;    %曲线4的方程y=r4*x+b4
                    else
                        if (f>=f4)&(f<=f5)
                            g(i,j)=r5*f+b5;    %曲线5的方程y=r5*x+b4
                        end
                    end
                end
            end
        end
    end
end
subplot(3,3,4),imshow(uint8(g)),ylabel('第1种方法');
subplot(3,3,5),imhist(uint8(g));

%######第2种方法######
%图像的最小灰度值为40，最大灰度值为204
f0=0;g0=0;        %分段曲线的第1个点
f1=100;g1=100;       %分段曲线的第2个点
f2=100;g2=240;      %分段曲线的第3个点
f3=140;g3=240;     %分段曲线的第4个点
f4=140;g4=140;      %分段曲线的第5个点
f5=255;g5=255;      %分段曲线的第6个点
subplot(3,3,9),plot([f0,f1,f2,f3,f4,f5],[g0,g1,g2,g3,g4,g5]),xlabel('f'),ylabel('g'),axis([0 255 0 255]);
% 
%绘制变换曲线
r1=(g1-g0)/(f1-f0);    %曲线1的斜率
b1=g0-r1*f0;           %曲线1的截距
r2=(g2-g1)/(f2-f1);    %曲线2的斜率
b2=g1-r2*f1;           %曲线2的截距
r3=(g3-g2)/(f3-f2);    %曲线3的斜率
b3=g2-r3*f2;           %曲线3的截距
r4=(g4-g3)/(f4-f3);    %曲线4的斜率
b4=g3-r4*f3;           %曲线4的截距
r5=(g5-g4)/(f5-f4);    %曲线5的斜率
b5=g4-r5*f4;           %曲线5的截距
[m,n]=size(I);
K=double(I);
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
                else
                    if (f>=f3)&(f<=f4)
                        g(i,j)=r4*f+b4;    %曲线4的方程y=r4*x+b4
                    else
                        if (f>=f4)&(f<=f5)
                            g(i,j)=r5*f+b5;    %曲线5的方程y=r5*x+b4
                        end
                    end
                end
            end
        end
    end
end
subplot(3,3,7),imshow(uint8(g)),ylabel('第2种方法');
subplot(3,3,8),imhist(uint8(g)),axis([0 255 1 3500]);
