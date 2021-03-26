package test;

import struktury.Para;
import struktury.ZbiorNaTablicy;
import struktury.ZbiorNaTablicyDynamicznej;

public class test {
    public static void testy() throws Exception {
        ZbiorNaTablicyDynamicznej z = new ZbiorNaTablicyDynamicznej();

        Para p1 = new Para("a", 1);
        Para p2 = new Para("b", 2);
        Para p3 = new Para("c", 3);
        Para p4 = new Para("d", 4);
        Para p5 = new Para("e", 5);
        Para p6 = new Para("e", 6);

        z.wstaw(p1);
        z.wstaw(p2);
        z.wstaw(p3);
        z.wstaw(p4);
        z.wstaw(p5);

        System.out.println(z.ile());

        z.usun("a");
        z.usun("b");
        z.usun("c");

        z.ustaw(p6);

        System.out.println(z.czytaj("e"));

        z.czysc();
    }
}
