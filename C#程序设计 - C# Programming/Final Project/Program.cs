using System;
using System.Windows.Forms;

namespace Final_Project
{
    // 建立基本类，存储用户信息。由于用户信息库的缺失，仅支持单用户及其修改操作
    public class BasicForm : Form
    {
        // 防止子类任意调用，使用protected进行封装
        protected static String id { get; set; }
        protected static String pwd { get; set; }

        // 必须定义无参构造，否则子类Activate.CreateInstances将提示父类无构造函数
        public BasicForm() { }
        public BasicForm(String id, String pwd)
        {
            BasicForm.id = id;
            BasicForm.pwd = pwd;
        }
    }

    internal static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            // 初始化账户密码
            Application.Run(new FormLogin("Wangjiaqi", "6021203558"));
        }
    }
}
