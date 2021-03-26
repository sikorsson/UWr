import java.util.Random;

public class Maze {
    public final int[][] maze;

    public final static int SIZE = 10;
    public final static int N = 1, S = 2, E = 4, W = 8; //sciany opisane w one-hot
    private final static Random RANDOM = new Random();

    public Maze() {
        maze = new int[SIZE][SIZE];
        carve_passages_from(0, 0, maze);
    }

    private int DX(int x) {
        return switch (x) {
            case E -> 1;
            case W -> -1;
            default -> 0;
        };
    }
    private int DY(int y) {
        return switch (y) {
            case N -> -1;
            case S -> 1;
            default -> 0;
        };
    }
    private int OPPOSITE(int y) {
        return switch (y) {
            case E -> W;
            case W -> E;
            case N -> S;
            case S -> N;
            default -> 0;
        };
    }

    void carve_passages_from(int cx, int cy, int[][] grid) {
        int[] directions = {N, S, E, W};
        for (int i=0; i<directions.length; i++) {
            int randomPosition = RANDOM.nextInt(directions.length);
            int temp = directions[i];
            directions[i] = directions[randomPosition];
            directions[randomPosition] = temp;
        }

        for (int direction: directions) {
            int nx = cx + DX(direction);
            int ny = cy + DY(direction);

            if ((ny >= 0 && ny < grid.length) && (nx >= 0 && nx < grid[ny].length) && grid[ny][nx] == 0) {
                grid[cy][cx] |= direction;
                grid[ny][nx] |= OPPOSITE(direction);
                carve_passages_from(nx, ny, grid);
            }
        }
    }

    public boolean isMoveViable(int x, int y, int dir) {
        return (maze[x][y] & dir) == dir;
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        int x, y;
        for(x = 0; x <= (SIZE * 2); x++)
            s.append("_");
        s.append("\n");

        for(y = 0; y < SIZE; y++) {
            s.append("|");
            for(x = 0; x < SIZE; x++) {
                s.append(((maze[y][x] & S) !=  0) ? " " : "_");
                if((maze[y][x] & E) != 0){
                    s.append((( (maze[y][x] | maze[y][x+1]) & S) != 0) ? " " : "_");
                } else {
                    s.append("|");
                }
            }
            s.append("\n");
        }
        return String.valueOf(s);
    }

    public void printArray() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++)
                System.out.print(maze[i][j] + "\t");
            System.out.print('\n');
        }
    }
}
