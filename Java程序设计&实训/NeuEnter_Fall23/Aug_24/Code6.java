package NeuEnter_Fall23.Aug_24;

public class Code6 {
    public static void main(String[] args)
    {
        int[] numbers={18, 25, 7, 36, 13, 2, 89, 63};
        int max=-1, max_index=-1;
        for (int i=0; i<numbers.length; i++)
        {
            if (max < numbers[i])
            {
                max = numbers[i];
                max_index = i;
            }       
        }
        System.out.println("The NO." + max_index + " is the maxium among the array whose value is:" + max);
    }
}
