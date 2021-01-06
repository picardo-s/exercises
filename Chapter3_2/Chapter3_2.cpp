#include <iostream>

int main()
{
    double temperature;
    int option;

    std::cout << "Enter 1 if you want to convert degrees celsius to degrees fahrenheit" << '\n'
        << " or 2 for converting vice versa: ";
    std::cin >> option;

    if (option == 1)
    {
        std::cout << "Enter an amount of degrees celsius: ";
        std::cin >> temperature;
        std::cout << (temperature * 9 / 5 + 32) << " degrees fahrenheit";
    }
    else if (option == 2)
    {
        std::cout << "Enter an amount of degrees fahrenheit: ";
        std::cin >> temperature;
        std::cout << ((temperature - 32) *  5 / 9) << " degrees celsius";
    }

}
