package NeuEnter_Fall23.Aug_30;

public class Practice02 {
    public static void main(String[] args)
    {
        int[] arr = {1, 2, 3, 4, 5};
        int[] target = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

        System.arraycopy(arr, 0, target, 0, 5);
    }
}