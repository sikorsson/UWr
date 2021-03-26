public class Solitaire {
    public int[][] board;
    public int pegsLeft;

    public final int[][] BOARD33 = new int[][] {
            {2, 2, 1, 1, 1, 2, 2},
            {2, 2, 1, 1, 1, 2, 2},
            {1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1},
            {2, 2, 1, 1, 1, 2, 2},
            {2, 2, 1, 1, 1, 2, 2}
    };
    public final int[][] BOARD37 = new int[][] {
            {2, 2, 1, 1, 1, 2, 2},
            {2, 1, 1, 1, 1, 1, 2},
            {1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 1, 1},
            {1, 1, 1, 1, 1, 1, 1},
            {2, 1, 1, 1, 1, 1, 2},
            {2, 2, 1, 1, 1, 2, 2}
    };

    public Solitaire(int x) {
        if(x != 33 && x != 37)
            throw new IllegalArgumentException("Wrong size of board. 'x' must be equal to 33 or 37.");
        if(x == 33)
            board = BOARD33;
        else
            board = BOARD37;
        pegsLeft = x - 1;
        GameData.isGameOver = false;
    }

    public void movePeg(int x_cur, int y_cur, int x_new, int y_new) {
        if(outOfBorder(x_cur, y_cur) || outOfBorder(x_new, y_new))
            return;
        if(!GameData.isGameOver) {
            if (board[x_new][y_new] == 0 && board[(x_new + x_cur) / 2][(y_new + y_cur) / 2] == 1)
                if (Math.abs(x_cur - x_new) + Math.abs(y_cur - y_new) == 2 && Math.abs(x_cur - x_new) * Math.abs(y_cur - y_new) == 0) {
                    board[x_cur][y_cur] = 0;
                    board[x_new][y_new] = 1;
                    board[(x_new + x_cur) / 2][(y_new + y_cur) / 2] = 0;
                    pegsLeft--;
                    GameData.isGameOver = isGameOver();
                }
        }
    }

    public boolean isGameOver() {
        for(int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                if (checkPeg(i, j) == 0 || checkPeg(i, j) == 2)
                    continue;
                if (checkPeg(i - 1, j) == 1 && checkPeg(i - 2, j) == 0)
                    return false;
                if (checkPeg(i + 1, j) == 1 && checkPeg(i + 2, j) == 0)
                    return false;
                if (checkPeg(i, j - 1) == 1 && checkPeg(i, j - 2) == 0)
                    return false;
                if (checkPeg(i, j + 1) == 1 && checkPeg(i, j + 2) == 0)
                    return false;
            }
        }
        return true;
    }

    private boolean outOfBorder(int x, int y) {
        return x < 0 || x >= board.length || y < 0 || y >= board.length;
    }

    public int checkPeg(int x, int y) {
        if(outOfBorder(x, y))
            return 2;
        return board[y][x];
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();
        for(int i = 0; i < board.length; i++) {
            for (int[] ints : board)
                s.append(ints[i]);
            s.append('\n');
        }
        return String.valueOf(s);
    }
}