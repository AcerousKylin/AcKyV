package NeuEnter_Fall23.Aug_23;

import java.util.Scanner;

public class Code14 {
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        String number = input.nextLine();
        input.close();
        char[] reverse=new char[100010], origin=number.toCharArray();
        for (int i=number.length()-1, j=0; i>=0; i--, j++)
            reverse[j] = origin[i];
        System.out.println(reverse);
    }
}
