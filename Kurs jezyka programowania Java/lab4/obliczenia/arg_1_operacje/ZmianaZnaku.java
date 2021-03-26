package obliczenia.arg_1_operacje;

import obliczenia.Wyrazenie;

public class ZmianaZnaku extends Arg_1{
    public ZmianaZnaku(Wyrazenie e) {
        a = e;
    }

    @Override
    public int oblicz() throws Exception{
        return -a.oblicz();
    }

    @Override
    public String toString() {
        return "-(" + a.toString() + ")";
    }
}
