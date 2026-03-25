package TouGe.Experiment08;
import java.util.Scanner;

public class Mission04 {
    public static void main(String[] args) {
        /***** Begin *****/
        Scanner input= new Scanner(System.in);
        int n = input.nextInt();
        input.close();
        int daily = 2;
        int total = 0;
        double count = 1;

        // 原题存在歧义和问题
        // 歧义在于没有说明是不超过n的是总数还是当天买的橘子数
        // 问题在于给出的所有测试案例都不符合两种理解方式的答案
        while (daily <= n)
        {
            count++;
            total += daily;
            daily *= 2;
        }

        System.out.printf("%.2f", total*0.4/count);

        /***** End *****/
    }
}
