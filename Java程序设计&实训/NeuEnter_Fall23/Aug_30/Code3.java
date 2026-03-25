package NeuEnter_Fall23.Aug_30;

public class Code3 {

    public static int comparationCheck(String a, String b) throws NullPointerException
    {
        int flag = a.compareTo(b);
        try
        {
            if (a == "" || b == "")
                throw new NullPointerException(flag);
        }
        catch (NullPointerException npe)
        {
            throw npe;
        }
        return flag;
    }
    public static void main(String[] args)
    {
        try
        {
            String a="a", b="";
            System.out.println( comparationCheck(a, b) );
        }
        catch (NullPointerException npe)
        {
            throw npe;
        }
    }
}
