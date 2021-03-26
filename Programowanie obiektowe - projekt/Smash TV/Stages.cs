namespace Smash_TV {
    
    /// <summary> Klasa tury </summary>
    /// <remarks> Ma ona na celu obliczać ilość przeciwników w danej turze oraz odpowiada za reset tur </remarks>
    public class Stage {
        public int howMany_enemies; //pole okreslajace ile przeciwnikow pojawi sie w danej turze
        public bool boss;
        private double div = 1.0;

        /// <summary> Zaktualizowanie tury </summary>
        /// <remarks> Metoda ta oblicza za pomocą prostegu wzoru ilość przeciwników w danej turze </remarks>
        /// <param name="stage"> Aktualna tura </param>
        public void update(int stage) { //ta metoda oblicza nam ilosc przeciwnikow za pomoca prostego wzoru, ktory dba o to, aby nie pojawilo sie ich za duzo
            howMany_enemies = (int)(stage * 3 / div);
            if (stage % 5 == 0) boss = true; //co 5 tur pojawia sie przeciwnik specjalny
            div += 0.05;
        }

        /// <summary> Metoda resetujacą ture </summary>
        /// <remarks> Jest tu resetowana wartość 'div' oraz wywołana metoda update(int stage) </remarks>
        /// <param name="stage"> Należy podać stage, tak za pomocą tego wywołać metodę update(int stage) </param>
        public void reset(int stage) {
            div = 1.0;
            update(stage);
        }
    }
}