import javax.swing.*;
import java.awt.*;

public class Menu {
    public JMenuBar mb;

    public Menu() {
        mb = new JMenuBar();
        Menu_Gra gra = new Menu_Gra();
        Menu_Ruchy ruchy = new Menu_Ruchy();
        Menu_Ustawienia ustawienia = new Menu_Ustawienia();
        Menu_Pomoc pomoc = new Menu_Pomoc();
        mb.add(gra.getMenu());
        mb.add(ruchy.getMenu());
        mb.add(ustawienia.getMenu());
        mb.add(Box.createHorizontalGlue());
        mb.add(pomoc.getMenu());
    }
}
