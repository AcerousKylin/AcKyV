package TouGe.Experiment02;
import java.util.Scanner;

public class Mission01 {
    public static void main(String[] args) {
        /***** Begin *****/
        
        Scanner input = new Scanner(System.in);

        double m = input.nextDouble();

        input.close();

        System.out.println(50.0 + 0.4*m);
        
        /***** End *****/
    }
}
