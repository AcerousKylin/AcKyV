package NeuEnter_Fall23.Aug_25.Chapter_6;

public class Code2 {
    public static class Rectangle
    {
        private int width=-1, height=-1;

        public Rectangle()
        {
            this.width = 0;
            this.height = 0;
        }

        public Rectangle(int width, int height)
        {
            this.width = width;
            this.height = height;
        }

        public int getArea()
        {
            return this.width * this.height;
        }

        public int getPerimeter()
        {
            return 2 * (width + height);
        }

        public void showRectangle()
        {
            System.out.println("It's a(n) " + this.width + " wide, " + this.height + " high rectangle");
        }
    }

    public static void main(String[] args)
    {
        Rectangle r0 = new Rectangle(3, 4);
        r0.showRectangle();
    }
}
