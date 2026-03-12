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
    public partial class Form1 : Form
    {
        double Mar;
        double Apr;
        double May;
        public Form1(double Mar, double Apr, double May)
        {
            InitializeComponent();
            this.Mar = Mar;
            this.Apr = Apr;
            this.May = May;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            int width = 400, height = 450;
            
            SolidBrush brush1 = new SolidBrush(Color.FromArgb(0, 30, 30, 30));
            SolidBrush brush2 = new SolidBrush(Color.FromArgb(0, 40, 40, 40));
            SolidBrush brush3 = new SolidBrush(Color.FromArgb(0, 50, 50, 50));

            RectangleF rf1 = new RectagleF(PointF())

            Graphics g = CreateGraphics();
            g.DrawPie(brush1, RectangleF() )
        }
    }
}
