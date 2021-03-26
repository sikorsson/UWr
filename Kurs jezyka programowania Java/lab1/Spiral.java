public class Spiral {
    public static boolean primality(int n) {
        if(n <= 3) return true;
        else if(n % 2 == 0 || n % 3 == 0)
            return false;

        int i = 5;

        while(i * i <= n) {
            if(n % i == 0 || n % (i + 2) == 0)
                return false;
            i += 6;
        }

        return true;
    }

    public static void main(String[] args) {
        int[][] arr;
        int n = Integer.valueOf(args[0]);
        if(n < 2 || n > 200) throw new IllegalArgumentException("parametr spoza zakresu 2...200");
        arr = new int[n][n];

        int c, r;

        if(n % 2 != 0) {
            c = n / 2;
            r = c;
        }
        else {
            c = n / 2 - 1;
            r = c + 1;
        }

        int value, counter, sq_n = n * n;

        arr[c][r]=1;
        c++;
        counter = 2;
        value = 2;

        while(value <= sq_n)
        {
            for(int i = 0; i < counter; i++) {
                if(value > sq_n) break;
                arr[c][r--] = value++;
            }
            c--;
            r++;
            for(int i = 0; i < counter; i++) {
                if(value > sq_n) break;
                arr[c--][r] = value++;
            }
            c++;
            r++;
            for(int i = 0; i < counter; i++) {
                if(value > sq_n) break;
                arr[c][r++] = value++;
            }
            c++;
            r--;
            for(int i = 0; i < counter; i++) {
                if(value > sq_n) break;
                arr[c++][r] = value++;
            }

            counter += 2;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!primality(arr[j][i]))
                    arr[j][i] = 0;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[j][i] == 0) System.out.print(" ");
                else System.out.print("*");
            }
            System.out.print("\n");
        }
    }
}
