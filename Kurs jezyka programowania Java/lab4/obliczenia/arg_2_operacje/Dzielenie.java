package obliczenia.arg_2_operacje;

import obliczenia.Wyrazenie;

public class Dzielenie extends Arg_2{
    public Dzielenie(Wyrazenie l, Wyrazenie r) {
        a = l;
        b = r;
    }

    @Override
    public int oblicz() throws Exception {
        if (b.oblicz() != 0)
            return a.oblicz() / b.oblicz();
        throw new ArithmeticException("Nie mozna podzielic przez 0");
    }

    @Override
    public String toString() {
        return "(" + a.toString() + ") / (" + b.toString() + ")";
    }
}
