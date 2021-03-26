public class Wektor {
    public final double dx, dy;

    public Wektor(double dx, double dy) {
        this.dx = dx;
        this.dy = dy;
    }

    public static Wektor zloz_wektory(Wektor w1, Wektor w2) {
        double dx, dy;
        dx = w1.dx + w2.dx;
        dy = w1.dy + w2.dy;
        return new Wektor(dx, dy);
    }
}
