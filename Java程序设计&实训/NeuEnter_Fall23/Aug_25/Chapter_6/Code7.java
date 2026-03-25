package NeuEnter_Fall23.Aug_25.Chapter_6;

public class Code7 {
    public static class Vehicle
    {
        private String brand, color;
        private double speed;

        public String getColor()    {   return this.color;  }
        public void setColor(String color)  {   this.color = color; }
        public double getSpeed()    {   return this.speed;  }
        public void setSpeed(double speed)  {   this.speed = speed; }

        public Vehicle()
        {
            this.brand = "None";
            this.color = "None";
            this.speed = 0.0;
        }

        public Vehicle(String brand, String color)
        {
            this.brand = brand;
            this.color = color;
            this.speed = 0;
        }

        public void run()
        {
            System.out.println("The " + this.color + "car from " + this.brand + " is running at " + this.speed + "km/h");
        }
    }

    public static class VehicleTest
    {
        Vehicle car1 = new Vehicle("benz", "black");
    }
}
