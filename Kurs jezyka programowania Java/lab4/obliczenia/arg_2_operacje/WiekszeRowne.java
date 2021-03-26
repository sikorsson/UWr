package obliczenia.arg_2_operacje;

import obliczenia.Wyrazenie;

public class WiekszeRowne extends Arg_2 {
    public WiekszeRowne(Wyrazenie l, Wyrazenie r) {
        a = l;
        b = r;
    }

    @Override
    public int oblicz() throws Exception {
        if(a.oblicz() >= b.oblicz())
            return 1;
        else return 0;
    }

    @Override
    public String toString() {
        return "(" + a.toString() + " >= " + b.toString() + ")";
    }
}
