namespace Final_Project
{
    partial class FormShowNotice
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
            this.richTextBoxNotice = new System.Windows.Forms.RichTextBox();
            this.labelNotice = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // richTextBoxNotice
            // 
            this.richTextBoxNotice.Location = new System.Drawing.Point(12, 31);
            this.richTextBoxNotice.Name = "richTextBoxNotice";
            this.richTextBoxNotice.ReadOnly = true;
            this.richTextBoxNotice.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.Vertical;
            this.richTextBoxNotice.Size = new System.Drawing.Size(406, 226);
            this.richTextBoxNotice.TabIndex = 1;
            this.richTextBoxNotice.Text = "";
            // 
            // labelNotice
            // 
            this.labelNotice.AutoSize = true;
            this.labelNotice.Location = new System.Drawing.Point(13, 13);
            this.labelNotice.Name = "labelNotice";
            this.labelNotice.Size = new System.Drawing.Size(67, 15);
            this.labelNotice.TabIndex = 2;
            this.labelNotice.Text = "未知通知";
            // 
            // FormShowNotice
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(430, 269);
            this.Controls.Add(this.labelNotice);
            this.Controls.Add(this.richTextBoxNotice);
            this.Name = "FormShowNotice";
            this.Text = "查看通知";
            this.Load += new System.EventHandler(this.FormShowNotice_Load);
            this.ResumeLayout(false);
            this.PerformLayout();
        }

        #endregion

        private System.Windows.Forms.RichTextBox richTextBoxNotice;
        private System.Windows.Forms.Label labelNotice;
    }
}