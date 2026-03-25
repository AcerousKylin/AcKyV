package TouGe.Experiment11;

import java.util.Scanner;

public class Mission04 {
    public static void main(String[] args) {
        //1-Input
        Scanner in = new Scanner(System.in);
        //请在指定位置填写代码。
        /********* Begin *********/
        int n = in.nextInt();
        int[] num = new int[40];
        for (int i=0; i<n; i++)
            num[i] = in.nextInt();
        for (int i=0; i<n-1; i++)
            System.out.print( (num[i+1]-num[i]) + " ");
        in.close();
        /********* End *********/
    }
}
