package obliczenia.arg_2_operacje;

import obliczenia.Wyrazenie;

public class LogDyskretny extends Arg_2 {
    public LogDyskretny(Wyrazenie l, Wyrazenie r) {
        a = l;
        b = r;
    }

    @Override
    public int oblicz() throws Exception {
        return (int) (Math.log(b.oblicz()) / Math.log(a.oblicz()));
    }

    @Override
    public String toString() {
        return "(log" + a.toString() + "(" + b.toString() + "))";
    }
}
