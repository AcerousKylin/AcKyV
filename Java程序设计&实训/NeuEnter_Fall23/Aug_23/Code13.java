package NeuEnter_Fall23.Aug_23;

public class Code13 {
    public static void main(String[] args)
    {
        int minP = -1;
        for (int i=201; i<400; i++)
        {
            boolean flag = true;
            for (int j=2; j<=i/2; j++)
            {
                if (i % j == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                minP = i;
                break;
            }
        }
        System.out.println("The minimum prime bigger than 200 is " + minP);
    }
}