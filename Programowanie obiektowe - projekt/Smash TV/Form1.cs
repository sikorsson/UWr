using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Smash_TV
{
  /// <summary> Główna klasa programu </summary>
  /// <remarks> Jest to obiekt typu Form </remarks>
  public partial class Form1 : Form {
    private bool goLeft, goRight, goUp, goDown, gameOver; //paramertry danych gry
    private Player player;
    private Stage stage;
    List<Enemy> enemies = new List<Enemy>();
    private Random rand = new Random();
    private int score = 0; 
    private int stageCount = 1;
    private int pauseTime = 2000;
    private bool pause;
    
    /// <summary> Konstruktor planszy </summary>
    /// <remarks> Tworzona jest postać gracza, updatowany stage oraz spawnowani są przeciwnicy </remarks>
    public Form1() { //tworzenie planszy
      InitializeComponent();
      player = Player.Instance;
      player.makePlayer(this);
      stage = new Stage();
      stage.update(stageCount);
      spawnEnemies();
    }

    /// <summary> Funkcja odpowiadajaca za timer w grze </summary>
    /// <remarks> Aktualizowane są w niej dane na temat postaci, pocisków, przeciwników oraz innych parametrów gry jak np. HUD </remarks>
    private void gameTimerTick(object sender, EventArgs e) {
      Score.Text = "Score: " + score; //wyswietlanie hud'a
      StageLabel.Text = "Stage: " + stageCount;
      EnemiesLeft.Text = "Enemies: " + stage.howMany_enemies.ToString();
      healthBar.Value = player.playerHealth;

      if (pause) { //pauza pomiedzy turami, trwa 2 sekundy
        deleteEnemies();
        if (pauseTime <= 0) {
          pause = false;
          pauseTime = 2000;
          spawnEnemies();
        }
        pauseTime -= gameTimer.Interval;
      }

      if (stage.howMany_enemies <= 0) { //zmienianie tury
        stageCount++;
        stage.update(stageCount);
        pause = true;
      }

      if (player.playerHealth <= 0) { //warunki przegranej gracza
        gameOver = true;
        gameTimer.Stop();
      }

      player.Move(goLeft, goRight, goUp, goDown);

      foreach (var x in enemies.ToList()) { //sprawdzanie i wykonywanie ruchu dla kazdego przeciwnika
        if (player.player.Bounds.IntersectsWith(x.enemy.Bounds)) { //sprawdzanie czy przeciwnik wszedl w kolizje z graczem
          player.playerHealth -= 1;
          this.Controls.Remove(x.enemy); //jesli przeciwnik sie zderzy z graczem to jest on niszczony
          x.enemy.Dispose();
          enemies.Remove(x);
          createEnemy();
        }

        x.Move();

        foreach (Control j in this.Controls) { //sprawdzanie czy przeciwnik zostal trafiony pociskiem
          if (j is PictureBox && (string) j.Tag == "bullet") { //kolizja sprawdzana za pomoca tagu
            if (x.enemy.Bounds.IntersectsWith(j.Bounds)) { //usuwanie pocisku
              this.Controls.Remove(j);
              ((PictureBox) j).Dispose();
              x.health--;

              if (x.health == 0) { //jesli przeciwnik ma 0 hp jest on usuwany
                this.Controls.Remove(x.enemy);
                x.enemy.Dispose();
                enemies.Remove(x);
                createEnemy();
                score++;
                stage.howMany_enemies--;
              }
            }
          }
        }
      }
    }

    /// <summary> Metoda sprawdzająca wciśnięte przyciski WASD </summary>
    /// <remarks> Jeśli dany przycisk jest wciśnięty to odpowiedni bool jest ustawiany na true </remarks>
    private void isKeyDown(object sender, KeyEventArgs e) { //poruszanie sie gracza
      if (gameOver == true) {
        return;
      }
      if (e.KeyCode == Keys.A) {
        goLeft = true;
      }
      if (e.KeyCode == Keys.D) {
        goRight = true;
      }
      if (e.KeyCode == Keys.W) {
        goUp = true;
      }
      if (e.KeyCode == Keys.S) {
        goDown = true;
      }
    }

    /// <summary> Metoda dla puszczonego przycisku </summary>
    /// <remarks> Dla WASD - bool ustawiane na false. Strzałki - wystrzeliwany jest pocisk. R - resetowana jest gra </remarks>
    private void isKeyUp(object sender, KeyEventArgs e) {
      if (e.KeyCode == Keys.R) {
        resetGame();
      }
      if (gameOver == true) {
        return;
      }
      if (e.KeyCode == Keys.A) {
        goLeft = false;
      }
      if (e.KeyCode == Keys.D) {
        goRight = false;
      }
      if (e.KeyCode == Keys.W) {
        goUp = false;
      }
      if (e.KeyCode == Keys.S) {
        goDown = false;
      }
      if (e.KeyCode == Keys.Left) { //wystrzeliwanie pocisku za pomoca string'a
        shootBullet("left");
      }
      if (e.KeyCode == Keys.Right) {
        shootBullet("right");
      }
      if (e.KeyCode == Keys.Up) {
        shootBullet("up");
      }
      if (e.KeyCode == Keys.Down) {
        shootBullet("down");
      }
    }
    
    /// <summary> Metoda tworzacą przeciwników </summary>
    /// <remarks> Losowany jest odpowiedni model przeciwnika tzn. jeden z 3 podstawowych i na podstawie tego jest tworzony ten obiekt </remarks>
    private void createEnemy() { //tworzenie przeciwnika
      int which_enemy = rand.Next(0, 3); //losujemy model
      Enemy enemy;
      switch (which_enemy) { //za pomoca case tworzony jest odpowiedni obiekt
        case 0: 
          enemy = new enemy_Basic();
          enemy.makeEnemy(this);
          enemies.Add(enemy);
          break;
        case 1:
          enemy = new enemy_Tank();
          enemy.makeEnemy(this);
          enemies.Add(enemy);
          break;
        case 2:
          enemy = new enemy_Fast();
          enemy.makeEnemy(this);
          enemies.Add(enemy);
          break;
      }
      player.player.BringToFront();
    }

    /// <summary> Metoda spawnujacą przeciwników </summary>
    /// <remarks> Tworzona jest zawsze 1/3 z max przeciwników w danej turze oraz jeśli jest to (tura%5==0) to dodatkowo tworzony jest obiekt Boss </remarks>
    private void spawnEnemies() { //spawn przeciwnikow
      for(int i = 0; i < stage.howMany_enemies / 3; i++) //jest ich zawsze na arenie 1/3 wszystkich do pokonania w danej turze
        createEnemy();
      if (stage.boss) { //spawn bossa w turze, jesli tura sie do tego kwalifikuje
        Enemy enemy = new enemy_Boss();
        enemy.makeEnemy(this);
        enemy.increaseHealth(stageCount);
        enemies.Add(enemy);
        stage.boss = false;
      }
    }

    /// <summary> Metoda usuwająca wszystkich przeciwników z planszy </summary>
    /// <remarks> Usuwa ona wszystkich przeciwników z listy enemies </remarks>
    private void deleteEnemies() { //usuwanie wszystkich przeciwnikow z planszy
      foreach (var x in enemies.ToList()) {
        this.Controls.Remove(x.enemy);
        x.enemy.Dispose();
        enemies.Remove(x);
      }
    }
    
    /// <summary> Metoda odpowiadajacą za strzelanie </summary>
    /// <remarks> Tworzy ona obiekt pocisku </remarks>
    /// <param name="dir"> Należy podać string dir z jedną z wartości: "left", "right", "up", "down" </param>
    private void shootBullet(string dir) { //strzelanie
      Bullet bullet = new Bullet {
        direction = dir,
        bulletLeft = player.player.Left + (player.player.Width / 2), //wyliczamy srodek gracza, skad wychodzi pocisk
        bulletTop = player.player.Top + (player.player.Height / 2)
      };
      bullet.makeBullet(this);
    }

    /// <summary> Metoda resetujacą grę </summary>
    /// <remarks> Ustawia ona wszystkie dane na te początkowe </remarks>
    private void resetGame() { //resetowanie gry
      stageCount = 1; //zerujemy wszystkie wyniki
      score = 0;
      stage.reset(stageCount);
      player.makePlayer(this);
      goLeft = false;
      goRight = false;
      goUp = false;
      goDown = false;
      deleteEnemies();
      spawnEnemies();
      gameOver = false;
      gameTimer.Start();
    }
  }
}