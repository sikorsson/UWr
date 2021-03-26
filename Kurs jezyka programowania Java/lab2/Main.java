public class Main {
    public static void main(String[] args) {
        Punkt ZERO = new Punkt(0, 0);
        Wektor v = new Wektor(2, 3);

        Punkt p = new Punkt(5, 5);
        p.print();
        p.obroc(ZERO, 90);
        p.print();
        System.out.print('\n');

        Odcinek o = new Odcinek(ZERO, p);
        o.print();
        System.out.print('\n');
        o.przesun(v);
        o.print();
        System.out.print('\n');

        Punkt a = new Punkt(0, 0);
        Punkt b = new Punkt(-2, 4);
        Punkt c = new Punkt(4, 3);
        Trojkat t = new Trojkat(a, b, c);
        t.print();
        System.out.print('\n');
        Prosta symetria = new Prosta(-0.5, 1, -3);
        t.odbij(symetria);
        t.print();
    }
}
