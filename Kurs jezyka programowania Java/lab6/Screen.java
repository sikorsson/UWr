import java.awt.*;
import java.awt.event.*;
import java.io.IOException;

public class Screen extends Frame {
    private final Canvas screen = new Canvas();
    private final Maze maze = new Maze();
    Game game;
    {
        try {
            game = new Game(maze);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private final WindowListener frameList = new WindowAdapter()
    {
        @Override
        public void windowClosing (WindowEvent ev)
        {
            Screen.this.dispose();
        }
    };

    public Screen() {
        super("Maze Runner");
        setSize(400, 400);
        setLocation(0, 0);
        add(screen, BorderLayout.CENTER);

        screen.addKeyListener(game.keyList);
        screen.setFocusable(true);
        screen.requestFocus();
        addWindowListener(frameList);
        add(game);

        setVisible(true);
    }
}
