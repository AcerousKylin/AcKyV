% F5_41.m

close all
clear
clc

I=imread('lena.bmp');
subplot(2,2,1),imshow(I),xlabel('(a) Ô­Ê¼Í¼Ïñ');
% imwrite(I,'.\F5_41a.bmp');

mask1=[ 0  -1  0
        -1 5  -1
        0  -1  0]
KB1=filter2(mask1,I);
subplot(2,2,2),imshow(KB1),xlabel('(b) Ä£°å1ÂË²¨Í¼Ïñ');
% imwrite(KB1,'.\F5_41b.bmp');

mask2=[-1 -1 -1
       -1 9  -1
       -1 -1 -1]
KB2=filter2(mask2,I);
subplot(2,2,3),imshow(KB2),xlabel('(c) Ä£°å2ÂË²¨Í¼Ïñ');
% imwrite(KB2,'.\F5_41c.bmp');

mask3=[ 1  -2  1
       -2   5  -2
       1  -2   1]
KB3=filter2(mask3,I);
subplot(2,2,4),imshow(KB3),xlabel('(d) Ä£°å3ÂË²¨Í¼Ïñ');
% imwrite(KB3,'.\F5_41d.bmp');
