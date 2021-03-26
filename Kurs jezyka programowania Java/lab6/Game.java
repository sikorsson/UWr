import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.IOException;
import java.util.Random;

public class Game extends Canvas {
    private Maze maze;
    private final static Random RANDOM = new Random();

    Image player;
    int player_xpos;
    int player_ypos;

    Game(Maze m) throws IOException {
        maze = m;
        randomizePos();
        player = ImageIO.read(new File("src/player.png"));
    }

    @Override
    public void paint(Graphics gr) {
        int height = getSize().height;
        int width = getSize().width;
        int size = Maze.SIZE;

        int sizeOfCell = height / size;
        int gridSize = sizeOfCell * size;
        int sizeOfPlayer = sizeOfCell / 2;

        int offsetH = height / 2 - gridSize / 2; //do wyśrodkowania labiryntu/postaci
        int offsetW = width / 2 - gridSize / 2;
        int cellOffset = sizeOfCell / 2 - sizeOfPlayer / 2;

        int curHt;
        int curWd;

        for(int i = 0; i < Maze.SIZE; i++) {
            curWd = i * sizeOfCell + offsetH;
            for(int j = 0; j < Maze.SIZE; j++) {
                int room = maze.maze[i][j];
                curHt = j * sizeOfCell + offsetW;
                if((room & Maze.N) == 0)
                    gr.drawLine(curHt, curWd , sizeOfCell + curHt, curWd);
                if((room & Maze.S) == 0)
                    gr.drawLine(curHt, curWd + sizeOfCell, curHt + sizeOfCell, curWd + sizeOfCell);
                if((room & Maze.W) == 0)
                    gr.drawLine(curHt, curWd, curHt, sizeOfCell + curWd);
                if((room & Maze.E) == 0)
                    gr.drawLine(curHt + sizeOfCell, curWd, sizeOfCell + curHt, sizeOfCell + curWd);

            }
        }
        gr.setColor(Color.GREEN);
        gr.fillRect(player_xpos * sizeOfCell + offsetW + cellOffset, player_ypos * sizeOfCell + offsetH + cellOffset, sizeOfPlayer, sizeOfPlayer);
        //player = player.getScaledInstance(sizeOfPlayer, sizeOfPlayer, Image.SCALE_DEFAULT);
        //gr.drawImage(player, column * sizeOfCell + offsetW + cellOffset, row * sizeOfCell + offsetH + cellOffset, null);
    }

    public KeyListener keyList = new KeyAdapter() {
        @Override
        public void keyPressed (KeyEvent ev)
        {
            switch (ev.getKeyCode())
            {
                case KeyEvent.VK_UP:
                    if(maze.isMoveViable(player_ypos, player_xpos, Maze.N))
                        player_ypos--;
                    break;
                case KeyEvent.VK_DOWN:
                    if(maze.isMoveViable(player_ypos, player_xpos, Maze.S))
                        player_ypos++;
                    break;
                case KeyEvent.VK_LEFT:
                    if(maze.isMoveViable(player_ypos, player_xpos, Maze.W))
                        player_xpos--;
                    break;
                case KeyEvent.VK_RIGHT:
                    if(maze.isMoveViable(player_ypos, player_xpos, Maze.E))
                        player_xpos++;
                    break;
                default:
                    break;
            }
            if(isGameOver())
                resetGame();
            repaint();
        }
    };

    public boolean isGameOver() {
        return player_xpos == 0 && player_ypos == 0;
    }

    private void resetGame() {
        maze = new Maze();
        randomizePos();
    }

    private void randomizePos() {
        player_xpos = RANDOM.nextInt(Maze.SIZE);
        player_ypos = RANDOM.nextInt(Maze.SIZE);
    }
}
