package NeuEnter_Fall23.Aug_25.Chapter_7;

import javax.swing.RowFilter.ComparisonType;
import javax.swing.plaf.synth.SynthStyle;

public class Code4 {
    public static class ColaEmployee
    {
        public String name;
        private int bir_month;

        public ColaEmployee()
        {
            this.name = "None";
            this.bir_month = -1;
        }
        
        public ColaEmployee(String name, int bir_month)
        {
            this.name = name;
            this.bir_month = bir_month;
        }

        public double getSalary(int month)
        {
            if (bir_month == month)
                return 100.0;
            else
                return 0.0;
        }
    }

    public static class SalariedEmployee extends ColaEmployee
    {
        private double salary_per_month;

        public SalariedEmployee()
        {
            super();
            this.salary_per_month = -1.0;
        }

        public SalariedEmployee(String name, int month, double salary_per_month)
        {
            super(name, month);
            this.salary_per_month = salary_per_month;
        }

        public double getSalary(int month)
        {
            return  salary_per_month + super.getSalary(month);
        }
    }

    public static class HourlyEmployee extends ColaEmployee
    {
        private double salary_per_hour, hours;

        public HourlyEmployee()
        {
            super();
            this.salary_per_hour = -1.0;
            this.hours = -1.0;
        }

        public HourlyEmployee(String name, int month, double sph, double h)
        {
            super(name, month);
            this.salary_per_hour = sph;
            this.hours = h;
        }

        public double getSalary(int month)
        {
            double salary = super.getSalary(month);
            if (hours > 160)
                return salary + (hours - 160.0) * 1.5 * salary_per_hour;
            else
                return salary + hours * salary_per_hour;
        }
    }

    public static class SalesEmployee extends ColaEmployee
    {
        private double sale, bonus_rate;

        public SalesEmployee()
        {
            super();
            this.sale = -1.0;
            this.bonus_rate = -1.0;
        }

        public SalesEmployee(String name, int month, double sale, double bonus_rate)
        {
            super(name, month);
            this.sale = sale;
            this.bonus_rate = bonus_rate;
        }

        public double getSalary(int month)
        {
            return super.getSalary(month) + sale * bonus_rate;
        }
    }

    public static class Company
    {
        public void showSalary(int month, ColaEmployee ce)
        {
            System.out.println(ce.name + "'s salary is " + ce.getSalary(month) + "$.");
        }
    }

    public static void main(String[] args)
    {
        ColaEmployee[] Cola = {new SalariedEmployee("Anderson", 1, 2000),
                                new HourlyEmployee("Kylin", 2, 10.0, 360),
                                new SalesEmployee("Anna", 3, 17250, 0.225)};
        Company Coke = new Company();
        for (int i=0; i<3; i++)
        {
            Coke.showSalary(2, Cola[i]);
        }
    }
}
