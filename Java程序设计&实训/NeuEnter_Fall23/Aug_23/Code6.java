package NeuEnter_Fall23.Aug_23;

import java.util.Scanner;

public class Code6 {
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int year = input.nextInt();
        input.close();
        System.out.println( ( (year%4==0 && year%100!=0) || year%400==0 )?"It's a leap year":"It's a common year");
    }
}
