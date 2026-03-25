package NeuEnter_Fall23.Aug_25.Chapter_7;

import java.util.Random;
// import java.util.Map;
// import java.util.HashMap;

public class Code6 {
    public static class Student
    {
        protected int studentID;
        protected String name;
        protected char gender;
        protected int age;
        protected int final_term;
        protected int mid_term;
        protected Random rdm_sID = new Random();
        protected Random rdm_name = new Random();
        protected Random rdm_age = new Random();
        protected Random rdm_f = new Random();
        protected Random rdm_m = new Random();

        public int getSID() {   return studentID;   }
        public String getName() {   return name;    }
        public char getGender()    {   return gender;  }
        public int getAge() {   return age; }

        public Student()
        {
            final_term = -1;
            mid_term = -1;
        }

        public Student(char gender)
        {
            studentID = (rdm_sID.nextInt(9998) + 1);
            this.name = String.valueOf( (char) ((int)'A' + rdm_name.nextInt(25)+1) ) +
                        String.valueOf( (char) ((int)'a' + rdm_name.nextInt(25)+1) ) +
                        String.valueOf( (char) ((int)'a' + rdm_name.nextInt(25)+1) );
            this.gender = gender;
            age = rdm_age.nextInt(3) + 19;
            final_term = rdm_f.nextInt(41) + 60;
            mid_term = rdm_m.nextInt(41) + 60;
        }

        public double getScore()    {   return -1.0;    }
    }

    public static class English extends Student
    {
        private int speech;
        private Random rdm_spc = new Random();

        public English()
        {
            super();
            speech = -1;
        }

        public English(char gender)
        {
            super(gender);
            this.speech = rdm_spc.nextInt(41) + 60;
        }

        public double getScore()
        {
            return 0.5*this.speech + 0.25*super.mid_term + 0.25*super.final_term;
        }
    }

    public static class Computer extends Student
    {
        private int operation, englishWriting;
        private Random rdm_op = new Random();
        private Random rdm_ew = new Random();

        public Computer()
        {
            super();
            operation = -1;
            englishWriting = -1;
        }

        public Computer(char gender)
        {
            super(gender);
            this.operation = rdm_op.nextInt(41) + 60;
            this.englishWriting = rdm_ew.nextInt(41) + 60;
        }

        public double getScore()
        {
            return 0.4*this.operation + 0.2*this.englishWriting
                    + 0.2*super.mid_term + 0.2*super.final_term;
        }
    }

    public static class Literature extends Student
    {
        private int speech, work;
        private Random rdm_spc = new Random();
        private Random rdm_wrk = new Random();

        public Literature()
        {
            super();
            speech = -1;
            work = -1;
        }

        public Literature(char gender)
        {
            super(gender);
            this.speech = rdm_spc.nextInt(41) + 60;
            this.work = rdm_wrk.nextInt(41) + 60;
        }

        public double getScore()
        {
            return 0.35*this.speech + 0.35*this.work
                    + 0.15*super.mid_term + 0.15*super.final_term;
        }
    }

    public static void main(String[] args)
    {
        Student[] students = new Student[10];

        // Map<String, Character> roster = new HashMap<>();
        // roster.put("Anderson", '男');
        // roster.put("Bolster", '男');
        // roster.put("Cathy", '女');
        // roster.put("Diana", '女');
        // roster.put("Ethon", '男');
        // roster.put("Falcon", '男');
        // roster.put("Granite", '女');
        // roster.put("Hans", '男');
        // roster.put("Ivy", '女');
        // roster.put("Jean", '女');

        Random rdm_dpm = new Random();
        for (int i=0; i<10; i++)
        {
            int department = rdm_dpm.nextInt(3) + 1;
            Random rdm_gdr = new Random();
            switch(department)
            {
                case 1:
                    students[i] = new English( (rdm_gdr.nextBoolean())?'男':'女' );
                    break;
                case 2:
                    students[i] = new Computer( (rdm_gdr.nextBoolean())?'男':'女' );
                    break;
                case 3:
                    students[i] = new Literature( (rdm_gdr.nextBoolean())?'男':'女' );
                    break;
            }
        }

        for (int i=0; i<10; i++)
        {
            System.out.printf("学号：230101%04d 姓名：%3s 性别：%1c 年龄：%2d 综合成绩%.2f\n", students[i].getSID(), students[i].getName(), students[i].getGender(), students[i].getAge(), students[i].getScore());
        }
    }
}
