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
    public partial class frameMain : Form
    {
        public frameMain()
        {
            InitializeComponent();
        }

        private void mstripBuyStock_Click(object sender, EventArgs e)
        {
            new frameBuyStock().ShowDialog();
        }

    }
}
