package TouGe.Experiment05;
import java.util.Scanner;

public class Mission03 {
    public static void main(String[] args) {
        /***** Begin *****/
        Scanner input = new Scanner(System.in);
        int mark = input.nextInt();
        input.close();
        double score;
        if (mark > 90)
            score = 4.0;
        else if (mark > 80)
            score = 3.5;
        else if (mark > 70)
            score = 3.0;
        else if (mark > 60)
            score = 2.5;
        else
            score = 0;
        
        System.out.println("point=" + score);
        /***** End *****/
    }
}
