package struktury;

public class Para {
    public final String klucz;
    private double wartosc;

    public Para(String str, double val) {
        if(str.equals("") || str == null) throw new IllegalArgumentException("string jest pusty lub ma wartosc null");

        klucz = str.toLowerCase();
        wartosc = val;
    }

    public double getWartosc() {
        return wartosc;
    }
    public void setWartosc(double newVal) {
        wartosc = newVal;
    }

    @Override
    public String toString() {
        return klucz;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null)
            return false;
        if (o.getClass() != this.getClass())
            return false;

        final Para x = (Para) o;

        return this.klucz.equals(x.klucz);
    }
}