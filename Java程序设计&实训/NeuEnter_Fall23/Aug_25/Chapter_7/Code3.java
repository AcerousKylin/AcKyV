package NeuEnter_Fall23.Aug_25.Chapter_7;

import java.lang.Math;

public class Code3 {
    public static abstract class Shape
    {
        private double area, perimeter;
        private String color;

        public Shape()
        {
            this.area = -1.0;
            this.perimeter = -1.0;
            this.color = "None";
        }

        public String getColor()    {   return this.color;  }

        public Shape(String color)
        {
            this.color = color;
        }

        abstract double getArea();
        abstract double getPer();
        abstract void showAll();
    }

    public static class Rectangle extends Shape
    {
        private double width, height;

        public Rectangle()
        {
            this.width = -1.0;
            this.height = -1.0;
        }

        public Rectangle(double width, double height)
        {
            this.width = width;
            this.height = height;
        }

        public double getArea()
        {
            return this.width * this.height;
        }

        public double getPer()
        {
            return 2 * (this.width + this.height);
        }

        public void showAll()
        {
            System.out.println("It's rectangle " + this.width + " wide and " + this.height + " with " + this.getArea() + " area and " + this.getPer() + " perimeter.");
        }
    }

    public static class Circle extends Shape
    {
        private double radius;

        public Circle()
        {
            this.radius = -1.0;
        }

        public Circle(double radius)
        {
            this.radius = radius;
        }

        public double getArea()
        {
            return Math.PI * Math.pow(this.radius, 2);
        }

        public double getPer()
        {
            return 2 * Math.PI * this.radius;
        }

        public void showAll()
        {
            System.out.println("It's circle whose radius is " + this.radius + " with " + this.getArea() + " area and " + this.getPer() + " perimeter.");
        }
    }

    public static void main(String[] args)
    {
        Rectangle r1 = new Rectangle(3.0, 4.0);
        Circle c1 = new Circle(1.0);
        r1.showAll();
        c1.showAll();
    }
}
