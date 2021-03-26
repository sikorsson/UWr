public class Trojkat {
    private Punkt a, b, c;

    public Trojkat(Punkt a, Punkt b, Punkt c) {
        if (a == b || a == c || b == c)
            throw new IllegalArgumentException("punkty w trojkacie sa takie same");

        //(xB−xA)(yC−yA)=(yB−yA)(xC−xA)
        double L = (b.getX() - a.getX()) * (c.getY() - a.getY());
        double R = (b.getY() - a.getY()) * (c.getX() - a.getX());
        if (L == R) throw new IllegalArgumentException("punkty w trojkacie sa wspolliniowe");

        this.a = a;
        this.b = b;
        this.c = c;
    }

    public void przesun(Wektor v) {
        a.przesun(v);
        b.przesun(v);
        c.przesun(v);
    }
    public void obroc(Punkt p, double kat) {
        a.obroc(p, kat);
        b.obroc(p, kat);
        c.obroc(p, kat);
    }
    public void odbij(Prosta p) {
        a.odbij(p);
        b.odbij(p);
        c.odbij(p);
    }

    public Punkt getA() {
        return a;
    }
    public Punkt getB() {
        return b;
    }
    public Punkt getC() {
        return c;
    }

    public void print() {
        a.print();
        b.print();
        c.print();
    }
}
