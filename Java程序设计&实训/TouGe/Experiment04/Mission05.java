package TouGe.Experiment04;

import java.util.Scanner;

public class Mission05 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("输入：");
        int m=sc.nextInt();
        int n=sc.nextInt();
        sc.close();
        
        System.out.println("输出：");
        
        System.out.println( (m+n)*2 );
        
        System.out.println( (m-n)%3 );
        
        System.out.println( (m-n)/2 + (m+n)*2);
    }
}
