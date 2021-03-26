package obliczenia.Instrukcja_operacje;

import obliczenia.Instrukcja;
import obliczenia.Zmienna;
import struktury.Para;

public class Deklaracja extends Instrukcja {
    public String nazwa;

    public Deklaracja(String s) {
        if(s == null) throw new NullPointerException();
        nazwa = s;
    }

    @Override
    public void wykonaj() throws Exception{
        Para p = new Para(nazwa, 0);
        Zmienna.arr.ustaw(p);
    }

    @Override
    public String toString() {
        return "var " + nazwa + ";\r\n";
    }

    public String getNazwa() {
        return nazwa;
    }
}
