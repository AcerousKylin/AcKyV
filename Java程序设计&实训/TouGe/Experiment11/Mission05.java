package TouGe.Experiment11;

import java.util.Scanner;
// 贪心装箱问题

public class Mission05 {
    public static void main(String[] args) {
        //1-Input
        Scanner in = new Scanner(System.in);
        //请在指定位置填写代码。
        /********* Begin *********/
        int n = in.nextInt();
        int[] goods = new int[n+10], boxes = new int [n+10];
        for (int i=0; i<n; i++)
            goods[i] = in.nextInt();
        int box_index = 1, box_num = 0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<box_index; j++)
            {
                if (goods[i] + boxes[j] > 100)
                    box_index++;
                else
                {
                    boxes[j] += goods[i];
                    System.out.println(goods[i] + " " + (j+1) );
                    if (box_num < j+1)
                        box_num = j+1;
                    break;
                }
            }
        }
        in.close();
        System.out.println(box_num);
        /********* End *********/
    }
}
