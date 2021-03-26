package obliczenia;

public class Liczba extends Wyrazenie{
    public int wartosc;

    public Liczba(int war) {
        wartosc = war;
    }

    @Override
    public int oblicz() {
        return wartosc;
    }

    @Override
    public String toString() {
        return String.valueOf(wartosc);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Liczba)) return false;
        Liczba liczba = (Liczba) o;
        return wartosc == liczba.wartosc;
    }
}
