#include <iostream>
#include "expr.hpp"

using namespace std;

vector<pair<string, double>> variable::arr;

int main() {
    expr *ex;

    //3 ^ (7 % 5) * 2 + 2 = 20
    ex = new add(
            new mult(
                    new power(
                            new number(3), new mod(
                                    new number(7), new number(5))),
                    new number(2)),
            new number(2)
    );
    cout << ex->describe() << " = " << ex->count() << endl;

    //ln e
    ex = new Ln(new e());
    cout << ex->describe() << " = " << ex->count() << endl;

    //x ^ 2 + x + 5
    ex = new add(
            new power(new variable("x"), new number(2)),
            new add(
                    new variable("x"),
                    new number(5)
            )
    );
    variable::add("x", 4);
    cout << ex->describe() << " = " << ex->count() << endl;

    //1 - 3 - (5 - 4 - 8) = 5
    ex = new sub(
            new sub(new number(1), new number(3)),
            new sub(
                    new sub(new number(5), new number(4)),
                    new number(8)
            )
    );
    cout << ex->describe() << " = " << ex->count() << endl;
}