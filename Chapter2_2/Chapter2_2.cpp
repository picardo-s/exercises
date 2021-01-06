#include <iostream>
#include <iomanip>

int main()
{
    std::cout << 1990 << std::setw(10) << 125 << '\n'
        << 1991 << std::setw(10) << 7290 << '\n'
        << 1992 << std::setw(10) << 11300 << '\n'
        << 1993 << std::setw(10) << 16200;
}

