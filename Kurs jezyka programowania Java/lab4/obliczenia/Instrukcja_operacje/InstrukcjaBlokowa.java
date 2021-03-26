package obliczenia.Instrukcja_operacje;

import obliczenia.Instrukcja;
import obliczenia.Zmienna;

import java.util.ArrayList;

public class InstrukcjaBlokowa extends Instrukcja {
    private Instrukcja[] arr;
    private ArrayList<String> zmienne = new ArrayList<>();

    public InstrukcjaBlokowa(Instrukcja... ins) {
        for(Instrukcja i : ins) {
            if(ins == null) throw new NullPointerException();
        }
        arr = ins;
    }

    @Override
    public void wykonaj() throws Exception {
        for(Instrukcja i : arr) {
            if(i instanceof Deklaracja)
                zmienne.add(((Deklaracja) i).getNazwa());
            i.wykonaj();
        }
        for(String z : zmienne) {
            Zmienna.arr.usun(z);
        }
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();

        for(Instrukcja i : arr){
            s.append("\t"+i.toString());
        }

        return "{\r\n" + s + "}";
    }

}
