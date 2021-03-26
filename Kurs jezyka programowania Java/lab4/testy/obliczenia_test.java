package testy;

import obliczenia.Liczba;
import obliczenia.Wyrazenie;
import obliczenia.Zmienna;
import obliczenia.arg_1_operacje.ZmianaZnaku;
import obliczenia.arg_2_operacje.*;
import struktury.Para;

public class obliczenia_test {
    public static void test() throws Exception {
        Para p = new Para("x", 2);
        Zmienna.arr.ustaw(p);
        p = new Para("y", 5);
        Zmienna.arr.ustaw(p);
        Wyrazenie ex;

        //3 + 5
        ex = new Dodawanie(new Liczba(3), new Liczba(5));
        System.out.println(ex.toString() + " = " + ex.oblicz());

        //-(2 - x) * 7
        ex = new Mnozenie(
                new ZmianaZnaku(
                        new Odejmowanie(new Liczba(2),
                                new Zmienna("x"))), new Liczba(7));
        System.out.println(ex.toString() + " = " + ex.oblicz());

        //(3 * 11 - 1) / (7 + 5)
        ex = new Dzielenie(
                new Odejmowanie(
                        new Mnozenie(new Liczba(3), new Liczba(11)), new Liczba(1)),
                new Dodawanie(new Liczba(7), new Liczba(5)));
        System.out.println(ex.toString() + " = " + ex.oblicz());

        //min((x + 13) * x, (1 - x) mod 2)
        ex = new Minimum(
                new Mnozenie(
                        new Dodawanie(new Zmienna("x"), new Liczba(13)),
                        new Zmienna("x")),
                new Modulo(new Odejmowanie(new Liczba(1), new Zmienna("x")), new Liczba(2)));
        System.out.println(ex.toString() + " = " + ex.oblicz());

        //2 ^ 5 + x * log(2, y) < 20
        ex = new Mniejsze(
                new Dodawanie(
                        new Potegowanie(new Liczba(2), new Liczba(5)),
                        new Mnozenie(new Zmienna("x"),
                                new LogDyskretny(new Liczba(2), new Zmienna("y")))), new Liczba(20));
        System.out.println(ex.toString() + " = " + ex.oblicz());
    }
}
