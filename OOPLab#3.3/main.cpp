#include <iostream>
#include "money.h"

int main() {
    Money money1;
    Money money2(200, 25);
    Money money3(money2);

    std::cout << "Enter money 1 (units,subunits): ";
    std::cin >> money1;
    std::cout << "Money 1: " << money1 << std::endl;
    std::cout << "Money 2: " << money2 << std::endl;
    std::cout << "Money 3: " << money3 << std::endl;

    Money sum = money1.add(money2);
    std::cout << "Sum of money 1 and money 2: " << sum << std::endl;

    Money divided = money1.divide(3L);
    std::cout << "Money 1 divided by 3: " << divided << std::endl;

    Money dividedByDouble = money1.divide(3.5);
    std::cout << "Money 1 divided by 3.5: " << dividedByDouble << std::endl;

    return 0;
}
