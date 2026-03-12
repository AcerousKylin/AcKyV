using System.IO;
using System.Windows.Forms;

namespace Final_Project
{
    public partial class FormShowNotice : Form
    {
        // 存储需要显示的文件的FileInfo
        private FileInfo fileInfoNotice;
        public FormShowNotice()
        {
            InitializeComponent();
        }

        // 重载构造函数
        public FormShowNotice(FileInfo fileInfoNotice)
        {
            this.fileInfoNotice = fileInfoNotice;
            InitializeComponent();
        }

        // 显示文本文档中的文字
        private void FormShowNotice_Load(object sender, System.EventArgs e)
        {
            labelNotice.Text = fileInfoNotice.Name;
            richTextBoxNotice.ResetText();
            richTextBoxNotice.AppendText(File.ReadAllText(fileInfoNotice.ToString()));
        }
    }
}
