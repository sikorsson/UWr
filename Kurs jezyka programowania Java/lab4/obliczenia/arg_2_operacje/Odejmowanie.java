package obliczenia.arg_2_operacje;

import obliczenia.Wyrazenie;

public class Odejmowanie extends Arg_2{
    public Odejmowanie(Wyrazenie l, Wyrazenie r) {
        a = l;
        b = r;
    }

    @Override
    public int oblicz() throws Exception {
        return a.oblicz() - b.oblicz();
    }

    @Override
    public String toString() {
        return "(" + a.toString() + " - " + b.toString() + ")";
    }
}
