public class Prosta {
    public final double a, b, c;

    public Prosta(double a, double b, double c) {
        if (a == 0 && b == 0) throw new IllegalArgumentException("nie mozna utworzyc prostej");
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public static Prosta przesun(Prosta p, Wektor v) {
            // Ax + By + (C - Adx + Bdy) = 0
        double tmp = p.c - p.a * v.dx + p.b * v.dy;
        return new Prosta(p.a, p.b, tmp);
    }

    public static boolean rownolegle(Prosta p1, Prosta p2) {
        return ((p1.a * p2.b) - (p2.a * p1.b)) == 0;
    }
    public static boolean prostopadle(Prosta p1, Prosta p2) {
        return ((p1.a * p2.b) + (p1.b * p2.b)) == 0;
    }

    public static Punkt przeciecie(Prosta p1, Prosta p2) {
        if (rownolegle(p1, p2)) throw new IllegalArgumentException("podane proste sa rownolegle");
        double a1, a2, b1, b2, x, y;
        a1 = -p1.a / p1.a;
        a2 = -p2.b / p2.c;
        b1 = -p1.c;
        b2 = -p2.c;
        x = (b2 - b1) / (a1 - a2);
        y = a1 * x + b1;
        return new Punkt(x, y);
    }
}
