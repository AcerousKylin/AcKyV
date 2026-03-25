package InheritTest.src;

import java.util.Scanner;
// import java.lang.Math;

class Parent
{
    public String name;
    static{
        System.out.println("Parent's static block");
    }

    {
        System.out.println("Parent's construct block");
    }

    public Parent()
    {
        System.out.println("Parent's constructor");
    }

    public Parent(String name)
    {
        this.name = name;
        System.out.println("Parent's name is " + name);
    }
}

class Child extends Parent
{
    public Parent parent;

    static{
        System.out.println("Child's static block");
    }

    {
        System.out.println("Child's construct block");
    }

    public Child()
    {
        System.out.println("Child's constructor");
    }

    public Child(String name)
    {
        this.name = name;
        System.out.println("Child's name is " + name);
        parent = new Parent(name);
    }
}

public class App {
    public static void main(String[] args) {
        Child c;
        System.out.println("class Child claimed");
        c = new Child("Jack");
        System.out.println("Object c instantiate");
    }
}
