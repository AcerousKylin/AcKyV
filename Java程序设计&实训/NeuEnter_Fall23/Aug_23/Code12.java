package NeuEnter_Fall23.Aug_23;

import java.util.Scanner;

public class Code12 {
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int top = input.nextInt(), fatorial=1;
        input.close();
        for (int i=1; i<=top; i++)
            fatorial *= i;
        System.out.println(top + "! is " + fatorial);
    }
}
