import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Menu_Ruchy {
    private final JMenu menu = new JMenu("Ruchy");
    JMenuItem mark = new JMenuItem("Zaznacz");
    JMenuItem mvUp = new JMenuItem("Skok w górę");
    JMenuItem mvDown = new JMenuItem("Skok w dół");
    JMenuItem mvLeft = new JMenuItem("Skok w lewo");
    JMenuItem mvRight = new JMenuItem("Skok w prawo");

    static ActionListener mvListener = e -> {
        JMenuItem menuItem = (JMenuItem) e.getSource();
        int x = GameData.chosenPegX;
        int y = GameData.chosenPegY;
        switch (menuItem.getText()) {
            case "Skok w górę":
                y -= 2;
                break;
            case "Skok w dół":
                y += 2;
                break;
            case "Skok w lewo":
                x -= 2;
                break;
            case "Skok w prawo":
                x += 2;
                break;
            default:
                break;
        }
        GameData.isPegChosen = false;
        GameData.solitaire.movePeg(GameData.chosenPegX, GameData.chosenPegY, x, y);
        GameData.drawRepaint();
    };

    public Menu_Ruchy() {
        mark.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(!GameData.isPegChosen) {
                    GameData.chosenPegX = GameData.activeX;
                    GameData.chosenPegY = GameData.activeY;
                    GameData.isPegChosen = true;
                }
                else {
                    GameData.solitaire.movePeg(GameData.chosenPegX, GameData.chosenPegY, GameData.activeX, GameData.activeY);
                    GameData.isPegChosen = false;
                }
                GameData.drawRepaint();
            }
        });

        mvUp.addActionListener(mvListener);
        mvDown.addActionListener(mvListener);
        mvLeft.addActionListener(mvListener);
        mvRight.addActionListener(mvListener);

        mvUp.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_W, InputEvent.CTRL_DOWN_MASK));
        mvDown.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S, InputEvent.CTRL_DOWN_MASK));
        mvLeft.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_A, InputEvent.CTRL_DOWN_MASK));
        mvRight.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_D, InputEvent.CTRL_DOWN_MASK));

        menu.add(mark);
        menu.add(mvUp);
        menu.add(mvDown);
        menu.add(mvLeft);
        menu.add(mvRight);
    }

    public JMenu getMenu() {
        return menu;
    }
}
