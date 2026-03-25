package NeuEnter_Fall23.Aug_23;

import java.util.Scanner;

public class Code2 {
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int grade = input.nextInt();
        String mark;
        input.close();
        switch(grade/10)
        {
            case 10:
            case 9:
                mark = "A";
                break;
            case 8:
                mark = "B";
                break;
            case 7:
                mark = "C";
                break;
            case 6:
                mark = "D";
                break;
            case 5:
            case 4:
            case 3:
            case 2:
            case 1:
            case 0:
                mark = "E";
                break;
            default:
                mark = "Invalid input value";
        }
        System.out.println("Your mark is: " + mark);
    }
}
