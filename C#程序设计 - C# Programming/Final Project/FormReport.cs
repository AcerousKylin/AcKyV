using System;
using System.Drawing;
using System.Windows.Forms;

namespace Final_Project
{
    public partial class FormReport : Form
    {
        private int[] stuClasses = new int[3] { 348, 346, 371 };
        private int stuTotal;
        private int[] stuAbsent = new int[3] { 21, 12, 0 };
        private int stuTotalAbsent;
        private float[] stuPercentage = new float[3];

        public FormReport()
        {
            InitializeComponent();
            for (int i = 0; i < 3; i++)
            {
                stuTotal += stuClasses[i];
                stuTotalAbsent += stuAbsent[i];
            }
            for (int i = 0; i < 3; i++)
                stuPercentage[i] = (float)stuClasses[i] / (float)stuTotal;
        }

        private void FormReport_Load(object sender, EventArgs e)
        {
            ;
        }

        private void groupBoxClass_Paint(object sender, PaintEventArgs e)
        {
            GroupBox groupBoxClass = sender as GroupBox;
            int indexClass;
            if (groupBoxClass == groupBoxA)
                indexClass = 0;
            else if (groupBoxClass == groupBoxB)
                indexClass = 1;
            else if (groupBoxClass == groupBoxC)
                indexClass = 2;
            else
                return;

            int signed = stuClasses[indexClass] - stuAbsent[indexClass];
            float radius = 150f;
            SolidBrush brushSigned = new SolidBrush(Color.ForestGreen), brushAbsent = new SolidBrush(Color.Gray);
            Font description = new Font("微软雅黑", 10, FontStyle.Bold);
            Graphics g = e.Graphics;
            g.TranslateTransform(groupBoxClass.Width / 2, groupBoxClass.Height / 2 - 30);

            int startAngle = 0;
            for (int i = 0; i < 2; i++)
            {
                SolidBrush solidBrushTemp = (i == 0) ? brushSigned : brushAbsent;
                int intSection = (int)((float)((i == 0) ? signed : stuAbsent[indexClass]) / (float)stuClasses[indexClass] * 360f);
                for (int j = startAngle; j < startAngle + intSection; j++)
                {
                    g.FillPie(solidBrushTemp, -radius / 2, -radius / 2, radius, radius, j, 1);
                    // Thread.Sleep(15);
                }
                startAngle = startAngle + intSection;
                g.FillRectangle(solidBrushTemp, -40f, 90 + 40 * i, 15, 15);
                string output = (i == 0) ? "Signed" : "Absent";
                g.DrawString(output, description, solidBrushTemp, new PointF(-20f, 90 + 40 * i));
            }
            g.Dispose();
        }

        private void groupBoxTotal_Paint(object sender, PaintEventArgs e)
        {
            float radius = 150f;
            SolidBrush[] brushes = { new SolidBrush(Color.Azure), new SolidBrush(Color.BurlyWood), new SolidBrush(Color.Crimson) };
            Font description = new Font("微软雅黑", 10, FontStyle.Bold);
            Graphics g = e.Graphics;
            g.TranslateTransform(groupBoxTotal.Width / 2 - 175, groupBoxTotal.Height / 2);

            int startAngle = 0;
            for (int i = 0; i < 3; i++)
            {
                int intSection = (int)(stuPercentage[i] * 360f);
                int j;
                for (j = startAngle; j < startAngle + intSection; j++)
                {
                    g.FillPie(brushes[i], -radius / 2, -radius / 2, radius, radius, j, 1);
                    //Thread.Sleep(15);
                }
                startAngle = startAngle + intSection;
                g.FillRectangle(brushes[i], 100f, -60 + 60 * i, 15, 15);
                g.DrawString("Class " + ("A" + i), description, brushes[i], new PointF(120f, -60 + 60 * i));
            }

            SolidBrush brushSigned = new SolidBrush(Color.ForestGreen), brushAbsent = new SolidBrush(Color.Gray);
            startAngle = 0;
            for (int i = 0; i < 2; i++)
            {
                SolidBrush solidBrushTemp = (i == 0) ? brushSigned : brushAbsent;
                int intSection = (int)((float)((i == 0) ? stuTotal - stuTotalAbsent : stuTotalAbsent) / (float)stuTotal * 360f);
                for (int j = startAngle; j < startAngle + intSection; j++)
                {
                    g.FillPie(solidBrushTemp, -radius / 2 + 275, -radius / 2, radius, radius, j, 1);
                    // Thread.Sleep(15);
                }
                startAngle = startAngle + intSection;
                g.FillRectangle(solidBrushTemp, 375f, -20 + 40 * i, 15, 15);
                string output = (i == 0) ? "Signed" : "Absent";
                g.DrawString(output, description, solidBrushTemp, new PointF(395f, -20 + 40 * i));
            }
            g.Dispose();
        }
    }
}
