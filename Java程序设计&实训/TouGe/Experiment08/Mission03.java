package TouGe.Experiment08;
import java.util.Scanner;

public class Mission03 {
    public static void main(String[] args) {
        /***** Begin *****/
        Scanner input = new Scanner(System.in);
        int negative=0, positive=0, sum=0;
        int count=0;

        while (true)
        {
            int score = input.nextInt();
            if (score > 0)
                positive++;
            else if (score < 0)
                negative++;
            else
                break;
            
            count++;
            sum += score;
        }

        if (count == 0)
            System.out.println("No input");
        else
        {
            System.out.println(positive);
            System.out.println(negative);
            System.out.println(sum);
            System.out.printf("%.2f", (double)sum/count );
        }

        input.close();
        /***** End *****/
    }
}
