package testy;

import obliczenia.*;
import obliczenia.arg_1_operacje.*;
import obliczenia.arg_2_operacje.*;
import obliczenia.Instrukcja_operacje.*;

public class instrukcja_testy {
    public static void test() throws Exception {
        Instrukcja instrukcja = new InstrukcjaBlokowa(
                new Deklaracja("n"),
                new InstrukcjaCzytania("n"),
                new InstrukcjaWarunkowa_IfElse(new Mniejsze(new Zmienna("n"), new Liczba(2)),
                        new InstrukcjaPisania(new Liczba(0)),
                        new InstrukcjaBlokowa(
                                new Deklaracja("p"),
                                new InstrukcjaPrzypisania("p", new Liczba(2)),
                                new Deklaracja("wyn"),
                                new InstrukcjaPetli_While(new MniejszeRowne(
                                        new Mnozenie(new Zmienna("p"), new Zmienna("p")),
                                        new Zmienna("n")),
                                        new InstrukcjaBlokowa(
                                                new InstrukcjaWarunkowa_If(new Rowne(new Modulo(new Zmienna("n"), new Zmienna("p")),
                                                        new Liczba(0)),
                                                        new InstrukcjaBlokowa(
                                                                new InstrukcjaPrzypisania("wyn", new Zmienna("p")),
                                                                new InstrukcjaPrzypisania("p", new Zmienna("n"))
                                                        )),
                                                new InstrukcjaPrzypisania("p", new Dodawanie(new Zmienna("p"), new Liczba(1)))
                                        )
                                ),
                                new InstrukcjaWarunkowa_IfElse(new Wieksze(new Zmienna("wyn"), new Liczba(0)),
                                        new InstrukcjaPisania(new Liczba(0)), new InstrukcjaPisania(new Liczba(1))
                                ))
                ));

        System.out.println(instrukcja);
    }
}
