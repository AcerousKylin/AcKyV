package NeuEnter_Fall23.Aug_25.Chapter_6;

public class Code3 {
    public static class Laptop
    {
        char color = ' ';
        int cpu = 0;
        public Laptop()
        {
            this.color = 'w';
            this.cpu = 12400;
        }
        
        public Laptop(char color, int cpu)
        {
            this.color = color;
            this.cpu = cpu;
        }

        public void inquery()
        {
            System.out.println("It's a " + this.color + " laptop with cpu " + this.cpu);
        }
    }

    public static class Test
    {
        public Laptop m1=new Laptop(), m2=new Laptop('b', 13900);
        public Test()
        {
            m1.inquery();
            m2.inquery();
        }
    }

    public static void main(String[] args)
    {
        // 两次输出两次
        Test t1 = new Test();
        t1.m1.inquery();
        t1.m2.inquery();
    }
}
