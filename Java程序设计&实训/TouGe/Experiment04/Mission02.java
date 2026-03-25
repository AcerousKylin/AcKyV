package TouGe.Experiment04;

import java.util.Scanner;

public class Mission02 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        sc.close();

        System.out.println("a==b=" + (a == b));
        System.out.println("a!=b=" + (a != b));
        System.out.println("a>b=" + (a>b));
        System.out.println("a<b=" + (a<b));
        System.out.println("b>=a=" + (b >= a));
		System.out.println("b<=a=" + (b <= a));

	}
}
