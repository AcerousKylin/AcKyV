package NeuEnter_Fall23.Aug_24;

public class Code3 {
    public static void main(String[] args)
    {
        int[] numbers = {1, 6, 2, 3, 9, 4, 5, 7, 8};
        for (int i=0; i<numbers.length; i++)
        {
            for (int j=i; j<numbers.length-1; j++)
            {
                if (numbers[j] > numbers[j+1])
                {
                    int temp = numbers[j];
                    numbers[j] = numbers[j+1];
                    numbers[j+1] = temp;
                }
            }
        }
        for (int i=0; i<numbers.length; i++)
        {
            System.out.print(numbers[i]);
            if (i!=numbers.length-1)
                System.out.print(", ");
        }
    }
}
