import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class MoveKeyboard implements KeyListener {
    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {
        int x_new = GameData.activeX;
        int y_new = GameData.activeY;
        switch (e.getKeyCode()) {
            case KeyEvent.VK_UP:
                y_new -= 1;
                break;
            case KeyEvent.VK_DOWN:
                y_new +=  1;
                break;
            case KeyEvent.VK_RIGHT:
                x_new += 1;
                break;
            case KeyEvent.VK_LEFT:
                x_new -= 1;
                break;
            case KeyEvent.VK_ENTER:
                if(GameData.isMoveViable(x_new, y_new) || GameData.solitaire.board[x_new][y_new] == 2)
                    return;
                if(!GameData.isPegChosen && GameData.solitaire.board[x_new][y_new] == 1) {
                    GameData.chosenPegX = x_new;
                    GameData.chosenPegY = y_new;
                    GameData.isPegChosen = true;
                }
                else {
                    GameData.solitaire.movePeg(GameData.chosenPegX, GameData.chosenPegY, x_new, y_new);
                    GameData.isPegChosen = false;
                }
                break;
            default:
                break;
        }
        if(GameData.isMoveViable(x_new, y_new) || GameData.solitaire.board[x_new][y_new] == 2)
            return;
        GameData.activeX = x_new;
        GameData.activeY = y_new;
        GameData.drawRepaint();
    }

    @Override
    public void keyReleased(KeyEvent e) {

    }
}
