package TouGe.Experiment05;
import java.util.Scanner;

public class Mission04 {
    public static void main(String[] args) {        
        /***** Begin *****/
        Scanner input = new Scanner(System.in);
        double x = input.nextDouble(), y;
        input.close();
        if (x < 1)
            y = x;
        else if (x< 10)
            y = 2 * x - 1;
        else
            y = 3 * x - 11;

        System.out.println("y=" + y);
        /***** End *****/
    }
}
