import javax.swing.*;
import java.awt.*;

public class Screen extends JFrame {
    public Screen() {
        super("Samotnik");
        setLayout(new BoxLayout(getContentPane(), BoxLayout.PAGE_AXIS));
        setResizable(false);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        addMouseListener(GameData.moveMouse);
        addKeyListener(GameData.moveKeyboard);

        setJMenuBar(GameData.menu.mb);
        add(GameData.drawBoard, CENTER_ALIGNMENT);
        add(GameData.wynik, CENTER_ALIGNMENT);

        GameData.drawBoard.setPreferredSize(new Dimension(570, 594));
        GameData.setup();

        pack();
        setVisible(true);
    }
}
