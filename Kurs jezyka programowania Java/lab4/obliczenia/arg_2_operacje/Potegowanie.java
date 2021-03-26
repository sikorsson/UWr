package obliczenia.arg_2_operacje;

import obliczenia.Wyrazenie;

public class Potegowanie extends Arg_2 {
    public Potegowanie(Wyrazenie l, Wyrazenie r) {
        a = l;
        b = r;
    }

    @Override
    public int oblicz() throws Exception {
        return (int) Math.pow(a.oblicz(), b.oblicz());
    }

    @Override
    public String toString() {
        return "(" + a.toString() + ") ^ (" + b.toString() + ")";
    }
}
