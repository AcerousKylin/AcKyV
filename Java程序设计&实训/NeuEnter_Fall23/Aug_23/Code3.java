package NeuEnter_Fall23.Aug_23;

public class Code3 {
    public static void main(String[] args)
    {
        double salary=3, ascend=0.06, decadeTotal=0;
        for (int i=0; i<10; i++)
        {
            decadeTotal += salary;
            salary *= 1 + ascend;
        }
        System.out.printf("Salary for a decade later is: %.2f w\n", salary);
        System.out.printf("Total income for the later one decade is: %.2f w", decadeTotal);
    }
}
