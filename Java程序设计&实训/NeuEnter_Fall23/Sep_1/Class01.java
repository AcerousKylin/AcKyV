package NeuEnter_Fall23.Sep_1;

import java.util.Scanner;

public class Class01
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        String email = input.nextLine();
        boolean flag = true;
        int indexOfAt = -1;

        if (email.contains("@"))
        {
            indexOfAt = email.indexOf('@', 0);
            if (email.indexOf('@', indexOfAt+1) != -1)
                flag = true;
        }
        else
            flag = false;

        if (flag && (!email.endsWith(".com") || email.endsWith(".cn")))
            flag = false;

        if (flag && (email.contains("日本") || email.contains("美国") || email.contains("核污染") || email.contains("乌克兰")))
            flag = false;

        if (flag)
        {
            for (int i=0; i<indexOfAt; i++)
            {
                if (email.charAt(i) < '0' && email.charAt(i) > '9' && email.charAt(i) < 'a' && email.charAt(i) > 'z' && email.charAt(i) < 'A' && email.charAt(i) > 'Z' && email.charAt(i) != '.' && email.charAt(i) !='-' && email.charAt(i) !='_')
                {
                    flag = false;
                    break;
                }    
            }
        }

        if (flag && email.contains(".."))
            flag = false;

        if (!flag)
            System.out.println("Your email are failed to create due to issues in format or allergic words.");
        else
            System.out.println("Your email was created successfully.");
    }
}