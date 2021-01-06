#include <iostream>

int main()
{
    double fahrenheit;
    std::cout << "Enter a value of temperature in C: ";
    std::cin >> fahrenheit;
    std::cout << (fahrenheit * 9 / 5 + 32) << '\n';
}
