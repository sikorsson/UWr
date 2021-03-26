#ifndef EXPR_HPP
#define EXPR_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


class expr {
public:
    virtual double count() = 0;

    virtual string describe() = 0;

    virtual int priority() = 0;

    ~expr() = default;
};

class arg_1 : public expr {
public:
    expr *a;

    ~arg_1();
};

class arg_2 : public arg_1 {
public:
    expr *b;

    ~arg_2();
};

class variable : public expr {
private:
    string name;
    static vector<pair<string, double>> arr;

public:
    variable(string s);

    virtual double count();

    virtual string describe();

    static void add(string s, double val);

    static double print(string s);

    static void rem(string s);

    static bool isVar(string s);

    virtual int priority() {
        return 5;
    }
};

class number : public expr {
public:
    double value;

    number(double val);

    virtual double count();

    virtual string describe();

    virtual int priority() {
        return 5;
    }
};

class const_ : public expr {
public:
    double value;
    string name;

    virtual int priority() {
        return 5;
    }
};

class pi : public const_ {
public:
    pi();

    virtual double count();

    virtual string describe();
};

class e : public const_ {
public:
    e();

    virtual double count();

    virtual string describe();
};

class phi : public const_ {
public:
    phi();

    virtual double count();

    virtual string describe();
};

class Sin : public arg_1 {
public:
    Sin(expr *e);

    virtual double count();

    virtual string describe();

    virtual int priority() {
        return 4;
    }
};

class Cos : public arg_1 {
public:
    Cos(expr *e);

    virtual double count();

    virtual string describe();

    virtual int priority() {
        return 4;
    }
};

class Exp : public arg_1 {
public:
    Exp(expr *e);

    virtual double count();

    virtual string describe();

    virtual int priority() {
        return 4;
    }
};

class Abs : public arg_1 {
public:
    Abs(expr *e);

    virtual double count();

    virtual string describe();

    virtual int priority() {
        return 4;
    }
};

class opposite : public arg_1 {
public:
    opposite(expr *e);

    virtual double count();

    virtual string describe();

    virtual int priority() {
        return 4;
    }
};

class reciprocal : public arg_1 {
public:
    reciprocal(expr *e);

    virtual double count();

    virtual string describe();

    virtual int priority() {
        return 4;
    }
};

class Ln : public arg_1 {
public:
    Ln(expr *e);

    virtual double count();

    virtual string describe();

    virtual int priority() {
        return 4;
    }
};

class add : public arg_2 {
public:
    add(expr *l, expr *r);

    virtual double count();

    virtual string describe();

    virtual int priority() {
        return 1;
    }
};

class sub : public arg_2 {
public:
    sub(expr *l, expr *r);

    virtual double count();

    virtual string describe();

    virtual int priority() {
        return 1;
    }
};

class mult : public arg_2 {
public:
    mult(expr *l, expr *r);

    virtual double count();

    virtual string describe();

    virtual int priority() {
        return 2;
    }
};

class Div : public arg_2 {
public:
    Div(expr *l, expr *r);

    virtual double count();

    virtual string describe();

    virtual int priority() {
        return 2;
    }
};

class mod : public arg_2 {
public:
    mod(expr *l, expr *r);

    virtual double count();

    virtual string describe();

    virtual int priority() {
        return 2;
    }
};

class Log : public arg_2 {
public:
    Log(expr *l, expr *r);

    virtual double count();

    virtual string describe();

    virtual int priority() {
        return 3;
    }
};

class power : public arg_2 {
public:
    power(expr *l, expr *r);

    virtual double count();

    virtual string describe();

    virtual int priority() {
        return 3;
    }
};

#endif //EXPR_HPP
