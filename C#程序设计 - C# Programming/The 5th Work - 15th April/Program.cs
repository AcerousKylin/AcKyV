using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace The_Fifth_Work___15th_April
{
    interface Information
    {
        string Code { get; set; }
        string Name { get; set; }

        void ShowInfo();
    }

    public class Sale : Information
    {
        string code = "";
        string name = "";

        public string Code { get { return code; } set { code = value;} }
        public string Name { get { return name; } set { name = value; } }

        public Sale(string code, string name)
        {
            Code = code;
            Name = name;
        }

        public void ShowInfo()
        {
            Console.WriteLine("Information:");
            Console.WriteLine("Code:" + this.Code);
            Console.WriteLine("Name:" + this.Name);
        }

        public static void ShowInfo(Sale[] sales, int month)
        {
            Console.WriteLine("\n————\t" + month + "月份的商品销售明细如下：");
            foreach (Sale s in sales)
            {
                Console.WriteLine("商品编号：" + s.Code + "\t\t商品名称：" + s.Name);
            }
        }

        public static double SaleMoney<T>(T[] items)
        {
            double sum=0;
            foreach (T item in items)
            {
                sum += Convert.ToDouble(item);
            }
            return sum;
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("—————销售明细—————");

            Sale[] salesJan = { new Sale("T0001", "笔记本电脑"), new Sale("T0002", "手机"),
                                new Sale("T0003", "平板电脑"), new Sale("T0004", "5G手机"),
                                new Sale("T0005", "台式电脑") };
            Sale[] salesFeb = { new Sale("T0006", "机箱"), new Sale("T0007", "显示器") };
            Sale[] salesMar = { new Sale("T0003", "平板电脑"), new Sale("T0004", "5G手机"),
                                new Sale("T0008", "组装电脑"), new Sale("T0009", "充电宝") };

            double[] dbJan = { 3500, 999, 3288, 1999, 12888 };
            double[] dbFeb = { 1499, 1699 };
            double[] dbMar = { 3288, 1999, 1999.9, 49 };

            while (true)
            {
                Console.WriteLine("\n若想退出，请输入q；");
                Console.Write(  "若想查询，请输入要查询的月份（如1、2、3等）：");
                string input = Console.ReadLine();
                if (input == "q")
                {
                    Console.WriteLine("即将退出销售明细查询，请按任意键退出...");
                    break;
                }
                try
                {
                    int month = Convert.ToInt32(input);
                    double sale;
                    if (month < 1 || month > 12)
                    {
                        Console.WriteLine("输入的月份有误！");
                        continue;
                    }
                    if (month == 1)
                    {
                        Sale.ShowInfo(salesJan, month);
                        sale = Sale.SaleMoney<double>(dbJan);
                    }
                    else if (month == 2)
                    {
                        Sale.ShowInfo(salesFeb, month);
                        sale = Sale.SaleMoney<double>(dbFeb);
                    }
                    else if (month == 3)
                    {
                        Sale.ShowInfo(salesMar, month);
                        sale = Sale.SaleMoney<double>(dbMar);
                    }
                    else
                    {
                        Console.WriteLine("\t该月没有销售数据!");
                        continue;
                    }
                    Console.WriteLine("\n" + month + "月商品总销售额：" + sale);
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                }
            }
            Console.ReadLine();
        }
    }
}
