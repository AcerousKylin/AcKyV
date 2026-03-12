using System;
using System.Windows.Forms;

namespace Final_Project
{
    public partial class FormAlarm : Form
    {
        public FormAlarm()
        {
            InitializeComponent();
        }

        private void buttonDeparment_Click(object sender, MouseEventArgs e)
        {
            Button buttonCurrent = (Button)sender;
            bool inStandby = false, inOp = false;

            foreach (ListViewItem district in listViewStandbyUnit.Items)
            {
                if (district.Text == buttonCurrent.Text)
                {
                    inStandby = true;
                    break;
                }
            }
            foreach (ListViewItem district in listViewOpUnit.Items)
            {
                if (district.Text == buttonCurrent.Text)
                {
                    inOp = true;
                    break;
                }
            }

            if (inStandby && inOp)
                MessageBox.Show("系统发生错误，请手动删除矛盾的调度单位", "发生错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
            else if (inStandby && !inOp)
                MessageBox.Show("该单位已待命！", "重复调度", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            else if (!inStandby && inOp)
                MessageBox.Show("该单位已出勤！", "重复调度", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            else
            {
                if (e.Button == MouseButtons.Left)
                    listViewStandbyUnit.Items.Add(buttonCurrent.Text);
                else if (e.Button == MouseButtons.Right)
                    listViewOpUnit.Items.Add(buttonCurrent.Text);
                else
                    System.Media.SystemSounds.Question.Play();
            }
        }
        private void buttonSbToOp_Click(object sender, EventArgs e)
        {
            if (listViewStandbyUnit.SelectedItems.Count == 0)
                return;
            ListViewItem temp = listViewStandbyUnit.FocusedItem;
            listViewStandbyUnit.Items.Remove(temp);
            listViewOpUnit.Items.Add(temp);
        }
        private void buttonDelete_Click(object sender, EventArgs e)
        {
            if (listViewStandbyUnit.SelectedItems == new ListView.SelectedListViewItemCollection(listViewStandbyUnit) && listViewOpUnit.SelectedItems == null)
                return;
            foreach (ListViewItem item in listViewStandbyUnit.Items)
            {
                if (listViewStandbyUnit.SelectedItems.Contains(item))
                {
                    int index = listViewStandbyUnit.Items.IndexOf(listViewStandbyUnit.FocusedItem);
                    if (listViewStandbyUnit.SelectedItems.Count != 0)
                    {
                        listViewStandbyUnit.Items.RemoveAt(index);
                    }
                }
            }
            foreach (ListViewItem item in listViewOpUnit.Items)
            {
                if (listViewOpUnit.SelectedItems.Contains(item))
                {
                    int index = listViewOpUnit.Items.IndexOf(listViewOpUnit.FocusedItem);
                    if (listViewOpUnit.SelectedItems.Count != 0)
                    {
                        listViewOpUnit.Items.RemoveAt(index);
                    }
                }
            }
        }

        private void buttonGenerate_Click(object sender, EventArgs e)
        {
            MessageBox.Show("暂时无法生成警情。", "生成失败", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private void buttonMultiOp_Click(object sender, EventArgs e)
        {
            MessageBox.Show("暂时无法连接协警。", "连接失败", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private void buttonAlarmTrans_Click(object sender, EventArgs e)
        {
            MessageBox.Show("暂时无法转移警情。", "转移失败", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private void buttonCallRecorder_Click(object sender, EventArgs e)
        {
            MessageBox.Show("暂时无法回呼录音。", "回呼失败", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private void buttonOpToSb_Click(object sender, EventArgs e)
        {
            if (listViewOpUnit.SelectedItems.Count == 0)
                return;
            ListViewItem temp = listViewOpUnit.FocusedItem;
            listViewOpUnit.Items.Remove(temp);
            listViewStandbyUnit.Items.Add(temp);
        }
    }
}
