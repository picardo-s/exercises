#include <iostream>

int main()
{
    double startRate, totalRate;
    int year = 0;
    double percent;

    std::cout << "Enter a starting rate: ";
    std::cin >> startRate;
    std::cout << "Enter a total rate: ";
    std::cin >> totalRate;
    std::cout << "Enter a percentage: ";
    std::cin >> percent;

    for (; startRate <= totalRate; ++year)
        startRate = startRate + startRate * (percent / 100);

    std::cout << "You will need around " << year << " year(s) to get " << totalRate;
}