#include <iostream>

int main()
{
    int penInShill = 12;
    int penInPound = 240;
    unsigned char poundCh = 156;

    int pound;
    int shilling;
    int penny;

    std::cout << "Enter an amount of pound: ";
    std::cin >> pound;
    std::cout << "Enter an amount of shilling: ";
    std::cin >> shilling;
    std::cout << "Enter an amount of penny: ";
    std::cin >> penny;

    std::cout << "Decimal pounds: " << poundCh << pound +(static_cast<double>(shilling * penInShill + penny) / penInPound); // можно указать число после знаков, но на момент данной главы
                                                                                                                            // об этом не упоминалось. std::setprecision(3) <iomanip>
}
