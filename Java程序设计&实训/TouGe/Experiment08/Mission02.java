package TouGe.Experiment08;

public class Mission02 {
    public static void main(String[] args) {
        /***** Begin *****/
        double sum = 0;

        for (int i=1; i<625; i++)
        {
            sum += 1 / ( (double)Math.sqrt(i) + (double)Math.sqrt(i+1) );
        }

        System.out.printf("sum=%.6f\n", sum);
        /***** End *****/
    }
}
