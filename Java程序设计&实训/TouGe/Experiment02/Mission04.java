package TouGe.Experiment02;
import java.util.Scanner;

public class Mission04 {
    public static void main(String[] args) {
        /***** Begin *****/
        Scanner input = new Scanner(System.in);

        double r = input.nextDouble();
        double h = input.nextDouble();
        input.close();

        double v = 1.0 / 3.0 * Math.PI * Math.pow(r, 2) * h;
        System.out.printf("v=%.2f", v);
        
        /***** End *****/
    }
}
