package NeuEnter_Fall23.Aug_23;

import java.util.Scanner;

public class Code5 {
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int number = input.nextInt();
        input.close();
        if (number%5==0 && number%6==0)
            System.out.println("It can be exactly divided by 5 and 6");
        else if (number%5==0 && number%6!=0)
            System.out.println("It can only be exactly divided by 5");
        else if (number%5!=0 && number%6==0)
            System.out.println("It can only be exactly divided by 6");
        else
            System.out.println("It can be exactly divided either by 5 or 6");
    }
}
