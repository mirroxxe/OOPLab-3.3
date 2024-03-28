#include "money.h"

Money::Money() : Currency() {}

Money::Money(long u, unsigned char s) : Currency(u, s) {}

Money::Money(const Money& other) : Currency(other) {}

Money::~Money() {}

Money& Money::operator=(const Money& other) {
    if (this != &other) {
        units = other.units;
        subunits = other.subunits;
    }
    return *this;
}

Money Money::add(const Money& other) const {
    long totalUnits = units + other.units;
    unsigned char totalSubunits = subunits + other.subunits;
    if (totalSubunits >= 100) {
        totalUnits++;
        totalSubunits -= 100;
    }
    return Money(totalUnits, totalSubunits);
}

Money Money::divide(long divisor) const {
    long totalSubunits = units * 100 + subunits;
    totalSubunits /= divisor;
    long totalUnits = totalSubunits / 100;
    totalSubunits %= 100;
    return Money(totalUnits, totalSubunits);
}

Money Money::divide(double divisor) const {
    double total = units + (subunits / 100.0);
    total /= divisor;
    long totalUnits = static_cast<long>(total);
    unsigned char totalSubunits = static_cast<unsigned char>((total - totalUnits) * 100);
    return Money(totalUnits, totalSubunits);
}

std::istream& operator>>(std::istream& is, Money& money) {
    is >> money.units >> money.subunits;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Money& money) {
    os << money.units << "," << static_cast<int>(money.subunits);
    return os;
}
