package obliczenia.arg_1_operacje;

import obliczenia.Wyrazenie;
import java.util.Objects;

public abstract class Arg_1 extends Wyrazenie {
    public Wyrazenie a;

    @Override
    public String toString() {
        return String.valueOf(a);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Arg_1)) return false;
        Arg_1 that = (Arg_1) o;
        return Objects.equals(a, that.a);
    }
}