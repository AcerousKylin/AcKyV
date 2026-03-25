package NeuEnter_Fall23.Aug_30;

public class Code2 {
    public static void main(String[] args)
    {
        Object obj = 10;
        try
        {
            if (!(obj instanceof Byte))
                throw new ByteSizeException();
        } catch (ByteSizeException bse)
        {
            throw bse;
        }
    }
}
