package TouGe.Experiment02;
import java.util.Scanner;

public class Mission05 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("======简易复数运算器======");
        System.out.println("请输入第一个数的实部和虚部(用空格分隔):");
        double a = input.nextDouble();
        double b = input.nextDouble();
        String x = toString(a, b);
        System.out.println("第一个数为:" + x);
        System.out.println("请输入第二个数的实部和虚部(用空格分隔):");
        /***** TODO1 begin *****/
        double c = input.nextDouble();
        double d = input.nextDouble();
        /***** TODO1 end *****/
        String y = toString(c, d);
        System.out.println("第二个数为:" + y);
        double suma = a + c;
        double sumb = b + d;
        String sum = toString(suma, sumb); //和
        double mnsa = a - c;
        double mnsb = b - d;
        String mns = toString(mnsa, mnsb); //差
        /***** TODO2 begin *****/
        double mula = a * c - b * d;
        double mulb = b * c + a * d;
        /***** TODO2 end *****/
        String mul = toString(mula, mulb); //乘
        double t = c * c + d * d;
        double diva = (a * c + b * d) / t;
        double divb = (b * c - a * d) / t;
        String div = toString(diva, divb); //除
        System.out.println("======运算结果如下：");
        System.out.printf("(%s)+(%s)=%s\n", x, y, sum);
        System.out.printf("(%s)-(%s)=%s\n", x, y, mns);
        /***** TODO3 begin *****/
        System.out.printf("(%s)*(%s)=%s\n", x, y, mul);
        System.out.printf("(%s)/(%s)=%s\n", x, y, div);
        /***** TODO3 end *****/

        input.close();
    }

    public static String toString(double a, double b) {
        String x = b > 0 ? String.format("%.2f+%.2fi", a, b) : String.format("%.2f-%.2fi", a, -b);
        return x;
    }
}
