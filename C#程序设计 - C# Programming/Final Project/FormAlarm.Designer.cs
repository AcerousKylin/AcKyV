using Microsoft.Win32;
using System.Windows.Forms;

namespace Final_Project
{
    partial class FormAlarm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormAlarm));
            this.panelDataInfo = new System.Windows.Forms.Panel();
            this.textDuration = new System.Windows.Forms.TextBox();
            this.textRecordNum = new System.Windows.Forms.TextBox();
            this.labelDuration = new System.Windows.Forms.Label();
            this.labelRecordNum = new System.Windows.Forms.Label();
            this.textAlarmTele = new System.Windows.Forms.TextBox();
            this.textAlarmTime = new System.Windows.Forms.TextBox();
            this.labelAlarmeTele = new System.Windows.Forms.Label();
            this.labelAlarmTime = new System.Windows.Forms.Label();
            this.textAddress = new System.Windows.Forms.TextBox();
            this.textAlarmNum = new System.Windows.Forms.TextBox();
            this.labelAddress = new System.Windows.Forms.Label();
            this.textUserName = new System.Windows.Forms.TextBox();
            this.labelUserName = new System.Windows.Forms.Label();
            this.labelCaseNum = new System.Windows.Forms.Label();
            this.panelAlarmSettings = new System.Windows.Forms.Panel();
            this.groupBoxBrief = new System.Windows.Forms.GroupBox();
            this.richTextAlarmBrief = new System.Windows.Forms.RichTextBox();
            this.labelCharger = new System.Windows.Forms.Label();
            this.labelSuperior = new System.Windows.Forms.Label();
            this.comboBoxCharger = new System.Windows.Forms.ComboBox();
            this.comboBoxSuperior = new System.Windows.Forms.ComboBox();
            this.comboBoxUnitGroup = new System.Windows.Forms.ComboBox();
            this.comboUnitType = new System.Windows.Forms.ComboBox();
            this.textBoxAlarmName = new System.Windows.Forms.TextBox();
            this.comboBoxCharType = new System.Windows.Forms.ComboBox();
            this.comboBoxChar = new System.Windows.Forms.ComboBox();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.labelChar = new System.Windows.Forms.Label();
            this.labelUnitGroup = new System.Windows.Forms.Label();
            this.labelAlarmName = new System.Windows.Forms.Label();
            this.labelCharType = new System.Windows.Forms.Label();
            this.textBoxAdditional = new System.Windows.Forms.TextBox();
            this.labelAdditional = new System.Windows.Forms.Label();
            this.comboBoxControlledArticle = new System.Windows.Forms.ComboBox();
            this.labelControlledArticle = new System.Windows.Forms.Label();
            this.buttonLocating = new System.Windows.Forms.Button();
            this.buttonRecorderBase = new System.Windows.Forms.Button();
            this.buttonTeleData = new System.Windows.Forms.Button();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.comboAlarmType = new System.Windows.Forms.ComboBox();
            this.labelCallType = new System.Windows.Forms.Label();
            this.textBoxCallRecorder = new System.Windows.Forms.TextBox();
            this.buttonCallRecorder = new System.Windows.Forms.Button();
            this.comboBoxRecorderStatus = new System.Windows.Forms.ComboBox();
            this.labelRecorderStatus = new System.Windows.Forms.Label();
            this.comboBoxDoRecord = new System.Windows.Forms.ComboBox();
            this.labelDoRecord = new System.Windows.Forms.Label();
            this.comboBoxAnon = new System.Windows.Forms.ComboBox();
            this.labelAnon = new System.Windows.Forms.Label();
            this.buttonNameData = new System.Windows.Forms.Button();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBoxReporter = new System.Windows.Forms.TextBox();
            this.labelUnitType = new System.Windows.Forms.Label();
            this.labelAlarmType = new System.Windows.Forms.Label();
            this.labelLocation = new System.Windows.Forms.Label();
            this.labelReporterTele = new System.Windows.Forms.Label();
            this.labelReporter = new System.Windows.Forms.Label();
            this.panelUnitOperate = new System.Windows.Forms.Panel();
            this.buttonDelete = new System.Windows.Forms.Button();
            this.buttonOpToSb = new System.Windows.Forms.Button();
            this.buttonSbToOp = new System.Windows.Forms.Button();
            this.groupBoxOpUnit = new System.Windows.Forms.GroupBox();
            this.listViewOpUnit = new System.Windows.Forms.ListView();
            this.groupBoxStandbyUnit = new System.Windows.Forms.GroupBox();
            this.listViewStandbyUnit = new System.Windows.Forms.ListView();
            this.groupBoxDepartAlter = new System.Windows.Forms.GroupBox();
            this.buttonLiaozhong = new System.Windows.Forms.Button();
            this.buttonBeizhan = new System.Windows.Forms.Button();
            this.buttonHunnan = new System.Windows.Forms.Button();
            this.buttonShenbei = new System.Windows.Forms.Button();
            this.buttonSujiatun = new System.Windows.Forms.Button();
            this.buttonYuhong = new System.Windows.Forms.Button();
            this.buttonKaifaQu = new System.Windows.Forms.Button();
            this.buttonDadong = new System.Windows.Forms.Button();
            this.buttonHuanggu = new System.Windows.Forms.Button();
            this.buttonShenhe = new System.Windows.Forms.Button();
            this.buttonTiexi = new System.Windows.Forms.Button();
            this.buttonHeping = new System.Windows.Forms.Button();
            this.labelOpTips = new System.Windows.Forms.Label();
            this.buttonGenerate = new System.Windows.Forms.Button();
            this.buttonAlarmTrans = new System.Windows.Forms.Button();
            this.buttonMultiOp = new System.Windows.Forms.Button();
            this.panelDataInfo.SuspendLayout();
            this.panelAlarmSettings.SuspendLayout();
            this.groupBoxBrief.SuspendLayout();
            this.panelUnitOperate.SuspendLayout();
            this.groupBoxOpUnit.SuspendLayout();
            this.groupBoxStandbyUnit.SuspendLayout();
            this.groupBoxDepartAlter.SuspendLayout();
            this.SuspendLayout();
            // 
            // panelDataInfo
            // 
            this.panelDataInfo.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panelDataInfo.Controls.Add(this.textDuration);
            this.panelDataInfo.Controls.Add(this.textRecordNum);
            this.panelDataInfo.Controls.Add(this.labelDuration);
            this.panelDataInfo.Controls.Add(this.labelRecordNum);
            this.panelDataInfo.Controls.Add(this.textAlarmTele);
            this.panelDataInfo.Controls.Add(this.textAlarmTime);
            this.panelDataInfo.Controls.Add(this.labelAlarmeTele);
            this.panelDataInfo.Controls.Add(this.labelAlarmTime);
            this.panelDataInfo.Controls.Add(this.textAddress);
            this.panelDataInfo.Controls.Add(this.textAlarmNum);
            this.panelDataInfo.Controls.Add(this.labelAddress);
            this.panelDataInfo.Controls.Add(this.textUserName);
            this.panelDataInfo.Controls.Add(this.labelUserName);
            this.panelDataInfo.Controls.Add(this.labelCaseNum);
            this.panelDataInfo.Location = new System.Drawing.Point(13, 13);
            this.panelDataInfo.Name = "panelDataInfo";
            this.panelDataInfo.Size = new System.Drawing.Size(1035, 67);
            this.panelDataInfo.TabIndex = 0;
            // 
            // textDuration
            // 
            this.textDuration.Location = new System.Drawing.Point(876, 35);
            this.textDuration.Name = "textDuration";
            this.textDuration.Size = new System.Drawing.Size(152, 25);
            this.textDuration.TabIndex = 13;
            // 
            // textRecordNum
            // 
            this.textRecordNum.Location = new System.Drawing.Point(876, 3);
            this.textRecordNum.Name = "textRecordNum";
            this.textRecordNum.Size = new System.Drawing.Size(152, 25);
            this.textRecordNum.TabIndex = 12;
            // 
            // labelDuration
            // 
            this.labelDuration.AutoSize = true;
            this.labelDuration.Font = new System.Drawing.Font("宋体", 10F);
            this.labelDuration.Location = new System.Drawing.Point(793, 38);
            this.labelDuration.Name = "labelDuration";
            this.labelDuration.Size = new System.Drawing.Size(76, 17);
            this.labelDuration.TabIndex = 11;
            this.labelDuration.Text = "通话时长";
            // 
            // labelRecordNum
            // 
            this.labelRecordNum.AutoSize = true;
            this.labelRecordNum.Font = new System.Drawing.Font("宋体", 10F);
            this.labelRecordNum.Location = new System.Drawing.Point(793, 7);
            this.labelRecordNum.Name = "labelRecordNum";
            this.labelRecordNum.Size = new System.Drawing.Size(77, 17);
            this.labelRecordNum.TabIndex = 10;
            this.labelRecordNum.Text = "录 音 号";
            // 
            // textAlarmTele
            // 
            this.textAlarmTele.Location = new System.Drawing.Point(629, 34);
            this.textAlarmTele.Name = "textAlarmTele";
            this.textAlarmTele.Size = new System.Drawing.Size(158, 25);
            this.textAlarmTele.TabIndex = 9;
            // 
            // textAlarmTime
            // 
            this.textAlarmTime.Location = new System.Drawing.Point(629, 3);
            this.textAlarmTime.Name = "textAlarmTime";
            this.textAlarmTime.Size = new System.Drawing.Size(158, 25);
            this.textAlarmTime.TabIndex = 8;
            // 
            // labelAlarmeTele
            // 
            this.labelAlarmeTele.AutoSize = true;
            this.labelAlarmeTele.Font = new System.Drawing.Font("宋体", 10F);
            this.labelAlarmeTele.Location = new System.Drawing.Point(547, 38);
            this.labelAlarmeTele.Name = "labelAlarmeTele";
            this.labelAlarmeTele.Size = new System.Drawing.Size(76, 17);
            this.labelAlarmeTele.TabIndex = 7;
            this.labelAlarmeTele.Text = "报警电话";
            // 
            // labelAlarmTime
            // 
            this.labelAlarmTime.AutoSize = true;
            this.labelAlarmTime.Font = new System.Drawing.Font("宋体", 10F);
            this.labelAlarmTime.Location = new System.Drawing.Point(547, 7);
            this.labelAlarmTime.Name = "labelAlarmTime";
            this.labelAlarmTime.Size = new System.Drawing.Size(76, 17);
            this.labelAlarmTime.TabIndex = 6;
            this.labelAlarmTime.Text = "接警时间";
            // 
            // textAddress
            // 
            this.textAddress.Location = new System.Drawing.Point(226, 34);
            this.textAddress.Name = "textAddress";
            this.textAddress.Size = new System.Drawing.Size(315, 25);
            this.textAddress.TabIndex = 5;
            // 
            // textAlarmNum
            // 
            this.textAlarmNum.Location = new System.Drawing.Point(85, 3);
            this.textAlarmNum.Name = "textAlarmNum";
            this.textAlarmNum.Size = new System.Drawing.Size(456, 25);
            this.textAlarmNum.TabIndex = 0;
            // 
            // labelAddress
            // 
            this.labelAddress.AutoSize = true;
            this.labelAddress.Font = new System.Drawing.Font("宋体", 10F);
            this.labelAddress.Location = new System.Drawing.Point(178, 38);
            this.labelAddress.Name = "labelAddress";
            this.labelAddress.Size = new System.Drawing.Size(42, 17);
            this.labelAddress.TabIndex = 4;
            this.labelAddress.Text = "地址";
            // 
            // textUserName
            // 
            this.textUserName.Location = new System.Drawing.Point(85, 34);
            this.textUserName.Name = "textUserName";
            this.textUserName.Size = new System.Drawing.Size(87, 25);
            this.textUserName.TabIndex = 3;
            // 
            // labelUserName
            // 
            this.labelUserName.AutoSize = true;
            this.labelUserName.Font = new System.Drawing.Font("宋体", 10F);
            this.labelUserName.Location = new System.Drawing.Point(3, 38);
            this.labelUserName.Name = "labelUserName";
            this.labelUserName.Size = new System.Drawing.Size(76, 17);
            this.labelUserName.TabIndex = 2;
            this.labelUserName.Text = "用户姓名";
            // 
            // labelCaseNum
            // 
            this.labelCaseNum.AutoSize = true;
            this.labelCaseNum.Font = new System.Drawing.Font("宋体", 10F);
            this.labelCaseNum.Location = new System.Drawing.Point(3, 7);
            this.labelCaseNum.Name = "labelCaseNum";
            this.labelCaseNum.Size = new System.Drawing.Size(76, 17);
            this.labelCaseNum.TabIndex = 1;
            this.labelCaseNum.Text = "接警单号";
            // 
            // panelAlarmSettings
            // 
            this.panelAlarmSettings.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panelAlarmSettings.Controls.Add(this.groupBoxBrief);
            this.panelAlarmSettings.Controls.Add(this.labelCharger);
            this.panelAlarmSettings.Controls.Add(this.labelSuperior);
            this.panelAlarmSettings.Controls.Add(this.comboBoxCharger);
            this.panelAlarmSettings.Controls.Add(this.comboBoxSuperior);
            this.panelAlarmSettings.Controls.Add(this.comboBoxUnitGroup);
            this.panelAlarmSettings.Controls.Add(this.comboUnitType);
            this.panelAlarmSettings.Controls.Add(this.textBoxAlarmName);
            this.panelAlarmSettings.Controls.Add(this.comboBoxCharType);
            this.panelAlarmSettings.Controls.Add(this.comboBoxChar);
            this.panelAlarmSettings.Controls.Add(this.comboBox1);
            this.panelAlarmSettings.Controls.Add(this.labelChar);
            this.panelAlarmSettings.Controls.Add(this.labelUnitGroup);
            this.panelAlarmSettings.Controls.Add(this.labelAlarmName);
            this.panelAlarmSettings.Controls.Add(this.labelCharType);
            this.panelAlarmSettings.Controls.Add(this.textBoxAdditional);
            this.panelAlarmSettings.Controls.Add(this.labelAdditional);
            this.panelAlarmSettings.Controls.Add(this.comboBoxControlledArticle);
            this.panelAlarmSettings.Controls.Add(this.labelControlledArticle);
            this.panelAlarmSettings.Controls.Add(this.buttonLocating);
            this.panelAlarmSettings.Controls.Add(this.buttonRecorderBase);
            this.panelAlarmSettings.Controls.Add(this.buttonTeleData);
            this.panelAlarmSettings.Controls.Add(this.textBox4);
            this.panelAlarmSettings.Controls.Add(this.comboAlarmType);
            this.panelAlarmSettings.Controls.Add(this.labelCallType);
            this.panelAlarmSettings.Controls.Add(this.textBoxCallRecorder);
            this.panelAlarmSettings.Controls.Add(this.buttonCallRecorder);
            this.panelAlarmSettings.Controls.Add(this.comboBoxRecorderStatus);
            this.panelAlarmSettings.Controls.Add(this.labelRecorderStatus);
            this.panelAlarmSettings.Controls.Add(this.comboBoxDoRecord);
            this.panelAlarmSettings.Controls.Add(this.labelDoRecord);
            this.panelAlarmSettings.Controls.Add(this.comboBoxAnon);
            this.panelAlarmSettings.Controls.Add(this.labelAnon);
            this.panelAlarmSettings.Controls.Add(this.buttonNameData);
            this.panelAlarmSettings.Controls.Add(this.textBox2);
            this.panelAlarmSettings.Controls.Add(this.textBoxReporter);
            this.panelAlarmSettings.Controls.Add(this.labelUnitType);
            this.panelAlarmSettings.Controls.Add(this.labelAlarmType);
            this.panelAlarmSettings.Controls.Add(this.labelLocation);
            this.panelAlarmSettings.Controls.Add(this.labelReporterTele);
            this.panelAlarmSettings.Controls.Add(this.labelReporter);
            this.panelAlarmSettings.Location = new System.Drawing.Point(12, 86);
            this.panelAlarmSettings.Name = "panelAlarmSettings";
            this.panelAlarmSettings.Size = new System.Drawing.Size(1036, 275);
            this.panelAlarmSettings.TabIndex = 1;
            // 
            // groupBoxBrief
            // 
            this.groupBoxBrief.Controls.Add(this.richTextAlarmBrief);
            this.groupBoxBrief.Font = new System.Drawing.Font("宋体", 10F);
            this.groupBoxBrief.Location = new System.Drawing.Point(3, 159);
            this.groupBoxBrief.Name = "groupBoxBrief";
            this.groupBoxBrief.Size = new System.Drawing.Size(1022, 109);
            this.groupBoxBrief.TabIndex = 53;
            this.groupBoxBrief.TabStop = false;
            this.groupBoxBrief.Text = "警情摘要";
            // 
            // richTextAlarmBrief
            // 
            this.richTextAlarmBrief.Location = new System.Drawing.Point(7, 25);
            this.richTextAlarmBrief.Name = "richTextAlarmBrief";
            this.richTextAlarmBrief.Size = new System.Drawing.Size(1009, 78);
            this.richTextAlarmBrief.TabIndex = 0;
            this.richTextAlarmBrief.Text = "";
            // 
            // labelCharger
            // 
            this.labelCharger.AutoSize = true;
            this.labelCharger.Font = new System.Drawing.Font("宋体", 10F);
            this.labelCharger.Location = new System.Drawing.Point(795, 131);
            this.labelCharger.Name = "labelCharger";
            this.labelCharger.Size = new System.Drawing.Size(76, 17);
            this.labelCharger.TabIndex = 52;
            this.labelCharger.Text = "管辖单位";
            // 
            // labelSuperior
            // 
            this.labelSuperior.AutoSize = true;
            this.labelSuperior.Font = new System.Drawing.Font("宋体", 10F);
            this.labelSuperior.Location = new System.Drawing.Point(548, 131);
            this.labelSuperior.Name = "labelSuperior";
            this.labelSuperior.Size = new System.Drawing.Size(76, 17);
            this.labelSuperior.TabIndex = 51;
            this.labelSuperior.Text = "上级单位";
            // 
            // comboBoxCharger
            // 
            this.comboBoxCharger.Font = new System.Drawing.Font("宋体", 10F);
            this.comboBoxCharger.FormattingEnabled = true;
            this.comboBoxCharger.Items.AddRange(new object[] {
            "和平分局",
            "铁西分局",
            "沈河分局",
            "皇姑分局",
            "大东分局",
            "于洪分局",
            "苏家屯分局",
            "沈北新区分局",
            "浑南分局",
            "北站地区分局",
            "经济技术开发区分局",
            "辽中分局"});
            this.comboBoxCharger.Location = new System.Drawing.Point(877, 127);
            this.comboBoxCharger.Name = "comboBoxCharger";
            this.comboBoxCharger.Size = new System.Drawing.Size(152, 25);
            this.comboBoxCharger.TabIndex = 50;
            // 
            // comboBoxSuperior
            // 
            this.comboBoxSuperior.Font = new System.Drawing.Font("宋体", 10F);
            this.comboBoxSuperior.FormattingEnabled = true;
            this.comboBoxSuperior.Items.AddRange(new object[] {
            "分局指挥中心",
            "市局指挥中心",
            "省局指挥中心",
            "军区指挥中心"});
            this.comboBoxSuperior.Location = new System.Drawing.Point(630, 128);
            this.comboBoxSuperior.Name = "comboBoxSuperior";
            this.comboBoxSuperior.Size = new System.Drawing.Size(159, 25);
            this.comboBoxSuperior.TabIndex = 49;
            // 
            // comboBoxUnitGroup
            // 
            this.comboBoxUnitGroup.Font = new System.Drawing.Font("宋体", 10F);
            this.comboBoxUnitGroup.FormattingEnabled = true;
            this.comboBoxUnitGroup.Items.AddRange(new object[] {
            "乡/镇",
            "区辖",
            "市辖",
            "省辖",
            "跨省",
            "跨国"});
            this.comboBoxUnitGroup.Location = new System.Drawing.Point(354, 127);
            this.comboBoxUnitGroup.Name = "comboBoxUnitGroup";
            this.comboBoxUnitGroup.Size = new System.Drawing.Size(188, 25);
            this.comboBoxUnitGroup.TabIndex = 48;
            // 
            // comboUnitType
            // 
            this.comboUnitType.Font = new System.Drawing.Font("宋体", 10F);
            this.comboUnitType.FormattingEnabled = true;
            this.comboUnitType.Items.AddRange(new object[] {
            "派出机构",
            "执法勤务机构",
            "综合管理机构"});
            this.comboUnitType.Location = new System.Drawing.Point(86, 127);
            this.comboUnitType.Name = "comboUnitType";
            this.comboUnitType.Size = new System.Drawing.Size(180, 25);
            this.comboUnitType.TabIndex = 47;
            // 
            // textBoxAlarmName
            // 
            this.textBoxAlarmName.Location = new System.Drawing.Point(877, 96);
            this.textBoxAlarmName.Name = "textBoxAlarmName";
            this.textBoxAlarmName.Size = new System.Drawing.Size(152, 25);
            this.textBoxAlarmName.TabIndex = 46;
            // 
            // comboBoxCharType
            // 
            this.comboBoxCharType.Font = new System.Drawing.Font("宋体", 10F);
            this.comboBoxCharType.FormattingEnabled = true;
            this.comboBoxCharType.Items.AddRange(new object[] {
            "情节较轻",
            "情节中等",
            "情节较大",
            "情节特大"});
            this.comboBoxCharType.Location = new System.Drawing.Point(630, 96);
            this.comboBoxCharType.Name = "comboBoxCharType";
            this.comboBoxCharType.Size = new System.Drawing.Size(158, 25);
            this.comboBoxCharType.TabIndex = 45;
            // 
            // comboBoxChar
            // 
            this.comboBoxChar.Font = new System.Drawing.Font("宋体", 10F);
            this.comboBoxChar.FormattingEnabled = true;
            this.comboBoxChar.Items.AddRange(new object[] {
            "盗窃抢劫",
            "勒索诈骗",
            "寻衅滋事",
            "故意伤害",
            "社区纠纷"});
            this.comboBoxChar.Location = new System.Drawing.Point(354, 96);
            this.comboBoxChar.Name = "comboBoxChar";
            this.comboBoxChar.Size = new System.Drawing.Size(188, 25);
            this.comboBoxChar.TabIndex = 44;
            // 
            // comboBox1
            // 
            this.comboBox1.Font = new System.Drawing.Font("宋体", 10F);
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "刑事案件",
            "民事案件",
            "国家机密"});
            this.comboBox1.Location = new System.Drawing.Point(86, 96);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(180, 25);
            this.comboBox1.TabIndex = 43;
            // 
            // labelChar
            // 
            this.labelChar.AutoSize = true;
            this.labelChar.Font = new System.Drawing.Font("宋体", 10F);
            this.labelChar.Location = new System.Drawing.Point(272, 100);
            this.labelChar.Name = "labelChar";
            this.labelChar.Size = new System.Drawing.Size(76, 17);
            this.labelChar.TabIndex = 42;
            this.labelChar.Text = "报案性质";
            // 
            // labelUnitGroup
            // 
            this.labelUnitGroup.AutoSize = true;
            this.labelUnitGroup.Font = new System.Drawing.Font("宋体", 10F);
            this.labelUnitGroup.Location = new System.Drawing.Point(272, 131);
            this.labelUnitGroup.Name = "labelUnitGroup";
            this.labelUnitGroup.Size = new System.Drawing.Size(76, 17);
            this.labelUnitGroup.TabIndex = 41;
            this.labelUnitGroup.Text = "⁭单位分组";
            // 
            // labelAlarmName
            // 
            this.labelAlarmName.AutoSize = true;
            this.labelAlarmName.Font = new System.Drawing.Font("宋体", 10F);
            this.labelAlarmName.Location = new System.Drawing.Point(795, 100);
            this.labelAlarmName.Name = "labelAlarmName";
            this.labelAlarmName.Size = new System.Drawing.Size(76, 17);
            this.labelAlarmName.TabIndex = 40;
            this.labelAlarmName.Text = "报案名称";
            // 
            // labelCharType
            // 
            this.labelCharType.AutoSize = true;
            this.labelCharType.Font = new System.Drawing.Font("宋体", 10F);
            this.labelCharType.Location = new System.Drawing.Point(548, 100);
            this.labelCharType.Name = "labelCharType";
            this.labelCharType.Size = new System.Drawing.Size(76, 17);
            this.labelCharType.TabIndex = 39;
            this.labelCharType.Text = "性质分类";
            // 
            // textBoxAdditional
            // 
            this.textBoxAdditional.Location = new System.Drawing.Point(877, 65);
            this.textBoxAdditional.Name = "textBoxAdditional";
            this.textBoxAdditional.Size = new System.Drawing.Size(152, 25);
            this.textBoxAdditional.TabIndex = 14;
            // 
            // labelAdditional
            // 
            this.labelAdditional.AutoSize = true;
            this.labelAdditional.Font = new System.Drawing.Font("宋体", 10F);
            this.labelAdditional.Location = new System.Drawing.Point(795, 69);
            this.labelAdditional.Name = "labelAdditional";
            this.labelAdditional.Size = new System.Drawing.Size(76, 17);
            this.labelAdditional.TabIndex = 38;
            this.labelAdditional.Text = "情况补充";
            // 
            // comboBoxControlledArticle
            // 
            this.comboBoxControlledArticle.Font = new System.Drawing.Font("宋体", 10F);
            this.comboBoxControlledArticle.FormattingEnabled = true;
            this.comboBoxControlledArticle.Items.AddRange(new object[] {
            "有",
            "无"});
            this.comboBoxControlledArticle.Location = new System.Drawing.Point(718, 66);
            this.comboBoxControlledArticle.Name = "comboBoxControlledArticle";
            this.comboBoxControlledArticle.Size = new System.Drawing.Size(71, 25);
            this.comboBoxControlledArticle.TabIndex = 37;
            // 
            // labelControlledArticle
            // 
            this.labelControlledArticle.AutoSize = true;
            this.labelControlledArticle.Font = new System.Drawing.Font("宋体", 10F);
            this.labelControlledArticle.Location = new System.Drawing.Point(636, 69);
            this.labelControlledArticle.Name = "labelControlledArticle";
            this.labelControlledArticle.Size = new System.Drawing.Size(76, 17);
            this.labelControlledArticle.TabIndex = 36;
            this.labelControlledArticle.Text = "管制物品";
            // 
            // buttonLocating
            // 
            this.buttonLocating.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("buttonLocating.BackgroundImage")));
            this.buttonLocating.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.buttonLocating.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonLocating.Font = new System.Drawing.Font("宋体", 10F);
            this.buttonLocating.Location = new System.Drawing.Point(546, 65);
            this.buttonLocating.Name = "buttonLocating";
            this.buttonLocating.Size = new System.Drawing.Size(84, 25);
            this.buttonLocating.TabIndex = 35;
            this.buttonLocating.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.buttonLocating.UseVisualStyleBackColor = true;
            // 
            // buttonRecorderBase
            // 
            this.buttonRecorderBase.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("buttonRecorderBase.BackgroundImage")));
            this.buttonRecorderBase.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.buttonRecorderBase.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonRecorderBase.Font = new System.Drawing.Font("宋体", 10F);
            this.buttonRecorderBase.Location = new System.Drawing.Point(546, 34);
            this.buttonRecorderBase.Name = "buttonRecorderBase";
            this.buttonRecorderBase.Size = new System.Drawing.Size(84, 25);
            this.buttonRecorderBase.TabIndex = 34;
            this.buttonRecorderBase.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.buttonRecorderBase.UseVisualStyleBackColor = true;
            // 
            // buttonTeleData
            // 
            this.buttonTeleData.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("buttonTeleData.BackgroundImage")));
            this.buttonTeleData.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.buttonTeleData.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonTeleData.Font = new System.Drawing.Font("宋体", 10F);
            this.buttonTeleData.Location = new System.Drawing.Point(275, 34);
            this.buttonTeleData.Name = "buttonTeleData";
            this.buttonTeleData.Size = new System.Drawing.Size(62, 25);
            this.buttonTeleData.TabIndex = 33;
            this.buttonTeleData.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.buttonTeleData.UseVisualStyleBackColor = true;
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(86, 65);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(456, 25);
            this.textBox4.TabIndex = 32;
            // 
            // comboAlarmType
            // 
            this.comboAlarmType.Font = new System.Drawing.Font("宋体", 10F);
            this.comboAlarmType.FormattingEnabled = true;
            this.comboAlarmType.Items.AddRange(new object[] {
            "报警或求助",
            "咨询或投诉",
            "恶作剧"});
            this.comboAlarmType.Location = new System.Drawing.Point(630, 3);
            this.comboAlarmType.Name = "comboAlarmType";
            this.comboAlarmType.Size = new System.Drawing.Size(158, 25);
            this.comboAlarmType.TabIndex = 31;
            // 
            // labelCallType
            // 
            this.labelCallType.AutoSize = true;
            this.labelCallType.Font = new System.Drawing.Font("宋体", 10F);
            this.labelCallType.Location = new System.Drawing.Point(548, 7);
            this.labelCallType.Name = "labelCallType";
            this.labelCallType.Size = new System.Drawing.Size(76, 17);
            this.labelCallType.TabIndex = 30;
            this.labelCallType.Text = "来话类别";
            // 
            // textBoxCallRecorder
            // 
            this.textBoxCallRecorder.Location = new System.Drawing.Point(743, 34);
            this.textBoxCallRecorder.Name = "textBoxCallRecorder";
            this.textBoxCallRecorder.Size = new System.Drawing.Size(286, 25);
            this.textBoxCallRecorder.TabIndex = 29;
            // 
            // buttonCallRecorder
            // 
            this.buttonCallRecorder.Font = new System.Drawing.Font("宋体", 10F);
            this.buttonCallRecorder.Location = new System.Drawing.Point(636, 34);
            this.buttonCallRecorder.Name = "buttonCallRecorder";
            this.buttonCallRecorder.Size = new System.Drawing.Size(101, 25);
            this.buttonCallRecorder.TabIndex = 28;
            this.buttonCallRecorder.Text = "回呼录音→";
            this.buttonCallRecorder.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.buttonCallRecorder.UseVisualStyleBackColor = true;
            this.buttonCallRecorder.Click += new System.EventHandler(this.buttonCallRecorder_Click);
            // 
            // comboBoxRecorderStatus
            // 
            this.comboBoxRecorderStatus.Font = new System.Drawing.Font("宋体", 10F);
            this.comboBoxRecorderStatus.FormattingEnabled = true;
            this.comboBoxRecorderStatus.Items.AddRange(new object[] {
            "可用",
            "不可用"});
            this.comboBoxRecorderStatus.Location = new System.Drawing.Point(425, 34);
            this.comboBoxRecorderStatus.Name = "comboBoxRecorderStatus";
            this.comboBoxRecorderStatus.Size = new System.Drawing.Size(117, 25);
            this.comboBoxRecorderStatus.TabIndex = 26;
            // 
            // labelRecorderStatus
            // 
            this.labelRecorderStatus.AutoSize = true;
            this.labelRecorderStatus.Font = new System.Drawing.Font("宋体", 10F);
            this.labelRecorderStatus.Location = new System.Drawing.Point(343, 38);
            this.labelRecorderStatus.Name = "labelRecorderStatus";
            this.labelRecorderStatus.Size = new System.Drawing.Size(76, 17);
            this.labelRecorderStatus.TabIndex = 25;
            this.labelRecorderStatus.Text = "话机状态";
            // 
            // comboBoxDoRecord
            // 
            this.comboBoxDoRecord.Font = new System.Drawing.Font("宋体", 10F);
            this.comboBoxDoRecord.FormattingEnabled = true;
            this.comboBoxDoRecord.Items.AddRange(new object[] {
            "全部开放",
            "需要权限",
            "物理存储"});
            this.comboBoxDoRecord.Location = new System.Drawing.Point(877, 3);
            this.comboBoxDoRecord.Name = "comboBoxDoRecord";
            this.comboBoxDoRecord.Size = new System.Drawing.Size(152, 25);
            this.comboBoxDoRecord.TabIndex = 24;
            // 
            // labelDoRecord
            // 
            this.labelDoRecord.AutoSize = true;
            this.labelDoRecord.Font = new System.Drawing.Font("宋体", 10F);
            this.labelDoRecord.Location = new System.Drawing.Point(795, 7);
            this.labelDoRecord.Name = "labelDoRecord";
            this.labelDoRecord.Size = new System.Drawing.Size(76, 17);
            this.labelDoRecord.TabIndex = 23;
            this.labelDoRecord.Text = "开放录音";
            // 
            // comboBoxAnon
            // 
            this.comboBoxAnon.Font = new System.Drawing.Font("宋体", 10F);
            this.comboBoxAnon.FormattingEnabled = true;
            this.comboBoxAnon.Items.AddRange(new object[] {
            "是",
            "否"});
            this.comboBoxAnon.Location = new System.Drawing.Point(425, 3);
            this.comboBoxAnon.Name = "comboBoxAnon";
            this.comboBoxAnon.Size = new System.Drawing.Size(117, 25);
            this.comboBoxAnon.TabIndex = 22;
            // 
            // labelAnon
            // 
            this.labelAnon.AutoSize = true;
            this.labelAnon.Font = new System.Drawing.Font("宋体", 10F);
            this.labelAnon.Location = new System.Drawing.Point(343, 7);
            this.labelAnon.Name = "labelAnon";
            this.labelAnon.Size = new System.Drawing.Size(76, 17);
            this.labelAnon.TabIndex = 21;
            this.labelAnon.Text = "是否匿名";
            // 
            // buttonNameData
            // 
            this.buttonNameData.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("buttonNameData.BackgroundImage")));
            this.buttonNameData.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.buttonNameData.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.buttonNameData.Font = new System.Drawing.Font("宋体", 10F);
            this.buttonNameData.ImageAlign = System.Drawing.ContentAlignment.TopCenter;
            this.buttonNameData.Location = new System.Drawing.Point(275, 3);
            this.buttonNameData.Name = "buttonNameData";
            this.buttonNameData.Size = new System.Drawing.Size(62, 25);
            this.buttonNameData.TabIndex = 20;
            this.buttonNameData.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.buttonNameData.UseVisualStyleBackColor = true;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(86, 34);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(183, 25);
            this.textBox2.TabIndex = 19;
            // 
            // textBoxReporter
            // 
            this.textBoxReporter.Location = new System.Drawing.Point(86, 3);
            this.textBoxReporter.Name = "textBoxReporter";
            this.textBoxReporter.Size = new System.Drawing.Size(183, 25);
            this.textBoxReporter.TabIndex = 14;
            // 
            // labelUnitType
            // 
            this.labelUnitType.AutoSize = true;
            this.labelUnitType.Font = new System.Drawing.Font("宋体", 10F);
            this.labelUnitType.Location = new System.Drawing.Point(6, 131);
            this.labelUnitType.Name = "labelUnitType";
            this.labelUnitType.Size = new System.Drawing.Size(76, 17);
            this.labelUnitType.TabIndex = 14;
            this.labelUnitType.Text = "单位类型";
            // 
            // labelAlarmType
            // 
            this.labelAlarmType.AutoSize = true;
            this.labelAlarmType.Font = new System.Drawing.Font("宋体", 10F);
            this.labelAlarmType.Location = new System.Drawing.Point(4, 100);
            this.labelAlarmType.Name = "labelAlarmType";
            this.labelAlarmType.Size = new System.Drawing.Size(76, 17);
            this.labelAlarmType.TabIndex = 15;
            this.labelAlarmType.Text = "报案类型";
            // 
            // labelLocation
            // 
            this.labelLocation.AutoSize = true;
            this.labelLocation.Font = new System.Drawing.Font("宋体", 10F);
            this.labelLocation.Location = new System.Drawing.Point(4, 69);
            this.labelLocation.Name = "labelLocation";
            this.labelLocation.Size = new System.Drawing.Size(76, 17);
            this.labelLocation.TabIndex = 16;
            this.labelLocation.Text = "事发地点";
            // 
            // labelReporterTele
            // 
            this.labelReporterTele.AutoSize = true;
            this.labelReporterTele.Font = new System.Drawing.Font("宋体", 10F);
            this.labelReporterTele.Location = new System.Drawing.Point(5, 38);
            this.labelReporterTele.Name = "labelReporterTele";
            this.labelReporterTele.Size = new System.Drawing.Size(76, 17);
            this.labelReporterTele.TabIndex = 17;
            this.labelReporterTele.Text = "联系电话";
            // 
            // labelReporter
            // 
            this.labelReporter.AutoSize = true;
            this.labelReporter.Font = new System.Drawing.Font("宋体", 10F);
            this.labelReporter.Location = new System.Drawing.Point(5, 7);
            this.labelReporter.Name = "labelReporter";
            this.labelReporter.Size = new System.Drawing.Size(77, 17);
            this.labelReporter.TabIndex = 18;
            this.labelReporter.Text = "报 警 人";
            // 
            // panelUnitOperate
            // 
            this.panelUnitOperate.Controls.Add(this.buttonDelete);
            this.panelUnitOperate.Controls.Add(this.buttonOpToSb);
            this.panelUnitOperate.Controls.Add(this.buttonSbToOp);
            this.panelUnitOperate.Controls.Add(this.groupBoxOpUnit);
            this.panelUnitOperate.Controls.Add(this.groupBoxStandbyUnit);
            this.panelUnitOperate.Controls.Add(this.groupBoxDepartAlter);
            this.panelUnitOperate.Location = new System.Drawing.Point(13, 368);
            this.panelUnitOperate.Name = "panelUnitOperate";
            this.panelUnitOperate.Size = new System.Drawing.Size(1035, 158);
            this.panelUnitOperate.TabIndex = 2;
            // 
            // buttonDelete
            // 
            this.buttonDelete.Location = new System.Drawing.Point(753, 118);
            this.buttonDelete.Name = "buttonDelete";
            this.buttonDelete.Size = new System.Drawing.Size(68, 23);
            this.buttonDelete.TabIndex = 9;
            this.buttonDelete.Text = "删除";
            this.buttonDelete.UseVisualStyleBackColor = true;
            this.buttonDelete.Click += new System.EventHandler(this.buttonDelete_Click);
            // 
            // buttonOpToSb
            // 
            this.buttonOpToSb.Location = new System.Drawing.Point(753, 75);
            this.buttonOpToSb.Name = "buttonOpToSb";
            this.buttonOpToSb.Size = new System.Drawing.Size(68, 23);
            this.buttonOpToSb.TabIndex = 8;
            this.buttonOpToSb.Text = "<<";
            this.buttonOpToSb.UseVisualStyleBackColor = true;
            this.buttonOpToSb.Click += new System.EventHandler(this.buttonOpToSb_Click);
            // 
            // buttonSbToOp
            // 
            this.buttonSbToOp.Location = new System.Drawing.Point(753, 32);
            this.buttonSbToOp.Name = "buttonSbToOp";
            this.buttonSbToOp.Size = new System.Drawing.Size(68, 23);
            this.buttonSbToOp.TabIndex = 7;
            this.buttonSbToOp.Text = ">>";
            this.buttonSbToOp.UseVisualStyleBackColor = true;
            this.buttonSbToOp.Click += new System.EventHandler(this.buttonSbToOp_Click);
            // 
            // groupBoxOpUnit
            // 
            this.groupBoxOpUnit.Controls.Add(this.listViewOpUnit);
            this.groupBoxOpUnit.Location = new System.Drawing.Point(836, 4);
            this.groupBoxOpUnit.Name = "groupBoxOpUnit";
            this.groupBoxOpUnit.Size = new System.Drawing.Size(194, 151);
            this.groupBoxOpUnit.TabIndex = 2;
            this.groupBoxOpUnit.TabStop = false;
            this.groupBoxOpUnit.Text = "已调度单位";
            // 
            // listViewOpUnit
            // 
            this.listViewOpUnit.HideSelection = false;
            this.listViewOpUnit.Location = new System.Drawing.Point(7, 25);
            this.listViewOpUnit.Name = "listViewOpUnit";
            this.listViewOpUnit.Size = new System.Drawing.Size(181, 120);
            this.listViewOpUnit.TabIndex = 0;
            this.listViewOpUnit.UseCompatibleStateImageBehavior = false;
            this.listViewOpUnit.View = System.Windows.Forms.View.List;
            // 
            // groupBoxStandbyUnit
            // 
            this.groupBoxStandbyUnit.Controls.Add(this.listViewStandbyUnit);
            this.groupBoxStandbyUnit.Location = new System.Drawing.Point(552, 4);
            this.groupBoxStandbyUnit.Name = "groupBoxStandbyUnit";
            this.groupBoxStandbyUnit.Size = new System.Drawing.Size(186, 151);
            this.groupBoxStandbyUnit.TabIndex = 1;
            this.groupBoxStandbyUnit.TabStop = false;
            this.groupBoxStandbyUnit.Text = "待调度单位";
            // 
            // listViewStandbyUnit
            // 
            this.listViewStandbyUnit.Activation = System.Windows.Forms.ItemActivation.OneClick;
            this.listViewStandbyUnit.Font = new System.Drawing.Font("宋体", 10F);
            this.listViewStandbyUnit.GridLines = true;
            this.listViewStandbyUnit.HideSelection = false;
            this.listViewStandbyUnit.Location = new System.Drawing.Point(7, 25);
            this.listViewStandbyUnit.Name = "listViewStandbyUnit";
            this.listViewStandbyUnit.Size = new System.Drawing.Size(173, 120);
            this.listViewStandbyUnit.TabIndex = 0;
            this.listViewStandbyUnit.UseCompatibleStateImageBehavior = false;
            this.listViewStandbyUnit.View = System.Windows.Forms.View.List;
            // 
            // groupBoxDepartAlter
            // 
            this.groupBoxDepartAlter.BackColor = System.Drawing.SystemColors.Control;
            this.groupBoxDepartAlter.Controls.Add(this.buttonLiaozhong);
            this.groupBoxDepartAlter.Controls.Add(this.buttonBeizhan);
            this.groupBoxDepartAlter.Controls.Add(this.buttonHunnan);
            this.groupBoxDepartAlter.Controls.Add(this.buttonShenbei);
            this.groupBoxDepartAlter.Controls.Add(this.buttonSujiatun);
            this.groupBoxDepartAlter.Controls.Add(this.buttonYuhong);
            this.groupBoxDepartAlter.Controls.Add(this.buttonKaifaQu);
            this.groupBoxDepartAlter.Controls.Add(this.buttonDadong);
            this.groupBoxDepartAlter.Controls.Add(this.buttonHuanggu);
            this.groupBoxDepartAlter.Controls.Add(this.buttonShenhe);
            this.groupBoxDepartAlter.Controls.Add(this.buttonTiexi);
            this.groupBoxDepartAlter.Controls.Add(this.buttonHeping);
            this.groupBoxDepartAlter.Controls.Add(this.labelOpTips);
            this.groupBoxDepartAlter.Font = new System.Drawing.Font("宋体", 10F);
            this.groupBoxDepartAlter.ForeColor = System.Drawing.SystemColors.ControlText;
            this.groupBoxDepartAlter.Location = new System.Drawing.Point(11, 4);
            this.groupBoxDepartAlter.Name = "groupBoxDepartAlter";
            this.groupBoxDepartAlter.Size = new System.Drawing.Size(532, 151);
            this.groupBoxDepartAlter.TabIndex = 0;
            this.groupBoxDepartAlter.TabStop = false;
            this.groupBoxDepartAlter.Text = "选择分局";
            // 
            // buttonLiaozhong
            // 
            this.buttonLiaozhong.Location = new System.Drawing.Point(7, 114);
            this.buttonLiaozhong.Name = "buttonLiaozhong";
            this.buttonLiaozhong.Size = new System.Drawing.Size(84, 23);
            this.buttonLiaozhong.TabIndex = 13;
            this.buttonLiaozhong.Text = "辽中分局";
            this.buttonLiaozhong.UseVisualStyleBackColor = true;
            this.buttonLiaozhong.MouseDown += new System.Windows.Forms.MouseEventHandler(this.buttonDeparment_Click);
            // 
            // buttonBeizhan
            // 
            this.buttonBeizhan.Location = new System.Drawing.Point(97, 85);
            this.buttonBeizhan.Name = "buttonBeizhan";
            this.buttonBeizhan.Size = new System.Drawing.Size(174, 23);
            this.buttonBeizhan.TabIndex = 12;
            this.buttonBeizhan.Text = "北站地区分局";
            this.buttonBeizhan.UseVisualStyleBackColor = true;
            this.buttonBeizhan.MouseDown += new System.Windows.Forms.MouseEventHandler(this.buttonDeparment_Click);
            // 
            // buttonHunnan
            // 
            this.buttonHunnan.Location = new System.Drawing.Point(7, 85);
            this.buttonHunnan.Name = "buttonHunnan";
            this.buttonHunnan.Size = new System.Drawing.Size(84, 23);
            this.buttonHunnan.TabIndex = 11;
            this.buttonHunnan.Text = "浑南分局";
            this.buttonHunnan.UseVisualStyleBackColor = true;
            this.buttonHunnan.MouseDown += new System.Windows.Forms.MouseEventHandler(this.buttonDeparment_Click);
            // 
            // buttonShenbei
            // 
            this.buttonShenbei.Location = new System.Drawing.Point(277, 56);
            this.buttonShenbei.Name = "buttonShenbei";
            this.buttonShenbei.Size = new System.Drawing.Size(174, 23);
            this.buttonShenbei.TabIndex = 10;
            this.buttonShenbei.Text = "沈北新区分局";
            this.buttonShenbei.UseVisualStyleBackColor = true;
            this.buttonShenbei.MouseDown += new System.Windows.Forms.MouseEventHandler(this.buttonDeparment_Click);
            // 
            // buttonSujiatun
            // 
            this.buttonSujiatun.Location = new System.Drawing.Point(97, 56);
            this.buttonSujiatun.Name = "buttonSujiatun";
            this.buttonSujiatun.Size = new System.Drawing.Size(174, 23);
            this.buttonSujiatun.TabIndex = 9;
            this.buttonSujiatun.Text = "苏家屯分局";
            this.buttonSujiatun.UseVisualStyleBackColor = true;
            this.buttonSujiatun.MouseDown += new System.Windows.Forms.MouseEventHandler(this.buttonDeparment_Click);
            // 
            // buttonYuhong
            // 
            this.buttonYuhong.Location = new System.Drawing.Point(7, 56);
            this.buttonYuhong.Name = "buttonYuhong";
            this.buttonYuhong.Size = new System.Drawing.Size(84, 23);
            this.buttonYuhong.TabIndex = 8;
            this.buttonYuhong.Text = "于洪分局";
            this.buttonYuhong.UseVisualStyleBackColor = true;
            this.buttonYuhong.MouseDown += new System.Windows.Forms.MouseEventHandler(this.buttonDeparment_Click);
            // 
            // buttonKaifaQu
            // 
            this.buttonKaifaQu.Location = new System.Drawing.Point(277, 85);
            this.buttonKaifaQu.Name = "buttonKaifaQu";
            this.buttonKaifaQu.Size = new System.Drawing.Size(174, 23);
            this.buttonKaifaQu.TabIndex = 6;
            this.buttonKaifaQu.Text = "经济技术开发区分局";
            this.buttonKaifaQu.UseVisualStyleBackColor = true;
            this.buttonKaifaQu.MouseDown += new System.Windows.Forms.MouseEventHandler(this.buttonDeparment_Click);
            // 
            // buttonDadong
            // 
            this.buttonDadong.Location = new System.Drawing.Point(367, 27);
            this.buttonDadong.Name = "buttonDadong";
            this.buttonDadong.Size = new System.Drawing.Size(84, 23);
            this.buttonDadong.TabIndex = 5;
            this.buttonDadong.Text = "大东分局";
            this.buttonDadong.UseVisualStyleBackColor = true;
            this.buttonDadong.MouseDown += new System.Windows.Forms.MouseEventHandler(this.buttonDeparment_Click);
            // 
            // buttonHuanggu
            // 
            this.buttonHuanggu.Location = new System.Drawing.Point(277, 27);
            this.buttonHuanggu.Name = "buttonHuanggu";
            this.buttonHuanggu.Size = new System.Drawing.Size(84, 23);
            this.buttonHuanggu.TabIndex = 4;
            this.buttonHuanggu.Text = "皇姑分局";
            this.buttonHuanggu.UseVisualStyleBackColor = true;
            this.buttonHuanggu.MouseDown += new System.Windows.Forms.MouseEventHandler(this.buttonDeparment_Click);
            // 
            // buttonShenhe
            // 
            this.buttonShenhe.Location = new System.Drawing.Point(187, 27);
            this.buttonShenhe.Name = "buttonShenhe";
            this.buttonShenhe.Size = new System.Drawing.Size(84, 23);
            this.buttonShenhe.TabIndex = 3;
            this.buttonShenhe.Text = "沈河分局";
            this.buttonShenhe.UseVisualStyleBackColor = true;
            this.buttonShenhe.MouseDown += new System.Windows.Forms.MouseEventHandler(this.buttonDeparment_Click);
            // 
            // buttonTiexi
            // 
            this.buttonTiexi.Location = new System.Drawing.Point(97, 27);
            this.buttonTiexi.Name = "buttonTiexi";
            this.buttonTiexi.Size = new System.Drawing.Size(84, 23);
            this.buttonTiexi.TabIndex = 2;
            this.buttonTiexi.Text = "铁西分局";
            this.buttonTiexi.UseVisualStyleBackColor = true;
            this.buttonTiexi.MouseDown += new System.Windows.Forms.MouseEventHandler(this.buttonDeparment_Click);
            // 
            // buttonHeping
            // 
            this.buttonHeping.Location = new System.Drawing.Point(7, 27);
            this.buttonHeping.Name = "buttonHeping";
            this.buttonHeping.Size = new System.Drawing.Size(84, 23);
            this.buttonHeping.TabIndex = 1;
            this.buttonHeping.Text = "和平分局";
            this.buttonHeping.UseVisualStyleBackColor = true;
            this.buttonHeping.MouseDown += new System.Windows.Forms.MouseEventHandler(this.buttonDeparment_Click);
            // 
            // labelOpTips
            // 
            this.labelOpTips.AutoSize = true;
            this.labelOpTips.BackColor = System.Drawing.SystemColors.Control;
            this.labelOpTips.Font = new System.Drawing.Font("宋体", 7.8F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.labelOpTips.ForeColor = System.Drawing.SystemColors.ControlDarkDark;
            this.labelOpTips.Location = new System.Drawing.Point(93, 0);
            this.labelOpTips.Name = "labelOpTips";
            this.labelOpTips.Size = new System.Drawing.Size(245, 13);
            this.labelOpTips.TabIndex = 0;
            this.labelOpTips.Text = "左键添加至待调度，右键添加至已调度";
            // 
            // buttonGenerate
            // 
            this.buttonGenerate.Font = new System.Drawing.Font("宋体", 12F);
            this.buttonGenerate.Location = new System.Drawing.Point(931, 532);
            this.buttonGenerate.Name = "buttonGenerate";
            this.buttonGenerate.Size = new System.Drawing.Size(117, 29);
            this.buttonGenerate.TabIndex = 3;
            this.buttonGenerate.Text = "生成接警单";
            this.buttonGenerate.UseVisualStyleBackColor = true;
            this.buttonGenerate.Click += new System.EventHandler(this.buttonGenerate_Click);
            // 
            // buttonAlarmTrans
            // 
            this.buttonAlarmTrans.Font = new System.Drawing.Font("宋体", 12F);
            this.buttonAlarmTrans.Location = new System.Drawing.Point(808, 532);
            this.buttonAlarmTrans.Name = "buttonAlarmTrans";
            this.buttonAlarmTrans.Size = new System.Drawing.Size(98, 29);
            this.buttonAlarmTrans.TabIndex = 5;
            this.buttonAlarmTrans.Text = "警情转移";
            this.buttonAlarmTrans.UseVisualStyleBackColor = true;
            this.buttonAlarmTrans.Click += new System.EventHandler(this.buttonAlarmTrans_Click);
            // 
            // buttonMultiOp
            // 
            this.buttonMultiOp.Font = new System.Drawing.Font("宋体", 12F);
            this.buttonMultiOp.Location = new System.Drawing.Point(12, 532);
            this.buttonMultiOp.Name = "buttonMultiOp";
            this.buttonMultiOp.Size = new System.Drawing.Size(105, 29);
            this.buttonMultiOp.TabIndex = 7;
            this.buttonMultiOp.Text = "多方协警";
            this.buttonMultiOp.UseVisualStyleBackColor = true;
            this.buttonMultiOp.Click += new System.EventHandler(this.buttonMultiOp_Click);
            // 
            // FormAlarm
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(1060, 573);
            this.Controls.Add(this.buttonMultiOp);
            this.Controls.Add(this.buttonAlarmTrans);
            this.Controls.Add(this.buttonGenerate);
            this.Controls.Add(this.panelUnitOperate);
            this.Controls.Add(this.panelAlarmSettings);
            this.Controls.Add(this.panelDataInfo);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "FormAlarm";
            this.Text = "接警窗口";
            this.panelDataInfo.ResumeLayout(false);
            this.panelDataInfo.PerformLayout();
            this.panelAlarmSettings.ResumeLayout(false);
            this.panelAlarmSettings.PerformLayout();
            this.groupBoxBrief.ResumeLayout(false);
            this.panelUnitOperate.ResumeLayout(false);
            this.groupBoxOpUnit.ResumeLayout(false);
            this.groupBoxStandbyUnit.ResumeLayout(false);
            this.groupBoxDepartAlter.ResumeLayout(false);
            this.groupBoxDepartAlter.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel panelDataInfo;
        private System.Windows.Forms.Label labelCaseNum;
        private System.Windows.Forms.TextBox textAlarmNum;
        private System.Windows.Forms.TextBox textAddress;
        private System.Windows.Forms.Label labelAddress;
        private System.Windows.Forms.TextBox textUserName;
        private System.Windows.Forms.Label labelUserName;
        private System.Windows.Forms.Label labelAlarmeTele;
        private System.Windows.Forms.Label labelAlarmTime;
        private System.Windows.Forms.TextBox textAlarmTele;
        private System.Windows.Forms.TextBox textAlarmTime;
        private System.Windows.Forms.TextBox textDuration;
        private System.Windows.Forms.TextBox textRecordNum;
        private System.Windows.Forms.Label labelDuration;
        private System.Windows.Forms.Label labelRecordNum;
        private System.Windows.Forms.Panel panelAlarmSettings;
        private System.Windows.Forms.Label labelUnitType;
        private System.Windows.Forms.Label labelAlarmType;
        private System.Windows.Forms.Label labelLocation;
        private System.Windows.Forms.Label labelReporterTele;
        private System.Windows.Forms.Label labelReporter;
        private System.Windows.Forms.TextBox textBoxReporter;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Button buttonNameData;
        private System.Windows.Forms.Label labelAnon;
        private System.Windows.Forms.ComboBox comboBoxAnon;
        private System.Windows.Forms.ComboBox comboBoxRecorderStatus;
        private System.Windows.Forms.Label labelRecorderStatus;
        private System.Windows.Forms.ComboBox comboBoxDoRecord;
        private System.Windows.Forms.Label labelDoRecord;
        private System.Windows.Forms.Button buttonCallRecorder;
        private System.Windows.Forms.ComboBox comboAlarmType;
        private System.Windows.Forms.Label labelCallType;
        private System.Windows.Forms.TextBox textBoxCallRecorder;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.Button buttonTeleData;
        private System.Windows.Forms.Button buttonRecorderBase;
        private System.Windows.Forms.TextBox textBoxAdditional;
        private System.Windows.Forms.Label labelAdditional;
        private System.Windows.Forms.ComboBox comboBoxControlledArticle;
        private System.Windows.Forms.Label labelControlledArticle;
        private System.Windows.Forms.Button buttonLocating;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Label labelChar;
        private System.Windows.Forms.Label labelUnitGroup;
        private System.Windows.Forms.Label labelAlarmName;
        private System.Windows.Forms.Label labelCharType;
        private System.Windows.Forms.ComboBox comboBoxChar;
        private System.Windows.Forms.ComboBox comboBoxCharType;
        private System.Windows.Forms.TextBox textBoxAlarmName;
        private System.Windows.Forms.ComboBox comboBoxCharger;
        private System.Windows.Forms.ComboBox comboBoxSuperior;
        private System.Windows.Forms.ComboBox comboBoxUnitGroup;
        private System.Windows.Forms.ComboBox comboUnitType;
        private System.Windows.Forms.Label labelCharger;
        private System.Windows.Forms.Label labelSuperior;
        private System.Windows.Forms.GroupBox groupBoxBrief;
        private System.Windows.Forms.RichTextBox richTextAlarmBrief;
        private System.Windows.Forms.Panel panelUnitOperate;
        private System.Windows.Forms.GroupBox groupBoxStandbyUnit;
        private System.Windows.Forms.ListView listViewStandbyUnit;
        private System.Windows.Forms.GroupBox groupBoxDepartAlter;
        private System.Windows.Forms.Label labelOpTips;
        private System.Windows.Forms.GroupBox groupBoxOpUnit;
        private System.Windows.Forms.ListView listViewOpUnit;
        private System.Windows.Forms.Button buttonLiaozhong;
        private System.Windows.Forms.Button buttonBeizhan;
        private System.Windows.Forms.Button buttonHunnan;
        private System.Windows.Forms.Button buttonShenbei;
        private System.Windows.Forms.Button buttonSujiatun;
        private System.Windows.Forms.Button buttonYuhong;
        private System.Windows.Forms.Button buttonKaifaQu;
        private System.Windows.Forms.Button buttonDadong;
        private System.Windows.Forms.Button buttonHuanggu;
        private System.Windows.Forms.Button buttonShenhe;
        private System.Windows.Forms.Button buttonTiexi;
        private System.Windows.Forms.Button buttonHeping;
        private System.Windows.Forms.Button buttonSbToOp;
        private System.Windows.Forms.Button buttonOpToSb;
        private System.Windows.Forms.Button buttonGenerate;
        private System.Windows.Forms.Button buttonAlarmTrans;
        private System.Windows.Forms.Button buttonMultiOp;
        private System.Windows.Forms.Button buttonDelete;
    }
}