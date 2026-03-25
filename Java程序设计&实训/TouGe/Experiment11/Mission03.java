package TouGe.Experiment11;

import java.util.Scanner;
// 数组内移

public class Mission03 {
    public static void main(String[] args) {
        //1-Input
        Scanner in = new Scanner(System.in);
        //请在指定位置填写代码。
        /********* Begin *********/
        int n = in.nextInt(), bias = in.nextInt();
        int[] num = new int[n+10], temp = new int[bias+10];
        for (int i=0; i<n; i++)
            num[i] = in.nextInt();
        for (int i=n-bias; i<n; i++)
            temp[i-n+bias] = num[i];
        for (int i=0; i<bias; i++)
            System.out.print(temp[i] + " ");
        for (int i=0; i<n-bias; i++)
            System.out.print(num[i] + " ");
        in.close();
        /********* End *********/
    }
}
