package NeuEnter_Fall23.Aug_23;

public class Code10 {
    public static void main(String[] args)
    {
        int i, sum = 0;
        for (i=1; i<=33; i++)
        {
            if (i % 3 == 0)
                sum += i;
        }
        i--;
        while (++i <= 66)
        {
            if (i % 3 == 0)
                sum += i;
        }
        
        do
        {
            if (i % 3 == 0)
                sum += i;
        }while(i++<=100);

        // 正确性测试
        // int temp = 0;
        // for (int j=1; j<=100; j++)
        // {
        //     if (j % 3 == 0)
        //         temp += j;
        // }
        // System.out.println(temp);

        System.out.println("The sum of all numebr in 1 to 100 that can be divided by 3 is: " + sum);
    }
}
