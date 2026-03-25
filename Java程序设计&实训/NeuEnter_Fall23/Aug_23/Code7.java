package NeuEnter_Fall23.Aug_23;

import java.util.Scanner;

public class Code7 {
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int score = input.nextInt();
        input.close();
        String output;
        if (score < 0 || score > 100)
            output = "Invalid score";
        else if (score < 60)
            output = "E";
        else if (score <= 70)
            output = "D";
        else if (score <= 80)
            output = "C";
        else if (score <= 90)
            output = "B";
        else
            output = "A";
        System.out.println("Your mark is: " + output);
    }
}
