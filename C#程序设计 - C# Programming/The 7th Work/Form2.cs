using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace The_7th_Work
{
    public partial class Input : Form
    {
        double Mar;
        double Apr;
        double May;
        Boolean tri = false;
        public Input()
        {
            InitializeComponent();
        }

        private void Input_Load(object sender, EventArgs e)
        {
            textBox1 = new TextBox();
            textBox2 = new TextBox();
            textBox3 = new TextBox();
            double.TryParse(textBox1.Text, out Mar);
            double.TryParse(textBox2.Text, out Apr);
            double.TryParse(textBox3.Text, out May);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form1 form1 = new Form1(Mar, Apr, May);
            if (May != 0.0 && Apr != 0.0 && May != 0.0)
                form1.ShowDialog();
            else
                MessageBox.Show(请输入)
        }
    }
}
