namespace Final_Project
{
    partial class FormReport
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
            this.groupBoxTotal = new System.Windows.Forms.GroupBox();
            this.labelInnerTitle = new System.Windows.Forms.Label();
            this.groupBoxA = new System.Windows.Forms.GroupBox();
            this.groupBoxB = new System.Windows.Forms.GroupBox();
            this.groupBoxC = new System.Windows.Forms.GroupBox();
            this.groupBoxTotal.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBoxTotal
            // 
            this.groupBoxTotal.Controls.Add(this.labelInnerTitle);
            this.groupBoxTotal.Location = new System.Drawing.Point(12, 12);
            this.groupBoxTotal.Name = "groupBoxTotal";
            this.groupBoxTotal.Size = new System.Drawing.Size(763, 234);
            this.groupBoxTotal.TabIndex = 0;
            this.groupBoxTotal.TabStop = false;
            this.groupBoxTotal.Text = "ABC班数据总览";
            this.groupBoxTotal.Paint += new System.Windows.Forms.PaintEventHandler(this.groupBoxTotal_Paint);
            // 
            // labelInnerTitle
            // 
            this.labelInnerTitle.AutoSize = true;
            this.labelInnerTitle.Font = new System.Drawing.Font("微软雅黑", 7.8F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.labelInnerTitle.Location = new System.Drawing.Point(252, 0);
            this.labelInnerTitle.Name = "labelInnerTitle";
            this.labelInnerTitle.Size = new System.Drawing.Size(287, 19);
            this.labelInnerTitle.TabIndex = 0;
            this.labelInnerTitle.Text = "软件工程5班 6021203558 王嘉琦信息统计页面";
            // 
            // groupBoxA
            // 
            this.groupBoxA.Location = new System.Drawing.Point(12, 254);
            this.groupBoxA.Name = "groupBoxA";
            this.groupBoxA.Size = new System.Drawing.Size(250, 369);
            this.groupBoxA.TabIndex = 1;
            this.groupBoxA.TabStop = false;
            this.groupBoxA.Text = "A班";
            this.groupBoxA.Paint += new System.Windows.Forms.PaintEventHandler(this.groupBoxClass_Paint);
            // 
            // groupBoxB
            // 
            this.groupBoxB.Location = new System.Drawing.Point(268, 254);
            this.groupBoxB.Name = "groupBoxB";
            this.groupBoxB.Size = new System.Drawing.Size(250, 369);
            this.groupBoxB.TabIndex = 2;
            this.groupBoxB.TabStop = false;
            this.groupBoxB.Text = "B班";
            this.groupBoxB.Paint += new System.Windows.Forms.PaintEventHandler(this.groupBoxClass_Paint);
            // 
            // groupBoxC
            // 
            this.groupBoxC.Location = new System.Drawing.Point(525, 254);
            this.groupBoxC.Name = "groupBoxC";
            this.groupBoxC.Size = new System.Drawing.Size(250, 369);
            this.groupBoxC.TabIndex = 3;
            this.groupBoxC.TabStop = false;
            this.groupBoxC.Text = "C班";
            this.groupBoxC.Paint += new System.Windows.Forms.PaintEventHandler(this.groupBoxClass_Paint);
            // 
            // FormReport
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(787, 634);
            this.Controls.Add(this.groupBoxC);
            this.Controls.Add(this.groupBoxB);
            this.Controls.Add(this.groupBoxA);
            this.Controls.Add(this.groupBoxTotal);
            this.Name = "FormReport";
            this.Text = "分局各班信息统计页面";
            this.Load += new System.EventHandler(this.FormReport_Load);
            this.groupBoxTotal.ResumeLayout(false);
            this.groupBoxTotal.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBoxTotal;
        private System.Windows.Forms.GroupBox groupBoxA;
        private System.Windows.Forms.GroupBox groupBoxB;
        private System.Windows.Forms.GroupBox groupBoxC;
        private System.Windows.Forms.Label labelInnerTitle;
    }
}