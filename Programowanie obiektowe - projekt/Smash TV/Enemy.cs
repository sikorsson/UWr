using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace Smash_TV {

    /// <summary> Główna abstrakcyjna klasa przeciwników </summary>
    /// <remarks> Jest to fabryka abstrakcyjna </remarks>
    public abstract class Enemy { //wierzcholek fabryki abstrakcyjnej
        protected int speed; //pola skladowe, wystepujace tez w dziedziczeniu
        public int health;

        protected Random rand = new Random();
        public PictureBox enemy = new PictureBox();
        private Player playerPos = Player.Instance; //tworzymy obiekt gracza, tak aby korzystac z jego pozycji przy ruchu
        
        /// <summary> Klasa abstrakcyjna do nadania parametrów przeciwnikowi </summary>
        /// <param name="form"> Jako argument należy podać obiekt Form </param>
        public abstract void makeEnemy(Form form);

        /// <summary> Klasa abstrakcyjna do zwiększenia wartości health </summary>
        /// <param name="form"> Jako argument należy podać obiekt Form </param>
        public abstract void increaseHealth(int stage);

        /// <summary> Metoda ustalająca pozycję początkową przeciwnika </summary>
        /// <remarks> Zwraca ona jedną z 4 możliwych pozycji </remarks>
        protected KeyValuePair<int, int> enemySpawnPosition() { //spawnowanie przeciwnikow
            int posX, posY;
            posX = rand.Next(0, 3); //wybieramy pozycje X, jako jedna z 3 mozliwosci: lewa strona, srodek, prawa

            if (posX == 0 || posX == 2) posY = 300; //w zaleznosci od posX przeciwnik pojawi sie na srodku, na gorze lub na dole
            else {
                posY = rand.Next(0, 2) * 600;
            }
            
            return new KeyValuePair<int, int>(posX * 400, posY);
        }

        /// <summary> Metoda poruszania przeciwnika </summary>
        /// <remarks> Za pomocą obecnej pozycji gracza przeciwnik poruszany jest w jego kierunku </remarks>
        public void Move() { //przeciwnicy poruszaja sie w kierunku gracza
            if (enemy.Left > playerPos.player.Left) {
                enemy.Left -= speed;
            }
            if (enemy.Left < playerPos.player.Left) {
                enemy.Left += speed;
            }
            if (enemy.Top > playerPos.player.Top) {
                enemy.Top -= speed;
            }
            if (enemy.Top < playerPos.player.Top) {
                enemy.Top += speed;
            }
        }
    }

    /// <summary> Basic produkt fabryki </summary>
    /// <remarks> Ma on średnie parametry życia i prędkości </remarks>
    public class enemy_Basic : Enemy { //przeciwnik basic, ktory dziedziczy po Enemy. Kazdy przeciwnik ma inne atrybuty
        public override void makeEnemy(Form form) {
            enemy.Tag = "enemy";
            speed = 4;
            health = 2;
            KeyValuePair<int, int> x = new KeyValuePair<int, int>();
            x = enemySpawnPosition();
            enemy.Left = x.Key;
            enemy.Top = x.Value;
            enemy.Size = new Size(32, 32);
            enemy.Image = Image.FromFile(@"sprites\basic.png");
            enemy.BackColor = Color.Empty;
            enemy.SizeMode = PictureBoxSizeMode.AutoSize;
            form.Controls.Add(enemy);
        }

        public override void increaseHealth(int stage) {
            throw new NotImplementedException();
        }
    }
    
    /// <summary> Tank produkt fabryki </summary>
    /// <remarks> Ma on więcej życia i jest wolniejszy od Basic </remarks>
    public class enemy_Tank : Enemy {
        public override void makeEnemy(Form form) {
            enemy.Tag = "enemy";
            speed = 2;
            health = 3;
            KeyValuePair<int, int> x = new KeyValuePair<int, int>();
            x = enemySpawnPosition();
            enemy.Left = x.Key;
            enemy.Top = x.Value;
            enemy.Size = new Size(48, 48);
            enemy.Image = Image.FromFile(@"sprites\tank.png");
            enemy.BackColor = Color.Empty;
            enemy.SizeMode = PictureBoxSizeMode.AutoSize;
            form.Controls.Add(enemy);
        }

        public override void increaseHealth(int stage) {
            throw new NotImplementedException();
        }
    }
    
    /// <summary> Fast produkt fabryki </summary>
    /// <remarks> Ma on mniej życia i jest szybszy od Basic </remarks>
    public class enemy_Fast : Enemy {
        public override void makeEnemy(Form form) {
            enemy.Tag = "enemy";
            speed = 6;
            health = 1;
            KeyValuePair<int, int> x = new KeyValuePair<int, int>();
            x = enemySpawnPosition();
            enemy.Left = x.Key;
            enemy.Top = x.Value;
            enemy.Size = new Size(24, 24);
            enemy.Image = Image.FromFile(@"sprites\fast.png");
            enemy.BackColor = Color.Empty;
            enemy.SizeMode = PictureBoxSizeMode.AutoSize;
            form.Controls.Add(enemy);
        }

        public override void increaseHealth(int stage) {
            throw new NotImplementedException();
        }
    }
    
    /// <summary> Boss produkt fabryki </summary>
    /// <remarks> Jest to unikalny przeciwnik, który pojawia się co 5 tur. Ma on większe parametry życia i prędkości od Basic </remarks>
    public class enemy_Boss : Enemy {
        public override void makeEnemy(Form form) {
            enemy.Tag = "enemy";
            speed = 5;
            health = 5;
            KeyValuePair<int, int> x = new KeyValuePair<int, int>();
            x = enemySpawnPosition();
            enemy.Left = x.Key;
            enemy.Top = x.Value;
            enemy.Size = new Size(64, 64);
            enemy.Image = Image.FromFile(@"sprites\boss.png");
            enemy.BackColor = Color.Empty;
            enemy.SizeMode = PictureBoxSizeMode.AutoSize;
            form.Controls.Add(enemy);
        }

        /// <summary> Unikalną własnością Boss'a jest to, że z każdym pojawieniem się jest on silniejszy </summary>
        /// <param name="stage"> Aktualna tura </param>
        public override void increaseHealth(int stage) {
            health += stage / 5;
        }
    }
}