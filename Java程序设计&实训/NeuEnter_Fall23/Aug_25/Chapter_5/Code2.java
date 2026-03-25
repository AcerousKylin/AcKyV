package NeuEnter_Fall23.Aug_25.Chapter_5;

import java.util.Scanner;

public class Code2 {
    public static boolean lap(int year)
    {
        if (year % 4 == 0 && year % 100 != 0)
            return true;
        else if (year % 400 == 0)
            return true;
        else
            return false;
    }

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.println("Which year you want to know that it's a lap or common year?");
        int year = input.nextInt();
        input.close();
        System.out.println("It's a " + (lap(year)?"lap":"common") + " year");
    }
}
