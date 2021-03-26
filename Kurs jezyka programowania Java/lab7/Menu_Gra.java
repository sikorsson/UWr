import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

public class Menu_Gra {
    private final JMenu menu = new JMenu("Gra");
    JMenuItem newGame = new JMenuItem("Nowa");
    JMenuItem exit = new JMenuItem("Koniec");

    public Menu_Gra() {
        menu.setMnemonic(KeyEvent.VK_G);
        newGame.setMnemonic(KeyEvent.VK_N);
        exit.setMnemonic(KeyEvent.VK_E);

        newGame.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                GameData.resetBoard();
            }
        });
                exit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        menu.add(newGame);
        menu.add(exit);
    }

    public JMenu getMenu() {
        return menu;
    }
}
