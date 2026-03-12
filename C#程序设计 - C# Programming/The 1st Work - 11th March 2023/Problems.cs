using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace March_11th_2023
{
    internal class Problems
    {
        static void Main(string[] args)
        {

            Problem_1("run");
            Problem_2("run");
            Problem_3("run");
            Problem_4("run");
            Problem_5("run");
        }

        public static void Problem_1(string strings)
        {
            Console.WriteLine(" ----------------------------------------------------------------");
            Console.WriteLine("|                                                                |");
            Console.WriteLine("|                                                                |");
            Console.WriteLine("|                                                                |");
            Console.WriteLine("|                                                                |");
            Console.WriteLine("|   编程词典（珍藏版）                                           |");
            Console.WriteLine("|                                                                |");
            Console.WriteLine("|                                                                |");
            Console.WriteLine("|                                                                |");
            Console.WriteLine("|                     开发团队：明日科技                         |");
            Console.WriteLine("|                                                                |");
            Console.WriteLine("|                                                                |");
            Console.WriteLine("|                                                                |");
            Console.WriteLine("|                                                                |");
            Console.WriteLine("|       copyright    2000——2015  明日科技                      |");
            Console.WriteLine("|                                                                |");
            Console.WriteLine("|                                                                |");
            Console.WriteLine("|                                                                |");
            Console.WriteLine(" ----------------------------------------------------------------");
            //Console.ReadLine();
        }
        public static void Problem_2(string strings)
        {
            int age = 30;
            int age2 = age;
            Console.WriteLine("age:" + age);
            Console.WriteLine("age2:" + age2);
            //Console.Read();
        }

        public static void Problem_3(string strings)
        {
            char first_name = '王';
            Console.WriteLine(first_name);
            //Console.Read();
        }

        public static void Problem_4(string strings)
        {

            int val = int.Parse(Console.ReadLine());
            // int test_entity = 50;
            Console.WriteLine( (val > 50)?"大于50":"不大于50" );
            //Console.Read();
        }

        public static void Problem_5(string strings)
        {
            int sum = 0;
            for (int i = 1; i<=100; i+=2)
                sum += i;

            Console.WriteLine(sum);
            Console.Read();
        }
    }
}
