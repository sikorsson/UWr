package obliczenia.arg_2_operacje;

import obliczenia.Wyrazenie;
import obliczenia.arg_1_operacje.Arg_1;

import java.util.Objects;

public abstract class Arg_2 extends Arg_1 {
    public Wyrazenie b;

    @Override
    public String toString() {
        return "" + a + b;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Arg_2)) return false;
        Arg_2 that = (Arg_2) o;
        return Objects.equals(a, that.a) && Objects.equals(b, that.b);
    }
}
