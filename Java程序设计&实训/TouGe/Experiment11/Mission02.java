package TouGe.Experiment11;

import java.util.Scanner;
import java.lang.Math;
// 计算均值和方差

public class Mission02 {
    public static void main(String[] args) {
        //1-Input
        Scanner in = new Scanner(System.in);
        //请在指定位置填写代码。
        /********* Begin *********/
        double[] num = new double[100];
        double mean=0.0;
        for (int i=0; i<10; i++)
        {
            num[i] = in.nextInt();
            mean += num[i];
        }
        mean /= 10.0;

        double temp = 0.0;
        for (int i=0; i<10; i++)
            temp += Math.pow(num[i] - mean, 2);
        temp /= 9;
        double deviation = Math.sqrt(temp);
        in.close();
        System.out.printf("%.2f\n", mean);
        System.out.printf("%.2f\n", deviation);
        /********* End *********/
    }
}
