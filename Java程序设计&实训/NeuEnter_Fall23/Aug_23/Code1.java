package NeuEnter_Fall23.Aug_23;

import java.util.Scanner;

public class Code1 {
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        double profit = input.nextInt(), reward;
        input.close();

        if (profit <= 10.0)
            reward = profit*0.1;
        else if (profit <= 20)
            reward = 1 + (profit-10)*0.075;
        else if (profit <= 40)
            reward = 1 + 0.75 + (profit-20)*0.05;
        else if (profit <= 60)
            reward = 1 + 0.75 + 1 + (profit-40)*0.03;
        else if (profit <= 100)
            reward = 1 + 0.75 + 1 + 0.6 + (profit-60)*0.015;
        else
            reward = 1 + 0.75 + 1 + 0.6 + (profit-100)*0.01;
        System.out.println("The reward is: " + reward + "w");
    }
}
