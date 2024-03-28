#include "currency.h"

Currency::Currency() : units(0), subunits(0) {}

Currency::Currency(long u, unsigned char s) : units(u), subunits(s) {}

Currency::Currency(const Currency& other) : units(other.units), subunits(other.subunits) {}

std::ostream& operator<<(std::ostream& os, const Currency& currency) {
    os << currency.units << "," << static_cast<int>(currency.subunits);
    return os;
}

std::istream& operator>>(std::istream& is, Currency& currency) {
    is >> currency.units >> currency.subunits;
    return is;
}

Currency::operator std::string() const {
    return std::to_string(units) + "," + std::to_string(subunits);
}
