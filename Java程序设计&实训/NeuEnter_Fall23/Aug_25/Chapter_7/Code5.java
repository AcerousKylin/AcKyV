package NeuEnter_Fall23.Aug_25.Chapter_7;

import java.util.Scanner;

public class Code5 {
    public static interface Fruit
    {
        // ...
    }
    
    public static class Apple implements Fruit
    {
        public Apple()
        {
            System.out.println("创建了一个苹果类的对象");
        }
    }

    public static class Banana implements Fruit
    {
        public Banana()
        {
            System.out.println("创建了一个香蕉类的对象");
        }
    }

    public static class Grape implements Fruit
    {
        public Grape()
        {
            System.out.println("创建了一个葡萄类的对象");
        }
    }

    public static class Gardener
    {
        public Gardener(String fruit)
        {
            switch (fruit)
            {
                case "Apple":
                    Apple apple = new Apple();
                    apple.equals(apple);
                    break;
                
                case "Banana":
                    Banana banana = new Banana();
                    banana.equals(banana);
                    break;
                
                case "Grape":
                    Grape grape = new Grape();
                    grape.equals(grape);
                    break;
                default:
                    System.out.println("There's no " + fruit + ".");
            }
        }
    }

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        String fruit = input.next();
        input.close();
        Gardener Kinder = new Gardener(fruit);
        Kinder.equals(Kinder);
    }
}
