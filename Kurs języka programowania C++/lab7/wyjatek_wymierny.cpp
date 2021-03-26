#include "wyjatek_wymierny.hpp"

wyjatek_wymierny::wyjatek_wymierny(std::string message) :
        msg_(message) {}

dzielenie_przez_0::dzielenie_przez_0(std::string message) :
        wyjatek_wymierny(message) {}

przekroczenie_zakresu::przekroczenie_zakresu(std::string message) :
        wyjatek_wymierny(message) {}