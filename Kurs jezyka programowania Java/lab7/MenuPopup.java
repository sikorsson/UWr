import javax.swing.*;

public class MenuPopup {
    private final JPopupMenu popupMenu = new JPopupMenu();
    JMenuItem mvUp = new JMenuItem("Skok w górę");
    JMenuItem mvDown = new JMenuItem("Skok w dół");
    JMenuItem mvLeft = new JMenuItem("Skok w lewo");
    JMenuItem mvRight = new JMenuItem("Skok w prawo");

    public MenuPopup() {
        mvUp.addActionListener(Menu_Ruchy.mvListener);
        mvDown.addActionListener(Menu_Ruchy.mvListener);
        mvLeft.addActionListener(Menu_Ruchy.mvListener);
        mvRight.addActionListener(Menu_Ruchy.mvListener);

        popupMenu.add(mvUp);
        popupMenu.add(mvDown);
        popupMenu.add(mvLeft);
        popupMenu.add(mvRight);
    }

    public JPopupMenu getJPopupMenu() {
        return popupMenu;
    }
}
