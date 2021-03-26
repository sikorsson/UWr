package calculator;

import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.text.*;
import javafx.event.*;

import java.math.BigInteger;

public class Controller {
    @FXML
    private Text result;
    @FXML
    private Text last;

    private BigInteger number = BigInteger.ZERO;
    private int radix = 10;
    private String operator = "";
    private boolean start = true;
    private boolean nextNum = false;
    private boolean error = false;

    private final Model model = new Model();

    @FXML
    private void getNumpad(ActionEvent e) {
        if(error) {
            clearNumbers();
        }
        else if(start) {
            result.setText("");
            last.setText("");
            start = false;
        }
        else if(nextNum) {
            result.setText("");
            nextNum = false;
        }
        String value = ((Button)e.getSource()).getText();
        if(result.getText().equals("0"))
            result.setText(value);
        else
            result.setText(result.getText() + value);
    }

    @FXML
    private void negNumber() {
        if(error || result.getText().equals(""))
            return;
        number = new BigInteger(result.getText(), radix);
        number = number.negate();
        result.setText(number.toString(radix));
    }

    @FXML
    private void undoNumber() {
        if(error || result.getText().equals(""))
            return;
        number = new BigInteger(result.getText(), radix);
        number = number.divide(new BigInteger(String.valueOf(radix)));
        result.setText(number.toString(radix));
    }

    @FXML
    private void clearNumbers() {
        result.setText("");
        last.setText("");
        number = BigInteger.ZERO;
        operator = "";
        start = true;
        nextNum = false;
        error = false;
    }

    @FXML
    private void getOperator(ActionEvent e) {
        if(error)
            return;

        String value = ((Button)e.getSource()).getText();
        if(!"=".equals(value) && !"n!".equals(value)) {
            if (!operator.isEmpty() || result.getText().equals(""))
                return;
            operator = value;
            number = new BigInteger(result.getText(), radix);
            start = false;
            nextNum = true;
            last.setText(result.getText() + " " + operator);
            return;
        }
        BigInteger num1;
        BigInteger num2;

        if("=".equals(value)) {
            if (operator.isEmpty())
                return;
            num1 = number;
            num2 = new BigInteger(result.getText(), radix);
        }
        else {
            if (result.getText().equals(""))
                return;
            num1 = new BigInteger(result.getText(), radix);
            num2 = BigInteger.ZERO;
            operator = value;
        }
        try {
            BigInteger res = model.calc(num1, num2, operator);
            result.setText(res.toString(radix));
        }
        catch (Exception exception) {
            result.setText("math error");
            error = true;
        }
        operator = "";
        start = true;
        nextNum = false;
        last.setText(result.getText());
    }

    @FXML
    private void changeRadix(ActionEvent e) {
        if(error) {
            clearNumbers();
        }
        String value = ((ToggleButton)e.getSource()).getText();
        BigInteger res = BigInteger.ZERO;
        if(!result.getText().equals(""))
            res = new BigInteger(result.getText(), radix);
        switch (value) {
            case "bin" -> radix = 2;
            case "dec" -> radix = 10;
            case "hex" -> radix = 16;
        }
        result.setText(res.toString(radix));
    }
}