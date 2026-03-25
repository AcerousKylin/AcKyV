package NeuEnter_Fall23.Aug_24;

import java.util.Scanner;

public class Code7 {
    public static void main(String[] args)
    {
        int[] tempArr = new int[100010];
        System.out.println("Please enter a sequence of numbers in one line with space seperates them and a non-digit character at the end:");
        Scanner input = new Scanner(System.in);
        int tLength = 0;
        while (input.hasNextInt())
            tempArr[tLength++] = input.nextInt();
        input.close();

        int [] numbers = new int[tLength];
        for (int i=0; i<tLength; i++)
            numbers[i] = tempArr[i];
        
        for(int i=0; i<tLength/2; i++)
        {
            int temp = numbers[i];
            numbers[i] = numbers[tLength-1-i];
            numbers[tLength-1-i] = temp;
        }

        for (int i=0; i<tLength; i++)
        {
            System.out.print(numbers[i]);
            if (i != tLength-1)
                System.out.print(", ");
        }
    }
}
