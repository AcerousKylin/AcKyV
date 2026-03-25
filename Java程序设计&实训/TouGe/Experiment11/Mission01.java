package TouGe.Experiment11;

import java.util.Scanner;
// 最值及其下标

public class Mission01 {
    public static void main(String[] args) {
        //1-Input
        Scanner in = new Scanner(System.in);
        //请在指定位置填写代码。
        /********* Begin *********/
        int[] num = new int[10];
        int max = 0, min = 0;
        for (int i=0; i<10; i++)
        {
            num[i] = in.nextInt();
            if (num[max] < num[i])
                max = i;
            if (num[min] > num[i])
                min = i;
        }
        in.close();
        System.out.println(num[max] + " " + max);
        System.out.println(num[min] + " " + min);
        /********* End *********/
    }
}
