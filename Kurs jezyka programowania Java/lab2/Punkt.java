public class Punkt {
    private double x, y;

    public Punkt() {
        this(0, 0);
    }
    public Punkt(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public void przesun(Wektor v) {
        x += v.dx;
        y += v.dy;
    }
    public void obroc(Punkt p, double kat) {
        kat = Math.toRadians(kat);
        double tmp_x = Math.cos(kat) * (x - p.x) - Math.sin(kat) * (y - p.y) + p.x;
        double tmp_y = Math.sin(kat) * (x - p.x) + Math.cos(kat) * (y - p.y) + p.y;
        x = tmp_x;
        y = tmp_y;
    }
    public void odbij(Prosta p) {
        // prostopadła do p: y1 = a1*x + b1
        double a1 = p.b / p.a;
        double b1 = y - a1 * x;

        double mid_x = -1 * (p.c + p.b * b1) / (p.b * a1 + p.a);
        double mid_y = a1 * mid_x + b1;

        x = 2 * mid_x - x;
        y = 2 * mid_y - y;
    }

    public double getX() {
        return x;
    }
    public double getY() {
        return y;
    }

    public void print() {
        System.out.println(x + " " + y);
    }
}
