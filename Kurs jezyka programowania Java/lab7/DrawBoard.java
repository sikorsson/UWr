import javax.swing.*;
import java.awt.*;

public class DrawBoard extends JPanel {
    int height;
    int width;
    int size;
    int sizeOfCell;
    public int gridSize;

    int offsetH;
    int offsetW;

    @Override
    public void paintComponent(Graphics gr) {
        super.paintComponent(gr);

        height = getSize().height;
        width = getSize().width;
        size = GameData.solitaire.board.length;

        sizeOfCell = height / size;
        gridSize = sizeOfCell * size;
        int sizeOfPeg = sizeOfCell / 2;

        offsetH = height / 2 - gridSize / 2;
        offsetW = width / 2 - gridSize / 2;
        int cellOffset = sizeOfCell / 2 - sizeOfPeg / 2;

        int curHt;
        int curWd;

        for(int i = 0; i < size; i++) {
            curWd = i * sizeOfCell;
            for(int j = 0; j < size; j++) {
                int cell = GameData.solitaire.board[j][i];
                curHt = j * sizeOfCell;
                if ((i * size + j) % 2 == 0)
                    gr.setColor(GameData.boardColor1);
                else
                    gr.setColor(GameData.boardColor2);
                if(cell != 2)
                    gr.fillRect(curHt, curWd, sizeOfCell, sizeOfCell);
                if(cell == 1) {
                    if (GameData.chosenPegY == i && GameData.chosenPegX == j) {
                        if (GameData.isPegChosen)
                            gr.setColor(GameData.pegChosen);
                        else
                            gr.setColor(GameData.pegColor);
                    } else {
                        gr.setColor(GameData.pegColor);
                    }
                    gr.fillOval(curHt + cellOffset, curWd + cellOffset, sizeOfPeg, sizeOfPeg);
                }
                if (GameData.activeY == i && GameData.activeX == j) {
                    gr.setColor(GameData.activeCell);
                    gr.drawRect(curHt, curWd, sizeOfCell, sizeOfCell);
                }
            }
        }
        if(GameData.isGameOver)
            GameData.changeWynikText("KONIEC. Wynik: " + GameData.solitaire.pegsLeft);
        else
            GameData.changeWynikText("Wynik: " + GameData.solitaire.pegsLeft);
    }
}
