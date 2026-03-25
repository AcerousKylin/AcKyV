package NeuEnter_Fall23.Aug_24;

import java.util.Scanner;

public class Class_rabbit {
    public static void main(String[] args)
    {
        long[] rabbit = new long[100010];
        rabbit[0] = rabbit[1] = 1;
        for (int i=2; i<100010; i++)
        {
            rabbit[i] = rabbit[i-1] + rabbit[i-2];
        }
        Scanner input = new Scanner(System.in);
        int month = input.nextInt();
        input.close();
        System.out.println("On the " + month + "th month, we got " + rabbit[month] + " pairs of rabbit");
    }
}
