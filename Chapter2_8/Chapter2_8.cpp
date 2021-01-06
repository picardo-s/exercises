#include <iostream>
#include <iomanip>

int main()
{
    long pop1 = 4789426, pop2 = 274124, pop3 = 9761;
    std::cout << std::setw(8) << "Location" << std::setw(12) << "Population" << std::endl
        << std::setw(8) << "Portcity" << std::setfill('.') << std::setw(12) << pop1 << std::endl
        << std::setw(8) << "Hightown" << std::setfill('.') << std::setw(12) << pop2 << std::endl
        << std::setw(5) << "Kirov" << std::setfill('.') << std::setw(15) << pop3 << std::endl;
}

