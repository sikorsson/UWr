namespace Smash_TV {
    partial class Form1 {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }

            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.healthBar = new System.Windows.Forms.ProgressBar();
            this.gameTimer = new System.Windows.Forms.Timer(this.components);
            this.Score = new System.Windows.Forms.Label();
            this.StageLabel = new System.Windows.Forms.Label();
            this.EnemiesLeft = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.BackColor = System.Drawing.Color.Transparent;
            this.label1.Font = new System.Drawing.Font("Bahnschrift", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (238)));
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(82, 27);
            this.label1.TabIndex = 0;
            this.label1.Text = "health:";
            // 
            // healthBar
            // 
            this.healthBar.Location = new System.Drawing.Point(84, 9);
            this.healthBar.MarqueeAnimationSpeed = 0;
            this.healthBar.Maximum = 10;
            this.healthBar.Name = "healthBar";
            this.healthBar.Size = new System.Drawing.Size(93, 26);
            this.healthBar.TabIndex = 1;
            this.healthBar.Value = 10;
            // 
            // gameTimer
            // 
            this.gameTimer.Enabled = true;
            this.gameTimer.Interval = 20;
            this.gameTimer.Tick += new System.EventHandler(this.gameTimerTick);
            // 
            // Score
            // 
            this.Score.BackColor = System.Drawing.Color.Transparent;
            this.Score.Font = new System.Drawing.Font("Bahnschrift", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (238)));
            this.Score.Location = new System.Drawing.Point(630, 9);
            this.Score.Name = "Score";
            this.Score.Size = new System.Drawing.Size(142, 27);
            this.Score.TabIndex = 2;
            this.Score.Text = "Score: 0";
            // 
            // StageLabel
            // 
            this.StageLabel.BackColor = System.Drawing.Color.Transparent;
            this.StageLabel.Font = new System.Drawing.Font("Bahnschrift", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (238)));
            this.StageLabel.Location = new System.Drawing.Point(231, 9);
            this.StageLabel.Name = "StageLabel";
            this.StageLabel.Size = new System.Drawing.Size(142, 27);
            this.StageLabel.TabIndex = 3;
            this.StageLabel.Text = "Stage: 1";
            // 
            // EnemiesLeft
            // 
            this.EnemiesLeft.BackColor = System.Drawing.Color.Transparent;
            this.EnemiesLeft.Font = new System.Drawing.Font("Bahnschrift", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte) (238)));
            this.EnemiesLeft.Location = new System.Drawing.Point(411, 9);
            this.EnemiesLeft.Name = "EnemiesLeft";
            this.EnemiesLeft.Size = new System.Drawing.Size(142, 27);
            this.EnemiesLeft.TabIndex = 4;
            this.EnemiesLeft.Text = "Enemies: 0";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int) (((byte) (237)))), ((int) (((byte) (231)))), ((int) (((byte) (154)))));
            this.ClientSize = new System.Drawing.Size(784, 561);
            this.Controls.Add(this.EnemiesLeft);
            this.Controls.Add(this.StageLabel);
            this.Controls.Add(this.Score);
            this.Controls.Add(this.healthBar);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.Text = "Smash TV";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.isKeyDown);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.isKeyUp);
            this.ResumeLayout(false);
        }

        private System.Windows.Forms.Label EnemiesLeft;
        private System.Windows.Forms.Timer gameTimer;
        private System.Windows.Forms.ProgressBar healthBar;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label Score;
        private System.Windows.Forms.Label StageLabel;

        #endregion
    }
}