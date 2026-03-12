% E4_13.m

close all
clear
clc

X=uint8([0  0  1  1
         0  0  2  3])
Y=uint8([0  1  0  1
         0  2  0  3])
Z=X&Y
Z1=and(X,Y)
