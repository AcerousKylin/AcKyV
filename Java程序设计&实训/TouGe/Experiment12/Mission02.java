package TouGe.Experiment12;

import java.util.Scanner;

public class Mission02 {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String name = sc.next();
		String sex = sc.next();
		/********** Begin **********/
		//分别使用两种构造器来创建Person对象  
		Person a = new Person();
        Person b = new Person(name, sex);
        sc.close();
		/********** End **********/
		
	}
}

class Person
{
    public Person()
    {
        System.out.println("一个人被创建了");
    }

    public Person(String name, String sex)
    {
        System.out.println("姓名：" + name + "，性别：" + sex + "，被创建了");
    }
}

/********** End **********/