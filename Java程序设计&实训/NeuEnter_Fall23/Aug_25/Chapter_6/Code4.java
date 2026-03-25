package NeuEnter_Fall23.Aug_25.Chapter_6;

public class Code4 {
    public static class Student
    {
        private String name, sid;
        public int score;
        public Student(String name, String sid, int score)
        {
            this.name = name;
            this.sid = sid;
            this.score = score;
        }

        public void showStuInfo()
        {
            System.out.printf("%9s %10s %3d\n", sid, name, score);
        }
    }

    public static void stuSort(Student[] students)
    {
        for (int i=0; i<students.length; i++)
        {
            for (int j=i+1; j<students.length; j++)
            {
                if (students[i].score < students[j].score)
                {
                    Student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    }

    public static void main(String[] args)
    {
        Student[] students={new Student("Ropert", "210100001", 99),
                            new Student("Truffles", "210100002", 60),
                            new Student("Unicorn", "210100003", 85)};
        stuSort(students);
        for (int i=0; i<students.length; i++)
        {
            students[i].showStuInfo();
        }
    }
}
