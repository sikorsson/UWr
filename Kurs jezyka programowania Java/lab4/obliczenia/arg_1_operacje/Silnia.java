package obliczenia.arg_1_operacje;

import obliczenia.Wyrazenie;

public class Silnia extends Arg_1 {
    Silnia(Wyrazenie e) {
        a = e;
    }

    public int oblicz() throws Exception{
        int n = (int) a.oblicz();
        int fact = 1;
        for (int i = 2; i <= n; i++) {
            fact = fact * i;
        }
        return fact;
    }

    @Override
    public String toString() {
        return (a.toString() + "!");
    }
}
