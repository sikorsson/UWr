import javax.swing.*;
import java.awt.*;

public class GameData {
    public static int currBoardSize = 33;
    public static Solitaire solitaire = new Solitaire(33);
    public static DrawBoard drawBoard = new DrawBoard();
    public static Menu menu = new Menu();
    public static MoveMouse moveMouse = new MoveMouse();
    public static MoveKeyboard moveKeyboard = new MoveKeyboard();
    public static JLabel wynik = new JLabel();

    //okno
    public static int width;
    public static int height;

    //gra
    public static boolean isGameOver = false;

    //pionki
    public static int chosenPegX = 3;
    public static int chosenPegY = 3;
    public static boolean isPegChosen = false;

    //aktywne pole
    public static int activeX = 3;
    public static int activeY = 3;

    //kolory
    public static Color pegColor = Color.BLACK;
    public static Color pegChosen = Color.RED;
    public static Color boardColor1 = new Color(200, 200, 200);
    public static Color boardColor2 = new Color(140, 190, 200);
    public static Color activeCell = Color.GREEN;

    private GameData() {}

    public static void setup() {
        width = GameData.drawBoard.getPreferredSize().width;
        height = GameData.drawBoard.getPreferredSize().height;
    }

    public static boolean isMoveViable(int x, int y) {
        return (x < 0 || x > drawBoard.size - 1) || (y < 0 || y > drawBoard.size - 1);
    }

    public static void changeWynikText(String s) {
        wynik.setFont(new Font(Font.SANS_SERIF, Font.BOLD, 15));
        wynik.setAlignmentX(0.5f);
        wynik.setText(s);
    }

    public static void resetBoard() {
        solitaire = new Solitaire(currBoardSize);
        chosenPegX = 3;
        chosenPegY = 3;
        activeX = 3;
        activeY = 3;
        drawRepaint();
    }

    public static void drawRepaint() {
        drawBoard.repaint();
    }
}
