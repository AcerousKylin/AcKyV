package NeuEnter_Fall23.Aug_24;

import java.util.Scanner;

public class Code8 {
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int[] bucket = new int[100010];
        System.out.println("Please enter a sequence of numbers in one line with space seperates them and a non-digit character at the end:");
        while (input.hasNextInt())
        {
            bucket[input.nextInt()]++;
        }
        input.close();
        for (int i=0; i<100010; i++)
        {
            if (bucket[i] > 0)
                System.out.println(i + " ");
        }
    }
}
