close all
clear
clc

for i=0:pi/64:2*pi
    pause(0.1)
    hold on
    plot(i, sin(i), 'ro')
    hold on
    plot(2*pi-i, cos(i), 'b*');
end