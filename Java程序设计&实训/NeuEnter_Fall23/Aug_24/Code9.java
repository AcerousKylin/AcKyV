package NeuEnter_Fall23.Aug_24;

public class Code9 {
    public static void main(String[] args)
    {
        int[] numbers = {-10, 2, 3, 246, -100, 0, 53};
        int sum=0, max=-1, min=100010;
        for (int i=0; i<numbers.length; i++)
        {
            sum += numbers[i];
            if (numbers[i] < min)
                min = numbers[i];
            if (numbers[i] > max)
                max = numbers[i];
        }
        double avrg = sum / numbers.length;
        System.out.println("The maximum number is " + max + " and the minimum number is " + min + ", the average is " + avrg);
    }
}
