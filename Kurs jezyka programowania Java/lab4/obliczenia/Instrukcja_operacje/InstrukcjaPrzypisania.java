package obliczenia.Instrukcja_operacje;

import obliczenia.Instrukcja;
import obliczenia.Wyrazenie;
import obliczenia.Zmienna;
import struktury.Para;

public class InstrukcjaPrzypisania extends Instrukcja {
    private String nazwa;
    private Wyrazenie ex;
    public InstrukcjaPrzypisania(String s, Wyrazenie w) {
        if(s == null || w == null) throw new NullPointerException();
        nazwa = s;
        ex = w;
    }

    @Override
    public void wykonaj() throws Exception {
        if(Zmienna.arr.search(nazwa)) {
            Para p = new Para(nazwa, ex.oblicz());
            Zmienna.arr.ustaw(p);
        }
        else throw new NoSuchFieldException("Zmienna nie istnieje");
    }

    @Override
    public String toString() {
        return nazwa + " = " + ex.toString()+";\r\n";
    }
}
