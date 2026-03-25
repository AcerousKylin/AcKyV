package NeuEnter_Fall23.Aug_30;

public class ByteSizeException extends RuntimeException {
    public ByteSizeException()
        {
            super("输入的数值不是byte类型");
        }
}
