package obliczenia.arg_2_operacje;

import obliczenia.Wyrazenie;

public class Minimum extends Arg_2 {
    public Minimum(Wyrazenie l, Wyrazenie r) {
        a = l;
        b = r;
    }

    public int oblicz() throws Exception {
        if(a.oblicz() < b.oblicz())
            return a.oblicz();
        return b.oblicz();
    }

    @Override
    public String toString() {
        return "min(" + a.toString() + ", " + b.toString() + ")";
    }
}
