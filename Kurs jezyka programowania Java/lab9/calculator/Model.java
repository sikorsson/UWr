package calculator;

import java.math.BigInteger;

public class Model {
    BigInteger result;
    public BigInteger calc(BigInteger a, BigInteger b, String op) {
        switch (op) {
            case "+":
                result = a.add(b);
                break;
            case "-":
                result = a.subtract(b);
                break;
            case "*":
                result = a.multiply(b);
                break;
            case "/":
                if (b.equals(BigInteger.ZERO))
                    throw new IllegalArgumentException();
                else
                    result = a.divide(b);
                break;
            case "%":
                if (b.signum() != 1)
                    throw new IllegalArgumentException();
                else
                    result = a.mod(b);
                break;
            case "n!":
                    result = factorial(a);
                break;
            case "(n k)":
                result = binomial_coefficient(a, b);
                break;
            case "x^y":
                result = pow(a, b);
                break;
        }
        return result;
    }

    private BigInteger factorial(BigInteger n) {
        if (n.signum() == -1)
            throw new IllegalArgumentException();
        BigInteger res = BigInteger.ONE;
        while (!n.equals(BigInteger.ZERO)) {
            res = res.multiply(n);
            n = n.subtract(BigInteger.ONE);
        }
        return res;
    }

    private BigInteger binomial_coefficient(BigInteger n, BigInteger k) {
        if (n.signum() == -1 || k.signum() == -1 || n.compareTo(k) < 0)
            throw new IllegalArgumentException();
        BigInteger num = factorial(n);
        BigInteger den = factorial(k).multiply(factorial(n.subtract(k)));
        return num.divide(den);
    }

    private BigInteger pow(BigInteger x, BigInteger y) {
        if (y.signum() == -1)
            return BigInteger.ZERO;
        if (y.signum() == 0)
            return new BigInteger("1");
        BigInteger tmp = x;
        y = y.subtract(BigInteger.ONE);
        while (!y.equals(BigInteger.ZERO)) {
            x = x.multiply(tmp);
            y = y.subtract(BigInteger.ONE);
        }
        return x;
    }
}
