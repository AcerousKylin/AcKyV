using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace EMS
{
    public partial class frameLogin : Form
    {
        public frameLogin()
        {
            InitializeComponent();
        }

        public static string strName;

        private void btnLogin_Click(object sender, EventArgs e)
        {
            if (txtUserName.Text == string.Empty)
            {
                MessageBox.Show("用户名不能为空！", "错误提示", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            if (txtUserName.Text == "wangjiaqi" && txtUserPwd.Text == "6021203558")
            {
                strName = txtUserName.Text;
                frameMain main = new frameMain();
                main.Show(); // 显示主窗体
                this.Visible = false; // 隐藏主窗体
            }
            else
            {
                MessageBox.Show("用户名称或密码不正确！", "错误提示", MessageBoxButton.OK, MessageBoxIcon.Error);
            }
        }

        private void txtUserName_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyValue == 13) // 是否按下Enter
                txtUserPwd.Focus(); // 输入框转到“密码”
        }

        private void txtUserPwd_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyValue == 13) // 同上
                btnLogin.Focus();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
