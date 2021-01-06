#include <iostream>

int main()
{
    double rate;
    int year;
    double percent;

    std::cout << "Enter a starting rate: ";
    std::cin >> rate;
    std::cout << "Enter an amount of years: ";
    std::cin >> year;
    std::cout << "Enter a percentage: ";
    std::cin >> percent;

    for (int i = 0; i < year; ++i)
        rate = rate + rate * (percent / 100);

    std::cout << "After " << year << " year(s) You will get " << rate;
}

