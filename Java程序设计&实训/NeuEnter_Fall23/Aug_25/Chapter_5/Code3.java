package NeuEnter_Fall23.Aug_25.Chapter_5;

public class Code3 {
    public static boolean Prime(int num)
    {
        for (int i=2; i<=num/2; i++)
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    public static void main(String[] args)
    {
        int result = -1;
        for (int i=200; i<100010; i++)
        {
            if (Prime(i))
            {
                result = i;
                break;
            }
        }
        System.out.println("The minimum prime number above 200 is: " + result);
    }
}
