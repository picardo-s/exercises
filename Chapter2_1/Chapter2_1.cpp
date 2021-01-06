#include <iostream>

int main()
{
    double gallonsInCubicFoot = 7.481;
    double gallons;
    std::cout << "Enter an amount of gallons: ";
    std::cin >> gallons;
    std::cout << gallons / gallonsInCubicFoot << " cubic foot(feet)\n";
}


