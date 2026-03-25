package TouGe.Experiment08;
import java.util.Scanner;
/*
 * 6174黑洞问题，给出四位数字，将其各位按升序和降序排列
 * 降序数（大数）-升序数（小数）= 结果，再将结果进行同样的操作
 * 最后总会得出结果为6174
 */

public class Mission05 {
    public static void main(String[] args) {
        /***** Begin *****/
        Scanner input = new Scanner(System.in);
        int result = input.nextInt();
        input.close();

        while (result != 6174)
        {
            int temp = result;

            int[] units = new int[4];
            for (int i=0; i<4; i++)
            {
                units[i] = temp % 10;
                temp /= 10;
            }

            for (int i=0; i<4; i++)
                for (int j=i; j<4; j++)
                    if (units[i] < units[j])
                    {
                        int _temp = units[i];
                        units[i] = units[j];
                        units[j] = _temp;
                    }
            
            int big=0;
            int small=0;
            for (int i=3; i>=0; i--)
            {
                big += units[3-i] * Math.pow(10, i);
                small += units[i] * Math.pow(10, i);
            }

            result = big - small;

            System.out.printf("%04d-%04d=%04d\n", big, small, result);
        }
        /***** End *****/        
    }
}
