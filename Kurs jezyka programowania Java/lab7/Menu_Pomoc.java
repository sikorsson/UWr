import javax.swing.*;
import java.awt.event.ActionListener;

public class Menu_Pomoc {
    private final JMenu menu = new JMenu("Pomoc");
    JMenuItem aboutGame = new JMenuItem("O grze");
    JMenuItem aboutApp = new JMenuItem("O aplikacji");


    ActionListener textListener = e -> {
        JMenuItem item = (JMenuItem) e.getSource();
        String text = "";
        if(item.getText().equals("O grze"))
            text = "Celem gry jest zostawienie na planszy jak najmniejszej liczby pionków.<br/>" +
                    "Idealnym rozwiązaniem jest pozostawienie jednego pionka, najlepiej w centrum.<br/> Pionka bije się przeskakując go w pionie lub w poziomie.<br/>" +
                    "Nie można poruszać się na ukos oraz nie można bić kilku pionków w jednym ruchu.";
        else if(item.getText().equals("O aplikacji"))
            text = "Autor: Paweł Sikora<br/>" +
                    "Wersja: 1.0<br/>" +
                    "Data powstania: 01.12.2020";
        JDialog dialog = new JDialog();
        dialog.setTitle("O grze");
        JLabel label = new JLabel("<html><div style='text-align: center;'>" + text + "</div></html>");
        dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
        dialog.add(label);
        dialog.pack();
        dialog.setVisible(true);
    };

    public Menu_Pomoc() {
        aboutGame.addActionListener(textListener);
        aboutApp.addActionListener(textListener);

        menu.add(aboutGame);
        menu.add(aboutApp);
    }

    public JMenu getMenu() {
        return menu;
    }
}
