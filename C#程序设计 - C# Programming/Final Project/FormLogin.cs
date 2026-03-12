using System;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace Final_Project
{
    public partial class FormLogin : BasicForm
    {
        // 将用户信息传入
        public FormLogin(String id, String pwd) : base(id, pwd)
        {
            InitializeComponent();
        }
        private void buttonLogin_Click(object sender, EventArgs e)
        {
            // 返回文本框输入字符
            String i_id = textID.Text;
            String i_pwd = textPwd.Text;

            if (i_id.Equals(id) && i_pwd.Equals(pwd)) // 此处使用"=="亦可
            {
                FormMain FormMain = new FormMain(this);
                this.Visible = false;
                FormMain.ShowDialog();
            }
            else if (i_id == "" || i_pwd == "")  // 由于使用了外部变量，无需检验为空引用，否则用String.IsNullOrEmpty()
            {
                MessageBox.Show("用户名/密码不能为空！", "出现留空", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (!Regex.IsMatch(i_id, @"[a-z A-Z]+$") || i_pwd.Length != 10) // 使用正则表达式检验字符串是否全为字母
            {   // 同上
                i_id = null;
                i_pwd = null;
                MessageBox.Show("用户名需为全英字母/密码长度为10！", "格式错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {   // 同上
                i_id = null;
                i_pwd = null;
                MessageBox.Show("用户名或密码输入错误！", "输入有误", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            // 清空输入框
            textID.Clear();
            textPwd.Clear();
        }

        // Enter键的快捷操作
        private void textID_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyValue == 13)
                textPwd.Focus();
        }

        private void textPwd_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyValue == 13)
                buttonLogin.Focus();
        }
        private void buttonExit_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
