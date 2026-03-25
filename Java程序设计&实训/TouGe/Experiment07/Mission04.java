package TouGe.Experiment07;
import java.util.Scanner;

public class Mission04 {
    public static void main(String[] args) {
		/*****start*****/
        Scanner input = new Scanner(System.in);

		System.out.println("欢迎使用中国人民银行ATM取款机");
        
        int current = 1000;
        boolean finish = false;

        while(!finish)
        {
            System.out.println("输入取款金额：");
            int bring = input.nextInt();

            if (bring > current)
            {
                System.out.println("目前余额：" + current + "无法满足您的取款需求！");
                continue;
            }
            else
            {
                current -= bring;
                System.out.println("剩余金额：" + current + "，是否继续（'1'：结束，'2'：继续）：");
                if (input.nextInt() == 1)
                    finish = true;
                else
                    continue;
            }
            System.out.println("取款结束！");
        }

        input.close();
		/*****end*****/
	}
}
