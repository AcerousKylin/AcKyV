package TouGe;

import java.util.Scanner; // 引入Scanner-扫描仪

public class ScannerExams {
	public static void main(String[] args){

		Scanner input = new Scanner(System.in); // 声明扫描仪
        
        int age = input.nextInt(); // 获取键盘输入的整数数据
		input.close(); // 关闭防止阻塞

        System.out.println(age); // print为输出后不换行
        // /r为回车，/n为换行，/t制表符

		/********* End *********/
	}
}