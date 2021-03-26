using System;
using System.Drawing;
using System.Windows.Forms;

namespace Smash_TV {
    
    /// <summary> Klasa reprezentujaca postac </summary>
    /// <remarks> Jest to klasa z zastosowanym wzorcem singleton </remarks>
    public sealed class Player { //wzorzec singleton, sealed blokuje dziedziczenie klasy
        private static Player instance = new Player(); //pole zawierajace instancje do wlasnej klasy
        
        public int playerHealth;
        public int speed;
        private Random rand = new Random();
        public PictureBox player = new PictureBox();

        /// <summary> Instancja klasy </summary>
        /// <remarks> Do tej klasy należy się odwoływać za pomocą tej instancji </remarks>
        public static Player Instance => instance; //do tej klasy odwoluje sie za pomoca tej metody, ktora zwraca istniejaca juz instancje

        /// <summary> Konstruktor postaci </summary>
        /// <remarks> Jest on prywatny, ponieważ z niego nie powinniśmy korzystać </remarks>
        private Player() {
        }

        /// <summary> Funkcja odpowiadajacą za nadanie postaci parametrów </summary>
        /// <param name="form"> Jako argument należy podać obiekt Form </param>
        public void makePlayer(Form form) { //funkcja ta sluzy do utworzenia postaci, tzn. nadaje jej parametry dla pol skladowych klasy oraz PictureBox'a
            playerHealth = 10;
            speed = 7;
            player.Size = new Size(32, 48);
            player.Left = 400;
            player.Top = 300;
            player.Name = "player";
            player.Image = Image.FromFile(@"sprites\player.png"); //ladowanie obrazka postaci
            player.BringToFront();
            form.Controls.Add(player); //dodanie PictureBox'a do Controls z form
        }

        /// <summary> Metoda poruszania postaci </summary>
        /// <remarks> Za pomocą booli sprawdzany jest wciśnięty przycisk, na podstawie tego i pozycji postaci gracz jest poruszany,
        /// tak żeby nie wyszedł on poza ekran </remarks>
        public void Move(bool l, bool r, bool u, bool d) { //metoda Move dziala za pomoca bool'i, ktore mowia jakie gracz wcisnal przyciski
            if (l == true && player.Left > 0) { //poza wcisnietymi przyciskami sprawdzane jest rowniez pozycja postaci, tak aby nie wyszla ona poza ekran
                player.Left -= speed;
            }
            if (r == true && player.Left + player.Width < 800) {
                player.Left += speed;
            }
            if (u == true && player.Top > 0) {
                player.Top -= speed;
            }
            if (d == true && player.Top + player.Height < 600) {
                player.Top += speed;
            }
        }
    }
}