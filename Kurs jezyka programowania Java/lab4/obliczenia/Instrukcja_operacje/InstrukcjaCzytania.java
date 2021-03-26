package obliczenia.Instrukcja_operacje;

import obliczenia.Instrukcja;
import obliczenia.Liczba;

import java.util.Scanner;

public class InstrukcjaCzytania extends Instrukcja {
    private final String nazwa;

    public InstrukcjaCzytania(String s) {
        if(s == null) throw new NullPointerException();
        nazwa = s;
    }

    @Override
    public void wykonaj() throws Exception {
        new Scanner(System.in);
        Scanner wejscie;
        int wartosc = 0;
        try {
            wejscie = new Scanner(System.in);
            wartosc = wejscie.nextInt();
        }
        catch (Exception e) {
            throw new Exception ("Mozna wczytac tylko liczby calkowite");
        }

        InstrukcjaPrzypisania przypisz = new InstrukcjaPrzypisania(nazwa, new Liczba(wartosc));
        przypisz.wykonaj();
    }

    @Override
    public String toString() {
        return "read " + nazwa + ";\r\n";
    }
}
