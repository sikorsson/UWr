package obliczenia;

import struktury.Para;
import struktury.ZbiorNaTablicy;
import java.util.Objects;

public class Zmienna extends Wyrazenie {

    private String nazwa;
    public final static ZbiorNaTablicy arr = new ZbiorNaTablicy(100);


    public Zmienna(String s) {
        nazwa = s;
    }

    @Override
    public int oblicz() throws Exception {
        if (isVar(nazwa))
            return (int) print(nazwa);
        throw new NoSuchFieldException("Zmienna nie ma wartosci");
    }

    @Override
    public String toString() {
        return nazwa;
    }

    public static void dodaj(String s, double val) throws Exception{
        Para p = new Para(s, val);
        arr.ustaw(p);
    }

    static double print(String s) throws Exception {
        Para p = arr.szukaj(s);
        return p.getWartosc();
    }

    static void remove(String s) {
        arr.usun(s);
    }

    public static boolean isVar(String s) {
        return arr.search(s);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Zmienna)) return false;
        Zmienna zmienna = (Zmienna) o;
        return Objects.equals(nazwa, zmienna.nazwa);
    }
}
