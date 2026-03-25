package TouGe.Experiment12;

public class Mission01 {
    public static void main(String[] args) {
		/********** Begin **********/
        //创建Dog对象
        Dog a = new Dog();
		//设置Dog对象的属性
		a.name = "五花肉";
        a.color = "棕色";
        a.variety = "阿拉斯加";
		//输出小狗的属性
		System.out.println("名字：" +  a.name   + "，毛色：" +  a.color  + "，品种：" + a.variety );
		
		//调用方法
        a.eat();
		a.run();
		/********** End **********/
		
	}
}

class Dog
        {
            public String name;
            public String color;
            public String variety;
            public void eat()
            {
                System.out.println("啃骨头");
            }

            public void run()
            {
                System.out.println("叼着骨头跑");
            }
        }
/********** End **********/