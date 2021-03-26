package struktury;

public abstract class Zbior {
    /** metoda ma wyszukac parę z zadanym kluczem
     metoda zgłasza wyjątek, gdy nie znajdzie pary o podanym kluczu */
    public abstract Para szukaj (String k) throws Exception;

    /** metoda ma wstawić do zbioru nową parę
     metoda zgłasza wyjątek, gdy para o podanym kluczu już jest w zbiorze */
    public abstract void wstaw (Para p) throws Exception;

    /** metoda ma usunąć ze zbioru parę o zadanym kluczu
     gdy pary o podanym kluczu nie ma w zbiorze metoda nic nie zrobi */
    public abstract void usun (String k);

    /** metoda ma odszukać parę o zadanym kluczu i zwrócić wartość pozwiązaną
     metoda zgłasza wyjątek, gdy nie znajdzie pary o podanym kluczu */
    public abstract double czytaj (String k) throws Exception;

    /** metoda ma wstawić do zbioru nową albo zaktualizować parę */
    public abstract void ustaw (Para p) throws Exception;

    /** metoda ma usunąć wszystkie pary ze zbioru */
    public abstract void czysc ();

    /** metoda ma podać ile jest wszystkich par w zbiorze */
    public abstract int ile ();
}
