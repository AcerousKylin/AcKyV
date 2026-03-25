package NeuEnter_Fall23.Aug_30;

import java.util.Scanner;

public class Code1 {
    public static void main(String[] args)
    {
        try
        {
            Scanner input = new Scanner(System.in);
            int a=input.nextInt(), b=input.nextInt();
            input.close();
            a = a / b;
        }
        catch(NumberFormatException nfe)
        {
            nfe.printStackTrace();
        }
        catch(ArithmeticException ae)
        {
            ae.printStackTrace();
        }
        finally
        {
            System.out.println("Always being execute");
        }
    }
}
