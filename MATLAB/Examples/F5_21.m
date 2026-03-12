% F5_21.m

close all
clear
clc

I=imread('eight.tif');
subplot(3,5,1),imshow(I),xlabel('(a) Ô­Ê¼Í¼Ïñ');
% imwrite(I,'.\F5_21a.bmp');

J=imnoise(I,'salt & pepper',0.3);
subplot(3,5,2),imshow(J),xlabel('(b) ÔëÉùÍ¼Ïñ');
% imwrite(J,'.\F5_21b.bmp');

mask1=[1 0 0 0 1
       0 1 0 1 0
       0 0 1 0 0
       0 1 0 1 0
       1 0 0 0 1];
subplot(3,5,3),imshow(mask1),xlabel('(c-1) ¶Ô½ÇÁÚÓòÄ£°å');

K1=ordfilt2(J,5,mask1);
uint8K1=uint8(K1);
subplot(3,5,4),imshow(uint8K1),xlabel('(c-2) ¶Ô½ÇÁÚÓòÄ£°åÂË²¨');
% imwrite(K1,'.\F5_21c.bmp');

mask2=[0 0 1 0 0
        0 0 1 0 0
        1 1 1 1 1
        0 0 1 0 0
        0 0 1 0 0];
subplot(3,5,5),imshow(mask2),xlabel('(d-1) 4-ÁÚÓòÄ£°å');

K2=ordfilt2(J,5,mask2);
uint8K2=uint8(K2);
subplot(3,5,6),imshow(uint8K2),xlabel('(d-2) 4-ÁÚÓòÄ£°åÂË²¨');
% imwrite(K2,'.\F5_21d.bmp');

mask3=[0 1 0 1 0
       1 0 0 0 1
        0 0 1 0 0
        1 0 0 0 1
         0 1 0 1 0];
subplot(3,5,7),imshow(mask3),xlabel('(e-1) 16ÁÚÓòÄ£°å');

K3=ordfilt2(J,5,mask3);
uint8K3=uint8(K3);
subplot(3,5,8),imshow(uint8K3),xlabel('(e-2) 16ÁÚÓòÄ£°åÂË²¨');
% imwrite(K3,'.\F5_21e.bmp');

mask4=[0 1 0 1 0
        1 0 1 0 1
        0 1 1 1 0
        1 0 1 0 1
        0 1 0 1 0];
subplot(3,5,9),imshow(mask4),xlabel('(f-1) 4-16ÁÚÓòÈÚºÏÄ£°å');

K4=ordfilt2(J,7,mask4);
uint8K4=uint8(K4);
subplot(3,5,10),imshow(uint8K4),xlabel('(f-2) 4-16ÁÚÓòÈÚºÏÄ£°åÂË²¨');
% imwrite(K4,'.\F5_21f.bmp');

mask5=[0 0 1 0 0
              0 1 1 1 0
              1 1 1 1 1
              0 1 1 1 0
              0 0 1 0 0];
subplot(3,5,11),imshow(mask5),xlabel('(g-1) ³ÇÇø¾àÀëÄ£°å');

K5=ordfilt2(J,7,mask5);
uint8K5=uint8(K5);
subplot(3,5,12),imshow(uint8K5),xlabel('(g-2) ³ÇÇø¾àÀëÄ£°åÂË²¨');
% imwrite(K5,'.\F5_21g.bmp');

mask6=[0 1 1 1 0
              1 0 0 0 1
              1 0 1 0 1
              1 0 0 0 1
              0 1 1 1 0];
subplot(3,5,13),imshow(mask6),xlabel('(h-1) Å·Ê½¾àÀëÄ£°å');

K6=ordfilt2(J,7,mask6);
uint8K6=uint8(K6);
subplot(3,5,14),imshow(uint8K6),xlabel('(h-2) Å·Ê½¾àÀëÄ£°åÂË²¨');
% imwrite(K6,'.\F5_21h.bmp');
