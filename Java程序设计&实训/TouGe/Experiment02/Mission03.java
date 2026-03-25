package TouGe.Experiment02;
import java.util.Scanner;

public class Mission03 {
    public static void main(String[] args) {
        /***** Begin *****/
        double s, a, r;
        int n;
        Scanner sc = new Scanner(System.in);
        a = sc.nextDouble();
        n = sc.nextInt();
        r = sc.nextDouble();
        sc.close();
        s = a * Math.pow(1 + r, n) - a;
        System.out.printf("s=%.2f\n", s);
        /***** End *****/
    }
}
