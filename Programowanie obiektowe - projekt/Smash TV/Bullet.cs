using System;
using System.Drawing;
using System.Windows.Forms;

namespace Smash_TV {
    
    /// <summary> Klasa bullet </summary>
    public class Bullet {
        public int bulletLeft;
        public int bulletTop;
        private int speed = 20;
        public string direction;
        
        public PictureBox bullet = new PictureBox();
        private Timer bulletTimer = new Timer();

        /// <summary> Metoda tworzaca pocisk na planszy </summary>
        /// <param name="form"> Jako argument należy podać obiekt Form </param>
        public void makeBullet(Form form) { //tworzenie pocisku
            bullet.BackColor = Color.Azure;
            bullet.Size = new Size(5,5);
            bullet.Tag = "bullet";
            bullet.Left = bulletLeft;
            bullet.Top = bulletTop;
            bullet.BringToFront();
            
            form.Controls.Add(bullet);
            bulletTimer.Interval = speed;
            bulletTimer.Tick += new EventHandler(bulletTimerEvent);
            bulletTimer.Start();
        }

        ///<summary> Timer pocisku, odpowiada za poruszanie się go i niszczenie, gdy ten wyleci poza arenę </summary>
        private void bulletTimerEvent(object sender, EventArgs e) { //poruszanie sie pocisku wg klikniecia strzalek
            if (direction == "left") {
                bullet.Left -= speed;
            }
            if (direction == "right") {
                bullet.Left += speed;
            }
            if (direction == "up") {
                bullet.Top -= speed;
            }
            if (direction == "down") {
                bullet.Top += speed;
            }

            if (bullet.Left < 0 || bullet.Left > 800 || bullet.Top < 0 || bullet.Top > 600) { //jesli pocisk wyleci poza ekran to jest on niszczony
                bulletTimer.Stop();
                bulletTimer.Dispose();
                bullet.Dispose();
                bulletTimer = null;
                bullet = null;
            }
        }
    }
}