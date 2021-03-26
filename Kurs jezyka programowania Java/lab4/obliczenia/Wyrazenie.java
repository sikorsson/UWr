package obliczenia;

public abstract class Wyrazenie implements Obliczalny {
    /** metoda sumująca wyrażenia */
    public static double suma (Wyrazenie... wyr) throws Exception {
        double suma = 0;
        for(Wyrazenie w : wyr){
            suma += w.oblicz();
        }
        return suma;
    }

    /** metoda mnożąca wyrażenia */
    public static double iloczyn (Wyrazenie... wyr) throws Exception {
        double iloczyn = 0;
        for(Wyrazenie w : wyr){
            iloczyn *= w.oblicz();
        }
        return iloczyn;
    }

}
