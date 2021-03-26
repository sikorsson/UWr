package obliczenia.Instrukcja_operacje;

import obliczenia.Instrukcja;
import obliczenia.Liczba;

public class InstrukcjaPisania extends Instrukcja {
    private Liczba wartosc;

    public InstrukcjaPisania(Liczba l) {
        if(l == null) throw new NullPointerException();
        wartosc = l;
    }

    @Override
    public void wykonaj() {
        System.out.println(wartosc.oblicz());
    }

    @Override
    public String toString() {
        return "write " + wartosc.oblicz() + ";\r\n";
    }
}
