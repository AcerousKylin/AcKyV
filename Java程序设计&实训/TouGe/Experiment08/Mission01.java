package TouGe.Experiment08;
import java.util.Scanner;

public class Mission01 {
    public static int gcd(int m, int n)
    {
        if (n > 0)
            return gcd(n, m % n);
        else
            return m;
    }

    public static void main(String[] args) {
       /***** Begin *****/
        Scanner input = new Scanner(System.in);
        int m = input.nextInt();
        int n = input.nextInt();
        input.close();
        if (m < n)
        {
            int temp = m;
            m = n;
            n = temp;
        }
        System.out.println(gcd(m, n));
        /***** End *****/
    }
}
