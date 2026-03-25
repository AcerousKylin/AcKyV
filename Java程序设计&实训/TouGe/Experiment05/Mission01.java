package TouGe.Experiment05;
import java.util.Scanner;

public class Mission01 {
    public static void main(String[] args) {
        /***** Begin *****/
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        if (num % 5 == 0 && num % 7 == 0)
            System.out.println("Yes");
        else
            System.out.println("No");
        input.close();
        /***** End *****/
    }
}
