package obliczenia.Instrukcja_operacje;

import obliczenia.Instrukcja;
import obliczenia.arg_2_operacje.Arg_2;

public class InstrukcjaWarunkowa_IfElse extends Instrukcja {
    private Arg_2 ex;
    private Instrukcja ins;
    private Instrukcja ins2;

    public InstrukcjaWarunkowa_IfElse(Arg_2 arg, Instrukcja cmd, Instrukcja cmd2) {
        if(arg == null || cmd == null || cmd2 == null) throw new NullPointerException();
        ex = arg;
        ins = cmd;
        ins2 = cmd2;
    }

    @Override
    public void wykonaj() throws Exception {
        if (ex.oblicz() == 1)
            ins.wykonaj();
        else
            ins2.wykonaj();
    }

    @Override
    public String toString() {
        return "if (" + ex.toString() + ") " + ins.toString() + "else\r\n" + ins2.toString() + "\r\n";
    }
}
