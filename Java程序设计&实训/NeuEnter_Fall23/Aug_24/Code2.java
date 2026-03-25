package NeuEnter_Fall23.Aug_24;

public class Code2 {
    public static void main(String[] args)
    {
        char[] NeuEdu = "neusofteducation".toCharArray(), dup = new char[NeuEdu.length];
        for (int i=0; i<NeuEdu.length; i++)
        {
            dup[i] = NeuEdu[i];
        }
        System.out.println(NeuEdu);
    }
}
