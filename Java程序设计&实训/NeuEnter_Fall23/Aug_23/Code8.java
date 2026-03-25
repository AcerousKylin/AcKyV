package NeuEnter_Fall23.Aug_23;

import java.util.Scanner;
import java.lang.Math;

public class Code8 {
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int x=input.nextInt(), y=input.nextInt(), z=input.nextInt();
        input.close();
        int avrg = (x + y + z)/3;
        
        int biasX=Math.abs(x-avrg), biasY=Math.abs(y-avrg), biasZ=Math.abs(z-avrg);
        char mid=(biasX<biasY && biasX<biasZ)?'x': ((biasY<biasX && biasY<biasZ)?'y':'z') ;
        switch (mid)
        {
            case 'x':
                System.out.println( (y<z) ? y+"<"+x+"<"+z : z+"<"+x+"<"+y );
                break;
            case 'y':
                System.out.println( (x<z) ? x+"<"+y+"<"+z : z+"<"+y+"<"+x );
                break;
            case 'z':
                System.out.println( (x<y) ? x+"<"+z+"<"+y : y+"<"+z+"<"+x );
                break;
        }
    }
}
