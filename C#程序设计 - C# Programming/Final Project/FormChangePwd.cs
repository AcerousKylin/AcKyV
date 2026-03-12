using System;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace Final_Project
{
    public partial class FormChangePwd : BasicForm
    {
        public FormChangePwd() : base()
        {
            InitializeComponent();
        }
        public FormChangePwd(String id, String pwd) : base(id, pwd)
        {
            InitializeComponent();
        }

        private void buttonConfirm_Click(object sender, EventArgs e)
        {

            if (this.textOriPwd.Text == pwd && textNewPwd.Text.Length == 10)
            {
                pwd = textNewPwd.Text;
                MessageBox.Show("修改成功！", "修改完成", MessageBoxButtons.OK, MessageBoxIcon.Information);
                this.Close();
            }
            else if (String.IsNullOrEmpty(this.textOriPwd.Text) || String.IsNullOrEmpty(this.textNewPwd.Text))
            {
                MessageBox.Show("原密码和新密码不可为空！", "输入为空", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (textOriPwd.Text != pwd)
            {
                MessageBox.Show("原密码输入错误！", "密码错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (textNewPwd.Text.Length != 10)
            {
                MessageBox.Show("密码长度必须为10！", "格式错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if(!Regex.IsMatch(textNewPwd.Text, @"[0-9]+$"))
            {
                MessageBox.Show("新密码必须为数字", "格式错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else if (textOriPwd == textNewPwd)
            {
                MessageBox.Show("新密码与原密码相同！", "更改无效", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
