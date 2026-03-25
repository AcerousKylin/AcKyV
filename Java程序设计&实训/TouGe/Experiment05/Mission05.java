package TouGe.Experiment05;
import java.util.Scanner;

public class Mission05 {
    public static void main(String[] args) {
        /***** Begin *****/
        Scanner input = new Scanner(System.in);
        double score = input.nextDouble();
        input.close();
        char grade;
        if (score > 100)
            grade = 'Z';
        else if (score > 90)
            grade = 'A';
        else if (score > 80)
            grade = 'B';
        else if (score > 70)
            grade = 'C';
        else if (score > 60)
            grade = 'D';
        else if (score < 0)
            grade = 'z';
        else
            grade = 'E';
        
        if (grade == 'Z' || grade == 'z')
            System.out.println("输入的成绩不符和规则");
        else
            System.out.println("grade=" + grade);
        /***** End *****/
    }
}
