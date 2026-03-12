using System.IO;
using System.Linq;
using System.Windows.Forms;

namespace Final_Project
{
    public partial class FormNotice : Form
    {
        public FormNotice()
        {
            InitializeComponent();
        }

        //  窗体初始化，主要对TreeView需要显示的内容进行初始化
        private void FormNotice_Load(object sender, System.EventArgs e)
        {
            // 获得工程/bin/Debug文件的绝对路径，防止程序迁移后无法使用
            // 路径应为.\Final Project\bin\Debug\
            string pathRoot = Path.GetDirectoryName(this.GetType().Assembly.Location) + "\\沈阳市公安局";
            string nameRoot = Path.GetFileNameWithoutExtension(pathRoot);

            // 先清除窗体自带的静态结点（它们是作调试用）
            treeViewUnits.Nodes.Clear();

            // 初始化根结点，利用Tag存储每个节点所在路径，并设置文件夹和文件的图标（后面将利用ImageIndex用于区分两者）
            TreeNode nodeRoot = new TreeNode(pathRoot);
            nodeRoot.Tag = pathRoot;
            nodeRoot.Text = nameRoot;
            nodeRoot.ImageIndex = nodeRoot.SelectedImageIndex = 1;
            treeViewUnits.Nodes.Add(nodeRoot);

            // 遍历整个根结点下的文件
            treeViewUnits_GetLeafNodes(nodeRoot, pathRoot);
        }

        // 递归遍历所有根结点下的子结点
        private void treeViewUnits_GetLeafNodes(TreeNode nodeRoot, string pathRoot)
        {
            // 路径错误则进行提示
            if (Directory.Exists(pathRoot) == false)
                MessageBox.Show("路径不存在！", "路径错误", MessageBoxButtons.OK, MessageBoxIcon.Error);

            // 对两种临时结点进行初始化
            DirectoryInfo dirInfoRoot = new DirectoryInfo(pathRoot);
            DirectoryInfo[] dirInfoLeaves = dirInfoRoot.GetDirectories();
            int dirsInRoot = dirInfoLeaves.Count();

            FileInfo[] fileInfoLeaves = dirInfoRoot.GetFiles();
            int filesInRoot = fileInfoLeaves.Count();

            // 循环递归所有子对象
            for (int i = 0; i < filesInRoot; i++)
            {
                TreeNode temp = new TreeNode(fileInfoLeaves[i].Name, 0, 0);
                temp.Tag = fileInfoLeaves[i].FullName;
                nodeRoot.Nodes.Add(temp);
            }

            for (int i = 0; i < dirsInRoot; i++)
            {
                TreeNode temp = new TreeNode(dirInfoLeaves[i].Name, 1, 1);
                temp.Tag = dirInfoLeaves[i];
                nodeRoot.Nodes.Add(temp);
                string pathleaf = dirInfoLeaves[i].FullName;
                treeViewUnits_GetLeafNodes(nodeRoot.Nodes[i], pathleaf);
            }
        }

        // 针对结点的双击事件，用于实现直接在TreeView中查看文本文档的内容
        private void treeViewUnits_NodeMouseDoubleClick(object sender, TreeNodeMouseClickEventArgs e)
        {
            // 如果双击文件夹，可以切换其展开/折叠状态
            if (e.Node.ImageIndex == 1)
            {
                if (e.Node.IsExpanded)
                    e.Node.Collapse();
                else
                    e.Node.Expand();
            }
            // 如果双击文本文档，将出现包含其中文本的新窗体
            else
            {
                FormShowNotice frmShowNotice = new FormShowNotice(new FileInfo((string)e.Node.Tag));
                frmShowNotice.Show();
            }
        }

        // TreeView结点的Check事件，实现了父结点与子结点之间的Check逻辑
        private void treeViewUnits_AfterCheck(object sender, TreeViewEventArgs e)
        {
            if (e.Action == TreeViewAction.ByMouse) // 确定为鼠标操作
            {
                // 针对多级结构，分别向上检测父结点、向下检测子结点
                treeViewUnits_CheckParentNodes(e.Node, e.Node.Checked);
                treeViewUnits_CheckChildNodes(e.Node, e.Node.Checked);
            }
        }

        // 递归检测
        private void treeViewUnits_CheckParentNodes(TreeNode currentNode, bool state)
        {
            bool changeParent = true;
            TreeNode currentParent = currentNode.Parent;

            if (currentParent != null)
            {
                treeViewUnits_CheckParentNodes(currentParent, state);
                foreach (TreeNode node in currentParent.Nodes)
                    if (node.Checked != state)
                        changeParent = false;
                if (changeParent || !state)
                    currentParent.Checked = state;
            }
            else
                return;
        }
        private void treeViewUnits_CheckChildNodes(TreeNode currentNode, bool state)
        {
            if (currentNode.Nodes.Count > 0)
            {
                foreach (TreeNode node in currentNode.Nodes)
                {
                    treeViewUnits_CheckChildNodes(node, state);
                    if (node.Checked != state)
                        node.Checked = state;
                }
            }
            else
                return;
        }

        // 清空按钮的实现
        private void buttonCleanText_Click(object sender, System.EventArgs e)
        {
            richTextBoxInput.ResetText();
            richTextBoxInput.Refresh();
        }

        // 退出按钮的实现
        private void buttonQuit_Click(object sender, System.EventArgs e)
        {
            this.Close();
        }

        // 发送按钮的实现
        private void buttonSend_Click(object sender, System.EventArgs e)
        {
            DialogResult confirm = MessageBox.Show("确定向选中单位发布已编辑的消息吗？", "确认", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);
            if (confirm == DialogResult.Cancel)
                return;

            bool checkedExist = treeViewUnits_Send(treeViewUnits.TopNode);
            if (checkedExist == false)
            {
                MessageBox.Show("请先选择要发送通知的部门或单位！", "发送失败", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            else
                MessageBox.Show("通知发送成功！可以双击进行查看。", "发送成功", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        // 递归实现将文本框中的消息发送到已选中结点中，并返回当前是否有结点被选中
        private bool treeViewUnits_Send(TreeNode currentNode)
        {
            bool checkedExist = false;
            foreach (TreeNode treeNode in currentNode.Nodes)
            {
                if (treeNode.Checked && treeNode.ImageIndex == 0) // 被选中的若是文本文件结点
                {
                    // 新的公告内容将覆盖原内容
                    string title = textBoxNoticeTitle.Text;
                    // 设置标题格式
                    if (title != string.Empty)
                        title = '\t' + title + '\n';
                    // 将通知内容写入文件
                    StreamWriter streamWriter = File.CreateText(title + (string)treeNode.Tag);
                    streamWriter.Write(richTextBoxInput.Text);
                    streamWriter.Close();
                    checkedExist = true;
                }
                else if (treeNode.ImageIndex == 1) // 被选中的若是文件夹结点
                {
                    if (treeNode.Nodes.Count > 0) // 文件夹不为空，说明这个文件夹可能有被选中的文本文件
                        checkedExist |= treeViewUnits_Send(treeNode); // 递归，对结果进行或等运算
                    else // 文件夹为空，说明这个文件夹没有被选中的文本文件
                        checkedExist |= false; // 或等false
                }
                else
                    checkedExist |= false; // 防止其他异常操作
            }
            return checkedExist; // 最后返回是否有被选中的文本文档结点
        }
    }
}
