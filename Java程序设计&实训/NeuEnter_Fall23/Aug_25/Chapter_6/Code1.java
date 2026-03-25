package NeuEnter_Fall23.Aug_25.Chapter_6;

public class Code1 {
    public static class Point
    {
        private int x, y;
        public Point()
        {
            this.x = 0;
            this.y = 0;
        }
        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
        public void movePoint(int dx, int dy)
        {
            this.x += dx;
            this.y += dy;
        }
        public void showPoint()
        {
            System.out.println("(" + this.x + "," + this.y + ")");
        }
    }

    public static void main(String[] args)
    {
        Point p1=new Point(), p2=new Point(1, -1);
        p1.movePoint(1, -1);
        p2.movePoint(1, -1);
        p1.showPoint();
        p2.showPoint();
    }
}
