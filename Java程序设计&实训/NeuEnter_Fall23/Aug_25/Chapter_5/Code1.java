package NeuEnter_Fall23.Aug_25.Chapter_5;

import java.util.Scanner;

public class Code1 {
    public static int Factorial(int num)
    {
        if (num == 1 || num == 0)
            return 1;
        else
            return num * Factorial(num-1);
    }

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.println("Type a number that you want its factorial and press enter:");
        int num = input.nextInt();
        int f = Factorial(num);
        input.close();
        System.out.println(num + "'s factorial is " + f);
    }
}
