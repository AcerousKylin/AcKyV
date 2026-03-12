% E4_19.m

close all
clear
clc

X=uint8([0  0  1  1
         0  0  2  3])
Y=uint8([0  1  0  1
         0  2  0  3])
Z=xor(X,Y)

