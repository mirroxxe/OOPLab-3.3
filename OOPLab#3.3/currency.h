#pragma once
#ifndef CURRENCY_H
#define CURRENCY_H

#include <iostream>
#include <string>

class Currency {
protected:
    long units;
    unsigned char subunits;

public:
    Currency();
    Currency(long u, unsigned char s);
    Currency(const Currency& other);

    friend std::ostream& operator<<(std::ostream& os, const Currency& currency);
    friend std::istream& operator>>(std::istream& is, Currency& currency);

    operator std::string() const;
};

#endif 
