package TouGe.Experiment05;
import java.util.Scanner;

public class Mission02 {
    public static void main(String[] args) {
        /***** Begin *****/
        Scanner input = new Scanner(System.in);
        int min=input.nextInt();
        input.close();
        for (int i=0; i<3; i++)
        {
            int temp = input.nextInt();
            if (min > temp)
                min = temp;
        }
        System.out.println("mininum=" + min);
        /***** End *****/
    }
}
