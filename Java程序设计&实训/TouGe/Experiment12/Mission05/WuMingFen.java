package TouGe.Experiment12.Mission05;

public class WuMingFen {
    String theMa;
    int quantity;
    boolean likeSoup;

    public WuMingFen(String m, int q, boolean s)
    {
        theMa = m;
        quantity = q;
        likeSoup = s;
    }

    public WuMingFen(String m, int q)
    {
        theMa = m;
        quantity = q;
    }

    public WuMingFen()
    {
        theMa = "酸辣";
        quantity = 2;
        likeSoup = true;
    }

    public void check()
    {
        System.out.println("面码：" + theMa + "，粉的份量：" + quantity + "两，是否带汤：" + likeSoup);
    }
}
