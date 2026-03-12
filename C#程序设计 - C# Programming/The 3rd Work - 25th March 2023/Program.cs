using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace The_Third_Work___25th_March
{
    internal class Program
    {
        public static void SplitUnit(string input, out string unit, out float num)
        {
            unit = Regex.Replace(input, "[0-9]", "", RegexOptions.IgnoreCase);
            num = float.Parse( Regex.Replace(input, unit, "", RegexOptions.IgnoreCase) );
        }

        public static string CombineUnit(string unit, float num)
        {
            return num.ToString() + unit;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("库存盘点信息如下：");

            cStockInfo csi1 = new cStockInfo();
            csi1.TradeCode = "TJRA001";
            csi1.FullName = "空调";
            csi1.TradeType = "TYPE-1";
            csi1.Standard = "2匹";
            csi1.Unit = "台";
            csi1.Produce = "天津";
            csi1.Quantity = 200;
            csi1.Price = 2000;
            csi1.AveragePrice = 2500;
            csi1.SalePrice = 3000;
            csi1.Check = 200;
            csi1.UpperLimit = 800;
            csi1.LowerLimit = 200;
            csi1.ShowInfo();
                
            cStockInfo csi2 = new cStockInfo();
            csi2.TradeCode = "TJRA002";
            csi2.FullName = "空调";
            csi2.TradeType = "TYPE-2";
            csi2.Standard = "1.5匹";
            csi2.Unit = "台";
            csi2.Produce = "天津";
            csi2.Quantity = 300;
            csi2.Price = 3000;
            csi2.AveragePrice = 3500;
            csi2.SalePrice = 4000;
            csi2.Check = 290;
            csi2.ShowInfo();

            Console.WriteLine("以上是商品1、2的信息，按任意键继续......");
            Console.ReadLine();



            cStockInfo csi3 = new cStockInfo();
            Boolean error = true;

            Console.WriteLine("接下来，请根据提示输入商品3的产品信息......");
            Console.WriteLine("");



            // 输入商品编号
            
            
            while (error)
            {
                Console.WriteLine("请输入纯数字商品编号，编号应在[1, 999]范围内：");
                int i_temp;
                string s_temp = Console.ReadLine();
                Boolean check = int.TryParse(s_temp, out i_temp);
                if (check)
                {
                    if (i_temp <= 1 || i_temp >= 999)
                    {
                        Console.WriteLine("错误！输入超出范围，请重新输入！");
                        continue;
                    }
                    else if (i_temp == 1 || i_temp == 2)
                    {
                        Console.WriteLine("请注意，您正在输入冲突的编号，是否重新输入？1");
                        Console.WriteLine("输入1：重新输入，输入其他：不了，继续");
                        int quit;
                        int.TryParse(Console.ReadLine(), out quit);
                        if (quit == 1)
                            continue;
                        if (quit == 0)
                            break;
                    }
                }
                else
                {
                    Console.WriteLine("错误！注意不要输入除数字外的内容，请重新输入！");
                    continue;
                }
                csi3.TradeCode = "TJRA" + i_temp.ToString("D3");
                error = false;
            }
            Console.WriteLine("商品编号输入成功");
            Console.WriteLine("");



            // 输入单位
            Console.WriteLine("请输入单位全称：");
            csi3.FullName = Console.ReadLine();
            Console.WriteLine("单位输入成功");
            Console.WriteLine("");



            // 输入商品规格
            while (true)
            {
                string unit;
                float scale;
                SplitUnit(csi3.Standard, out unit, out scale);  
                Console.WriteLine("即将输入商品规格，当前商品规格为：" + csi3.Standard);
                Console.WriteLine("若不更改单位，请直接输入规格；若要更改单位，请输入单位（汉字&英文）");
                string s_temp = Console.ReadLine();

                float f_temp = scale;
                if (!float.TryParse(s_temp, out f_temp))
                    unit = s_temp;
                else
                    scale = f_temp;
                csi3.Standard = CombineUnit(unit, scale);
                Console.WriteLine("更改成功，当前商品规格为：" + csi3.Standard);

                Console.WriteLine("还要继续更改商品规格吗？输入1：继续修改，输入其他：不了");
                int quit;
                int.TryParse(Console.ReadLine(), out quit);
                if (quit == 1)
                    continue;
                else
                    break;
            }
            Console.WriteLine("商品规格输入成功");
            Console.WriteLine("");



            // 输入库存数量
            while (true)
            {
                Console.WriteLine("请输入库存数量，库存数量应该在[1, 1000]范围内：");
                float f_temp;
                Boolean check = float.TryParse(Console.ReadLine(), out f_temp);
                if (check)
                {
                    if (csi3.Quantity > 1000 || csi3.Quantity < 1)
                    {
                        Console.WriteLine("错误！输入超出范围！请重新输入！");
                        continue;
                    }
                    else
                    {
                        csi3.Quantity = f_temp;
                        break;
                    }
                }
                else
                {
                    Console.WriteLine("错误！注意不要输入除数字外的内容，请重新输入！");
                    continue;
                }
            }
            Console.WriteLine("库存数量输入成功");
            Console.WriteLine("");



            // 检查库存情况
            Console.WriteLine("正在自动检查库存情况......");
            if (csi3.Quantity > csi3.UpperLimit)
                Console.WriteLine("库存量已超限！！！请注意仓储！！！");
            else if (csi3.Quantity < csi3.LowerLimit)
                Console.WriteLine("库存量已不足！！！请注意补货！！！");
            else
                Console.WriteLine("库存量正常，建议清点货物数量，防止遗漏");

            csi3.ShowInfo();
            Console.WriteLine("按任意键退出......");
            Console.ReadLine();
        }

        public class cStockInfo
        {
            private string tradeCode = "";
            private string fullName = "";
            private string tradeType = "";
            private string standard = "";
            private string tradeUnit = "";
            //private struct tradeUnit
            //{
            //    private string unit = Regex.Replace(s_tradeUnit, unit, "", RegexOptions.IgnoreCase);
            //    private int scale = Regex.Replace(input, unit, "", RegexOptions.IgnoreCase);
            //    public string getUnit()
            //    {
            //        return scale.ToString() + unit;
            //    }
            //    public void setUnit(string input)
            //    {
            //        unit = Regex.Replace(input, "[0-9]", "", RegexOptions.IgnoreCase);
            //        scale = int.Parse(input.Replace(unit, ""))  ;// Regex.Replace(input, unit, "", RegexOptions.IgnoreCase);
            //    }
            //}

            private string produce = "";

            private float quantity = 0;
            private float price = 0;
            private float averagePrice = 0;
            private float salePrice = 0;
            private float check = 0;
            private float upperLimit = 0;
            private float lowerLimit = 0;

            public string TradeCode
            {
                get { return tradeCode; }
                set { tradeCode = value; }
            }

            public string FullName
            {
                get { return fullName; }
                set { fullName = value; }
            }

            public string TradeType
            {
                get { return tradeType; }
                set { tradeType = value; }
            }

            public string Standard
            {
                get { return standard; }
                set { standard = value; }
            }

            public string Unit
            {
                get { return tradeUnit; }
                set { tradeUnit = value; }
            }

            public string Produce
            {
                get { return produce; }
                set { produce = value; }
            }

            public float Quantity
            {
                get { return quantity; }
                set { quantity = value; }
            }

            public float Price
            {
                get { return price; }
                set { price = value; }
            }

            public float AveragePrice
            {
                get { return averagePrice; }
                set { averagePrice = value; }
            }

            public float SalePrice
            {
                get { return salePrice; }
                set { salePrice = value; }
            }

            public float Check
            {
                get { return check; }
                set { check = value; }
            }

            public float UpperLimit
            {
                get { return upperLimit; }
                set { upperLimit = value; }
            }

            public float LowerLimit
            {
                get { return lowerLimit; }
                set { lowerLimit = value; }
            }

            public cStockInfo()
            {
                this.TradeCode = "TJRA001";
                this.FullName = "空调";
                this.TradeType = "TYPE-2";
                this.Standard = "2匹";
                this.Unit = "台";
                this.Produce = "天津";
                this.Quantity = 200;
                this.Price = 2000;
                this.AveragePrice = 2500;
                this.SalePrice = 3000;
                this.Check = 200;
                this.UpperLimit = 900;
                this.LowerLimit = 100;
            }

            public void ShowInfo()
            {
                Console.WriteLine("-----------------------------------------------------");
                Console.WriteLine("显示商品信息");
                Console.WriteLine("");
                Console.WriteLine("商品编号：{0, -15}", TradeCode);
                Console.WriteLine("单位全称：{0, -15}", FullName);
                Console.WriteLine("商品型号：{0, -15}", TradeType);
                Console.WriteLine("");
                Console.WriteLine("商品规格：{0, -15}", Standard);
                Console.WriteLine("商品单位：{0, -15}", Unit);
                Console.WriteLine("商品产地：{0, -15}", Produce);
                Console.WriteLine("库存数量：{0, -15}", Quantity);
                Console.WriteLine("");
                Console.WriteLine("最后一次价格：{0, -15:C}", Price);
                Console.WriteLine("加权平均价格：{0, -15:C}", AveragePrice);
                Console.WriteLine("库存数量：{0, -15:C}", SalePrice);
                Console.WriteLine("");
                Console.WriteLine("盘点数量：{0, -15}", Check);
                Console.WriteLine("库存警报上限：{0, -15}", UpperLimit);
                Console.WriteLine("库存警报下线：{0, -15}", LowerLimit);
                Console.WriteLine("");
                Console.WriteLine("商品信息显示完毕");
                Console.WriteLine("-----------------------------------------------------");
            }
        }
    }
}