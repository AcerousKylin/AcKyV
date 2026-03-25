package NeuEnter_Fall23.Aug_25.Chapter_6;

public class Code6 {
    public static class Person
    {
        private String name;
        private int age;
        private double height;
        public Person()
        {
            this.name = "None";
            this.age = -1;
            this.height = -1.0;
        }

        public Person(String name, int age, double height)
        {
            this.name = name;
            this.age = age;
            this.height = height;
        }

        public void sayHello()
        {
            System.out.println("Hello, my name is " + this.name + ".");
            System.out.println("I'm " + this.age + " age old and " + this.height + " tall.");
        }
    }
    public static class Constructor
    {
        private Person p1 = new Person("zhangsan", 33, 1.73);
        private Person p2 = new Person("Si Li", 44, 1.74);
        public Constructor()
        {
            p1.sayHello();
            p2.sayHello();
        }
    }

    public static void main(String[] args)
    {
        Constructor c = new Constructor();
        c.equals(c);
    }
}
