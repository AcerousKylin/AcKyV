using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SS6021203558
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "简单客车售票系统";
            string[,] info = new string[10, 5];
            for (int i=1; i<=9; i++)
                for (int j = 1; j <= 4; j++)
                    info[i, j] = "【有票】";

            while(true)
            {
                
                System.Console.Clear();

                System.Console.WriteLine("\n          简单售票系统\n");
                System.Console.WriteLine("\n                   学号：6021203558，姓名：张三");
                System.Console.WriteLine("\n                           输入q并按回车退出系统\n");

                for (int i = 1; i <= 9; i++)
                {
                    for (int j = 1; j <= 4; j++)
                        System.Console.Write(info[i, j]);
                    System.Console.WriteLine();
                }

                System.Console.Write("\n请输入座位行号和列号:");
                string input;
                input = System.Console.ReadLine();
                if (input == "q")
                    break;

                string[] code;

                if (input.Contains(","))
                    code = input.Split(',');
                else if (input.Contains("，"))
                    code = input.Split('，');
                else
                {
                    Console.WriteLine("请使用逗号分隔行号和列号！请按任意键返回...");
                    Console.ReadKey();
                    continue;
                }

                int line = int.Parse(code[0]);
                int column = int.Parse(code[1]);
                if (line < 1 || line > 9 || column < 1 || column > 4)
                {
                    Console.WriteLine("\n请输入行数为1~9、列数为1~4的座位号！请按任意键返回...\n");
                    Console.ReadKey();
                    continue;
                }
                info[line, column] = "【已售】";
            }
        }
    }
}
