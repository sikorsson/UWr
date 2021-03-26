import javax.swing.*;
import java.awt.event.*;

public class Menu_Ustawienia {
    private final JMenu menu = new JMenu("Ustawienia");
    ButtonGroup gr = new ButtonGroup();
    JRadioButton board33 = new JRadioButton("Brytyjska - 33");
    JRadioButton board37 = new JRadioButton("Europejska - 37");
    JMenuItem colorBoard = new JMenuItem("Kolor - plansza");
    JMenuItem colorPeg = new JMenuItem("Kolor - pionki");

    ActionListener boardListener = e -> {
        JRadioButton button = (JRadioButton) e.getSource();
        if(button.getText().equals("Brytyjska - 33"))
            GameData.currBoardSize = 33;
        else if(button.getText().equals("Europejska - 37"))
            GameData.currBoardSize = 37;
    };
    ActionListener colorBoardListener = e -> {
        GameData.boardColor1 = JColorChooser.showDialog(null, "Wybierz 1. kolor planszy", GameData.boardColor1);
        GameData.boardColor2 = JColorChooser.showDialog(null, "Wybierz 2. kolor planszy", GameData.boardColor2);
        GameData.drawRepaint();
    };
    ActionListener colorPegListener = e -> {
        GameData.pegColor = JColorChooser.showDialog(null, "Wybierz 1. kolor planszy", GameData.pegColor);
        GameData.drawRepaint();
    };

    public Menu_Ustawienia() {
        board33.setSelected(true);

        board33.addActionListener(boardListener);
        board37.addActionListener(boardListener);
        colorBoard.addActionListener(colorBoardListener);
        colorPeg.addActionListener(colorPegListener);

        gr.add(board33);
        gr.add(board37);

        menu.add(board33);
        menu.add(board37);
        menu.add(new JSeparator());
        menu.add(colorBoard);
        menu.add(colorPeg);
    }

    public JMenu getMenu() {
        return menu;
    }
}
