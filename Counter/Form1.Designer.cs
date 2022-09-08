namespace Counter
{
    partial class Form1
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
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.MMI_timer = new System.Windows.Forms.Timer(this.components);
            this.FORM_timer = new System.Windows.Forms.Timer(this.components);
            this.init_button = new System.Windows.Forms.Button();
            this.SW_button = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(25, 18);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(92, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "WIN NRT counter";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(33, 63);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(84, 12);
            this.label2.TabIndex = 1;
            this.label2.Text = "WIN RT counter";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(42, 106);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(75, 12);
            this.label3.TabIndex = 2;
            this.label3.Text = "FORM counter";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(196, 17);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(32, 12);
            this.label4.TabIndex = 3;
            this.label4.Text = "num1";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(196, 63);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(32, 12);
            this.label5.TabIndex = 4;
            this.label5.Text = "num2";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(196, 106);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(32, 12);
            this.label6.TabIndex = 5;
            this.label6.Text = "num3";
            // 
            // MMI_timer
            // 
            this.MMI_timer.Enabled = true;
            this.MMI_timer.Interval = 30;
            this.MMI_timer.Tick += new System.EventHandler(this.MMI_timer_Tick);
            // 
            // FORM_timer
            // 
            this.FORM_timer.Enabled = true;
            this.FORM_timer.Tick += new System.EventHandler(this.FORM_timer_Tick);
            // 
            // init_button
            // 
            this.init_button.Location = new System.Drawing.Point(34, 146);
            this.init_button.Name = "init_button";
            this.init_button.Size = new System.Drawing.Size(75, 23);
            this.init_button.TabIndex = 6;
            this.init_button.Text = "Initialization";
            this.init_button.UseVisualStyleBackColor = true;
            this.init_button.Click += new System.EventHandler(this.init_button_Click);
            // 
            // SW_button
            // 
            this.SW_button.Location = new System.Drawing.Point(186, 146);
            this.SW_button.Name = "SW_button";
            this.SW_button.Size = new System.Drawing.Size(75, 23);
            this.SW_button.TabIndex = 7;
            this.SW_button.Text = "counter_SW";
            this.SW_button.UseVisualStyleBackColor = true;
            this.SW_button.Click += new System.EventHandler(this.SW_button_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(294, 192);
            this.Controls.Add(this.SW_button);
            this.Controls.Add(this.init_button);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Timer MMI_timer;
        private System.Windows.Forms.Timer FORM_timer;
        private System.Windows.Forms.Button init_button;
        private System.Windows.Forms.Button SW_button;
    }
}

