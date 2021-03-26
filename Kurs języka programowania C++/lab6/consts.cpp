#include "expr.hpp"

pi::pi() {
    value = 3.14159265359;
    name = "pi";
}

double pi::count() {
    return value;
}

string pi::describe() {
    return name;
}

e::e() {
    value = 2.71828182846;
    name = "e";
}

double e::count() {
    return value;
}

string e::describe() {
    return name;
}

phi::phi() {
    value = 1.61803;
    name = "fi";
}

double phi::count() {
    return value;
}

string phi::describe() {
    return name;
}