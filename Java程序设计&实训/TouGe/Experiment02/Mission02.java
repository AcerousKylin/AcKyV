package TouGe.Experiment02;
import java.util.Scanner;

public class Mission02 {
    public static void main(String[] args) {
        /***** Begin *****/
        Scanner input = new Scanner(System.in);

        int num = input.nextInt();
        int sum=0;
        input.close();

        while (num > 0)
        {
            int unit = num % 10;
            // System.out.println("unit=" + unit);
            sum += unit;
            num /= 10;
        }

        System.out.println("sum=" + sum);
        // System.out.printf("sum=%d\n", sum);

        /***** End *****/
    }
}
