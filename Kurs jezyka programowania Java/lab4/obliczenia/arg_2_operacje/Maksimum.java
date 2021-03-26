package obliczenia.arg_2_operacje;

import obliczenia.Wyrazenie;

public class Maksimum extends Arg_2 {
    public Maksimum(Wyrazenie l, Wyrazenie r) {
        a = l;
        b = r;
    }

    @Override
    public int oblicz() throws Exception {
        if(a.oblicz() > b.oblicz())
            return a.oblicz();
        return b.oblicz();
    }

    @Override
    public String toString() {
        return "max(" + a.toString() + ", " + b.toString() + ")";
    }
}
