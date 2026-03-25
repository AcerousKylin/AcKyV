package TouGe.Experiment04;

import java.util.Scanner;

public class Mission01 {
    public static void main(String[] args) {

        System.out.println("请输入第一个整数");
        System.out.println("请输入第二个整数");
        
		Scanner sc = new Scanner(System.in);
        int num1 = sc.nextInt(), num2 = sc.nextInt();
        sc.close();
        
        System.out.println("两数相加的结果为：" + (num1+num2));
		System.out.println("两数相减的结果为：" + (num1-num2));
		System.out.println("两数相乘的结果为：" + (num1*num2));
        System.out.println("两数相除的结果为：" + (num1/num2));
        System.out.println("两数取余数的结果为：" + (num1%num2));

	}
}
