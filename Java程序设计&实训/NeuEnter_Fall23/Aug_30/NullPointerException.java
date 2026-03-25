package NeuEnter_Fall23.Aug_30;

public class NullPointerException extends RuntimeException
{
    public int flag=0;


    public NullPointerException(int flag)
    {
        super("比较中的字符串为空！");
        this.flag = flag;
    }
}
