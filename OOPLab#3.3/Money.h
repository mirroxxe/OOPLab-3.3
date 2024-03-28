#ifndef MONEY_H
#define MONEY_H

#include "currency.h"

class Money : public Currency {
public:
    Money();
    Money(long u, unsigned char s);
    Money(const Money& other);
    ~Money();

    Money& operator=(const Money& other);

    Money add(const Money& other) const;
    Money divide(long divisor) const;
    Money divide(double divisor) const;
    friend std::istream& operator>>(std::istream& is, Money& money);
    friend std::ostream& operator<<(std::ostream& os, const Money& money);
};

#endif 