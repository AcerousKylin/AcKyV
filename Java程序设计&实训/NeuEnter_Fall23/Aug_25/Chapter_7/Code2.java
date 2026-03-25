package NeuEnter_Fall23.Aug_25.Chapter_7;

public class Code2 {
    public static class Vehicle
    {
        private String brand, color;
        private double speed;
        
        public String getBrand()    {   return this.brand;  }
        public void setBrand(String brand)  {   this.brand = brand; }
        public String getColor()    {   return this.color;  }
        public void setColor(String color)  {   this.color = color; }
        public double getSpeed()    {   return this.speed;  }
        public void setSpeed(double speed)  {   this.speed = speed; }

        public Vehicle()
        {
            this.brand = "None";
            this.color = "None";
            this.speed = -1;
        }
        
        public Vehicle(String brand, String color)
        {
            this.brand = brand;
            this.color = color;
            this.speed = 0;
        }

        public void run()
        {
            System.out.println("The " + this.color + " car from " + this.brand + " is running at " + this.speed + "km/h");
        }
    }

    public static class Car extends Vehicle
    {
        int load;
        public Car()
        {
            this.load = -1;
        }

        public Car(String brand, String color, int load)
        {
            super(brand, color);
            this.load = load;
        }

        @Override
        public void run()
        {
            System.out.println("The " + this.getColor() + " car " + this.load + " from " + this.getBrand() + " with " + this.load + " load limit is running at " + this.getSpeed() + "km/h");
        }
    }

    public static void main(String[] args)
    {
        Vehicle vhc1 = new Vehicle("benz", "black");
        vhc1.run();
        Car c1 = new Car("Honda", "red", 2);
        c1.run();
    }
}
