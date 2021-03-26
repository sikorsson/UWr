package obliczenia.Instrukcja_operacje;

import obliczenia.Instrukcja;
import obliczenia.arg_2_operacje.Arg_2;

public class InstrukcjaWarunkowa_If extends Instrukcja {
    private Arg_2 ex;
    private Instrukcja ins;

    public InstrukcjaWarunkowa_If(Arg_2 arg, Instrukcja cmd) {
        if(arg == null || cmd == null) throw new NullPointerException();
        ex = arg;
        ins = cmd;
    }

    @Override
    public void wykonaj() throws Exception {
        if (ex.oblicz() == 1)
            ins.wykonaj();
    }

    @Override
    public String toString() {
        return "if (" + ex.toString() + ") " + ins.toString() + "\r\n";
    }
}
