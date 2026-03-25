package TouGe.Experiment04;

import java.util.Scanner;

public class Mission04 {
    public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
        int year=sc.nextInt();
        sc.close();
        boolean result;
        
        result = ( (year%400==0) || ( (year%4==0) && (year%100!=0) ) ) ? true : false;
        
        System.out.println(year + "年是否为闰年:" + result);
        
	}
}
