package NeuEnter_Fall23.Aug_23;

import java.util.Scanner;

public class Code9 {
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        String numbers = input.next();
        input.close();

        System.out.println("It's a " + numbers.length() + " figure(s) number");
        System.out.println("The each of the digit is following sequence:");
        char[] cnumbers = numbers.toCharArray();
        for (int i=0; i<numbers.length(); i++)
            System.out.println(cnumbers[i]);
    }
}
