package obliczenia.arg_2_operacje;

import obliczenia.Wyrazenie;

public class Dodawanie extends Arg_2 {
    public Dodawanie(Wyrazenie l, Wyrazenie r) {
        a = l;
        b = r;
    }

    @Override
    public int oblicz() throws Exception{
        return a.oblicz() + b.oblicz();
    }

    @Override
    public String toString() {
        return "(" + a.toString() + " + " + b.toString() + ")";
    }
}
