#ifndef INC_7_WYJATEK_WYMIERNY_HPP
#define INC_7_WYJATEK_WYMIERNY_HPP
#include <iostream>
#include <stdexcept>

class wyjatek_wymierny: public std::exception { //https://stackoverflow.com/questions/8152720/correct-way-to-inherit-from-stdexception
protected:
    std::string msg_;
public:
    wyjatek_wymierny(std::string message);
    virtual const char* what() const throw () {
        return msg_.c_str();
    }
};

class dzielenie_przez_0: public wyjatek_wymierny {
public:
    dzielenie_przez_0(std::string message);
};

class przekroczenie_zakresu: public wyjatek_wymierny {
public:
    przekroczenie_zakresu(std::string message);
};

#endif //INC_7_WYJATEK_WYMIERNY_HPP
