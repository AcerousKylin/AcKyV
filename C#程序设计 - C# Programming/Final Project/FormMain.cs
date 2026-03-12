using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.IO; // 添加IO库
using System.Linq;
using System.Windows.Forms;

namespace Final_Project
{
    public partial class FormMain : BasicForm
    {
        private FormLogin frmLoginParent = null;

        public FormMain() : base()
        {
            InitializeComponent();
        }
        public FormMain(FormLogin frmLogin) : base()
        {
            InitializeComponent();
            this.frmLoginParent = frmLogin;
        }
        public FormMain(String id, String pwd) : base(id, pwd)
        {
            InitializeComponent();
        }

        private void menuItemChangePwd_Click(object sender, EventArgs e)
        {
            FormChangePwd formChangePwd = new FormChangePwd();
            formChangePwd.ShowDialog();
        }

        private void FormMain_Load(object sender, EventArgs e)
        {
            // 文件流指定路径为“D:\Code Space\C#\Final Project\bin\Debug\feedback.txt”，并按行读取
            FileStream fileStreamFeedback = new FileStream(Application.StartupPath + "\\feedback.txt", FileMode.Open, FileAccess.ReadWrite, FileShare.ReadWrite);
            StreamReader streamReaderFeedback = new StreamReader(fileStreamFeedback);

            // 对读取的整行字符串进行预处理，使用二重列表进行存储
            List<List<String>> itemElement = new List<List<String>>();
            while (true)
            {
                String tupleFeedback = streamReaderFeedback.ReadLine();
                // EOF结束
                if (tupleFeedback == null || tupleFeedback.Trim() == "")
                    break;
                // 用“|”对每行的元素进行分割
                String[] singleElements = tupleFeedback.Split('|');
                List<String> splitElements = new List<String>();
                foreach (String element in singleElements)
                {
                    splitElements.Add(element.Trim());
                }
                itemElement.Add(splitElements);
            }

            // 预处理结束，准备显示
            listViewFeedback.BeginUpdate();
            List<ListViewItem> items = new List<ListViewItem>();
            // 基本使用双重循环进行Item赋值
            for (int i = 0; i < itemElement.LongCount(); i++)
            {
                ListViewItem itemFeedback = new ListViewItem();
                List<String> temp = itemElement.ElementAt<List<String>>(i);
                itemFeedback = listViewFeedback.Items.Add(temp[0].ToString().Trim());
                itemFeedback.SubItems.Add(temp[1].ToString().Trim());
                itemFeedback.SubItems.Add(temp[2].ToString().Trim());
            }
            listViewFeedback.EndUpdate(); // 结束显示更新
        }

        private void LoginOut_Click(object sender, EventArgs e)
        {
            this.Close();
            frmLoginParent.Show();
        }

        private PointF[][] Hex(float X0, float Y0, float multiple)
        {   // 根据位置和倍率，生成一个二维六边形坐标数组
            float Sqrt_3 = (float)Math.Sqrt(3);
            PointF pointTop = new PointF(X0, Y0 - 1.0f * Sqrt_3 * multiple),
               pointTopLeft = new PointF(X0 - 1.5f * multiple, Y0 - 0.5f * Sqrt_3 * multiple),
              pointTopRight = new PointF(X0 + 1.5f * multiple, Y0 - 0.5f * Sqrt_3 * multiple),
            pointBottomLeft = new PointF(X0 - 1.5f * multiple, Y0 + 0.5f * Sqrt_3 * multiple),
           pointBottomRight = new PointF(X0 + 1.5f * multiple, Y0 + 0.5f * Sqrt_3 * multiple),
                pointBottom = new PointF(X0, Y0 + 1.0f * Sqrt_3 * multiple);


            PointF cornerTopLeft = new PointF(X0 - 0.5f * multiple, Y0 - 0.5f * Sqrt_3 * multiple),
                  cornerTopRight = new PointF(X0 + 0.5f * multiple, Y0 - 0.5f * Sqrt_3 * multiple),
                   cornerMidLeft = new PointF(X0 - 1.0f * multiple, Y0),
                  cornerMidRight = new PointF(X0 + 1.0f * multiple, Y0),
                cornerBottomLeft = new PointF(X0 - 0.5f * multiple, Y0 + 0.5f * Sqrt_3 * multiple),
               cornerBottomRight = new PointF(X0 + 0.5f * multiple, Y0 + 0.5f * Sqrt_3 * multiple);

            PointF[] hexCentral = {pointTop,
                                   cornerTopRight, pointTopRight, cornerMidRight, pointBottomRight, cornerBottomRight,
                                   pointBottom,
                                   cornerBottomLeft, pointBottomLeft, cornerMidLeft, pointTopLeft, cornerTopLeft};
            PointF[] hexPoints = { pointTop, pointTopLeft, pointTopRight, pointBottomLeft, pointBottomRight, pointBottom };
            PointF[] hexCorner = { cornerTopLeft, cornerTopRight, cornerMidLeft, cornerMidRight, cornerBottomLeft, cornerBottomRight };

            PointF[][] hexResult = new PointF[3][];
            hexResult[0] = hexCentral;
            hexResult[1] = hexPoints;
            hexResult[2] = hexCorner;
            return hexResult;
        }

        private void pictureMain_Click(object sender, EventArgs e)
        {
            // 位于鼠标右下的六边形坐标集
            /*PointF      pointTop = new PointF(X0 + 1.5f * multiple, Y0),
                    pointTopLeft = new PointF(X0,                   Y0 + 0.5f * Sqrt_3 * multiple),
                   pointTopRight = new PointF(X0 + 3.0f * multiple, Y0 + 0.5f * Sqrt_3 * multiple),
                 pointBottomLeft = new PointF(X0,                   Y0 + 1.5f * Sqrt_3 * multiple),
                pointBottemRight = new PointF(X0 + 3.0f * multiple, Y0 + 1.5f * Sqrt_3 * multiple),
                     pointBottom = new PointF(X0 + 1.5f * multiple, Y0 + 2.0f * Sqrt_3 * multiple);

            PointF    cornerTopLeft = new PointF(X0 + 1.0f * multiple, Y0 + 0.5f * Sqrt_3 * multiple),
                     cornerTopRight = new PointF(X0 + 2.0f * multiple, Y0 + 0.5f * Sqrt_3 * multiple),
                      cornerMidLeft = new PointF(X0 + 0.5f * multiple, Y0 + 1.0f * Sqrt_3 * multiple),
                     cornerMidRight = new PointF(X0 + 2.5f * multiple, Y0 + 1.0f * Sqrt_3 * multiple),
                   cornerBottomLeft = new PointF(X0 + 1.0f * multiple, Y0 + 1.5f * Sqrt_3 * multiple),
                  cornerBottomRight = new PointF(X0 + 2.0f * multiple, Y0 + 1.5f * Sqrt_3 * multiple);

            PointF[] hexLeftDown = {pointTop,
                            cornerTopRight, pointTopRight, cornerMidRight, pointBottemRight, cornerBottomRight,
                            pointBottom,
                            cornerBottomLeft, pointBottomLeft, cornerMidLeft, pointTopLeft, cornerTopLeft};*/

            pictureMain.Refresh();

            // 设定坐标和笔刷
            PointF originalPoint = pictureMain.PointToClient(Control.MousePosition);
            Brush layer1 = new SolidBrush(Color.FromArgb(255, 193, 2)), layer2 = new SolidBrush(Color.FromArgb(254, 244, 200));

            // 绘制并填充多层六角星
            Graphics clickGraph = pictureMain.CreateGraphics();
            PointF[][] hexBack = Hex(originalPoint.X, originalPoint.Y, 50.0f);
            clickGraph.FillPolygon(layer1, hexBack[0]);
            float radius = 20.0f;
            for (int i = 0; i < hexBack[1].Length; i++)
                clickGraph.FillPie(layer1, hexBack[1][i].X - radius / 2, hexBack[1][i].Y - radius / 2, radius, radius, 0.0f, 360.0f);

            PointF[][] hexMid = Hex(originalPoint.X, originalPoint.Y, 40.0f);
            clickGraph.FillPolygon(layer2, hexMid[0]);

            PointF[][] hexInside = Hex(originalPoint.X, originalPoint.Y, 30.0f);
            Brush fill = new LinearGradientBrush(hexInside[1][0], hexInside[1][5], Color.FromArgb(240, 227, 180), Color.FromArgb(197, 171, 114));
            clickGraph.FillPolygon(fill, hexInside[0]);
        }

        private void pictureMain_DoubleClick(object sender, EventHandler e)
        {
            FormReport frmReport = new FormReport();
            frmReport.ShowDialog();
        }
        private void FormAlarm_Click(object sender, EventArgs e)
        {
            FormAlarm frmAlarm = new FormAlarm();
            frmAlarm.ShowDialog();
        }

        private void msItemAnnounce_Click(object sender, EventArgs e)
        {
            FormNotice frmNotice = new FormNotice();
            frmNotice.ShowDialog();
        }
    }
}
