package obliczenia;

public class Stala extends Wyrazenie {
    private final Stala_wartosci wartosc;

    public Stala(Stala_wartosci s) {
        this.wartosc = s;
    }

    @Override
    public int oblicz() {
        return wartosc.w;
    }

    @Override
    public String toString() {
        return String.valueOf(wartosc.w);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Stala)) return false;
        Stala stala = (Stala) o;
        return wartosc == stala.wartosc;
    }
}

