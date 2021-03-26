import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class MoveMouse implements MouseListener {
    @Override
    public void mouseClicked(MouseEvent e) {
        if(e.getButton() == MouseEvent.BUTTON3) {
            if(!GameData.isPegChosen)
                return;
            MenuPopup popup = new MenuPopup();
            popup.getJPopupMenu().show(e.getComponent(), e.getX(), e.getY());
            return;
        }
        int y = e.getY() - Math.abs(GameData.height - GameData.drawBoard.height);

        int x = e.getX() / GameData.drawBoard.sizeOfCell;
        y = y / GameData.drawBoard.sizeOfCell;

        if(GameData.solitaire.checkPeg(x, y) == 2)
            return;

        if(GameData.isPegChosen) {
            GameData.solitaire.movePeg(GameData.chosenPegX, GameData.chosenPegY, x, y);
            GameData.isPegChosen = false;
        }
        else if(GameData.solitaire.board[x][y] == 1) {
            GameData.chosenPegX = x;
            GameData.chosenPegY = y;
            GameData.isPegChosen = true;
        }
        GameData.drawRepaint();
    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {

    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }
}
