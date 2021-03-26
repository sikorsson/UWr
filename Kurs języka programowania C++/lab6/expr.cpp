#include "expr.hpp"

arg_1::~arg_1() {
    delete a;
}

arg_2::~arg_2() {
    delete b;
}

variable::variable(string s) {
    name = s;
}

double variable::count() {
    if (isVar(name))
        return print(name);
    throw "Variable has no value";
}

string variable::describe() {
    return name;
}

void variable::add(string s, double val) {
    if (! isVar(s))
        arr.push_back(make_pair(s, val));
    else {
        for (auto i = arr.begin(); i != arr.end(); i ++) {
            if (i->first == s)
                i->second = val;
        }
    }
}

double variable::print(string s) {
    for (auto i = arr.begin(); i != arr.end(); i ++) {
        if (i->first == s)
            return i->second;
    }
}

void variable::rem(string s) {
    for (int i = 0; i != arr.size(); i ++) {
        if (arr[i].first == s)
            arr.erase(arr.begin() + i);
    }
}

bool variable::isVar(string s) {
    for (auto i = arr.begin(); i != arr.end(); i ++) {
        if (i->first == s)
            return true;
    }
    return false;
}

number::number(double val) {
    value = val;
}

double number::count() {
    return value;
}

string number::describe() {
    return to_string((int) value);
}

Sin::Sin(expr *e) {
    a = e;
}

double Sin::count() {
    return sin(a->count());
}

string Sin::describe() {
    return "sin(" + a->describe() + ")";
}

Cos::Cos(expr *e) {
    a = e;
}

double Cos::count() {
    return cos(a->count());
}

string Cos::describe() {
    return "cos(" + a->describe() + ")";
}


Exp::Exp(expr *e) {
    a = e;
}

double Exp::count() {
    return exp(a->count());
}

string Exp::describe() {
    return "exp(" + a->describe() + ")";
}

Abs::Abs(expr *e) {
    a = e;
}

double Abs::count() {
    return abs(a->count());
}

string Abs::describe() {
    return "|" + a->describe() + "|";
}

opposite::opposite(expr *e) {
    a = e;
}

double opposite::count() {
    return - 1 * a->count();
}

string opposite::describe() {
    return "opposite(" + a->describe() + ")";
}

reciprocal::reciprocal(expr *e) {
    a = e;
}

double reciprocal::count() {
    if (a->count() != 0)
        return 1 / a->count();
    throw "Can't divide by 0";
}

string reciprocal::describe() {
    return "reciprocal(" + a->describe() + ")";
}

Ln::Ln(expr *e) {
    a = e;
}

double Ln::count() {
    return log(a->count());
}

string Ln::describe() {
    return "ln(" + a->describe() + ")";
}

add::add(expr *l, expr *r) {
    a = l;
    b = r;
}

double add::count() {
    return a->count() + b->count();
}

string add::describe() {
    return a->describe() + " + " + b->describe();
}

sub::sub(expr *l, expr *r) {
    a = l;
    b = r;
}

double sub::count() {
    return a->count() - b->count();
}

string sub::describe() {
    if (b->priority() == priority())
        return a->describe() + " - (" + b->describe() + ")";
    return a->describe() + " - " + b->describe();
}

mult::mult(expr *l, expr *r) {
    a = l;
    b = r;
}

double mult::count() {
    return a->count() * b->count();
}

string mult::describe() {
    string l = a->describe();
    if (a->priority() <= priority())
        l = "(" + l + ")";
    string r = b->describe();
    if (b->priority() <= priority())
        r = "(" + r + ")";
    return l + " * " + r;
}

Div::Div(expr *l, expr *r) {
    a = l;
    b = r;
}

double Div::count() {
    if (b->count() != 0)
        return a->count() / b->count();
    throw "Can't divide by 0";
}

string Div::describe() {
    string l = a->describe();
    if (a->priority() <= priority())
        l = "(" + l + ")";
    string r = b->describe();
    if (b->priority() <= priority())
        r = "(" + r + ")";
    return l + " / " + r;
}

mod::mod(expr *l, expr *r) {
    a = l;
    b = r;
}

double mod::count() {
    return fmod(a->count(), b->count());
}

string mod::describe() {
    string l = a->describe();
    if (a->priority() <= priority())
        l = "(" + l + ")";
    string r = b->describe();
    if (b->priority() <= priority())
        r = "(" + r + ")";
    return l + " % " + r;
}

Log::Log(expr *l, expr *r) {
    a = l;
    b = r;
}

double Log::count() {
    return (log(b->count()) / log(a->count()));
}

string Log::describe() {
    string l = a->describe();
    if (a->priority() <= priority())
        l = "(" + l + ")";
    string r = b->describe();
    if (b->priority() <= priority())
        r = "(" + r + ")";
    return "log" + l + "of" + r;
}

power::power(expr *l, expr *r) {
    a = l;
    b = r;
}

double power::count() {
    return pow(a->count(), b->count());
}

string power::describe() {
    string l = a->describe();
    if (a->priority() <= priority())
        l = "(" + l + ")";
    string r = b->describe();
    if (b->priority() <= priority())
        r = "(" + r + ")";
    return l + " ^ " + r;
}