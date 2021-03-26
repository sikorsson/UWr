public class Odcinek {
    private Punkt a, b;

    public Odcinek(Punkt a, Punkt b) {
        if (a == b) throw new IllegalArgumentException("punkty w odcinku sa takie same");

        this.a = a;
        this.b = b;
    }

    public void przesun(Wektor v) {
        a.przesun(v);
        b.przesun(v);
    }
    public void obroc(Punkt p, double kat) {
        a.obroc(p, kat);
        b.obroc(p, kat);
    }
    public void odbij(Prosta p) {
        a.odbij(p);
        b.odbij(p);
    }

    public Punkt getA() {
        return a;
    }
    public Punkt getB() {
        return b;
    }

    public void print() {
        a.print();
        b.print();
    }
}
