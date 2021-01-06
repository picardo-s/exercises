#include <iostream>

int main()
{
    int guest;
    int chair;
    int count = 1;

    std::cout << "Enter an amount of guests: ";
    std::cin >> guest;
    std::cout << "Enter an amount of chairs: ";
    std::cin >> chair;

    if (chair > guest)
        std::cout << "The amount of chairs is more than the amount of guests\n";
    else
    {
        for (; chair > 0; chair--, guest--)
            count *= guest;

        std::cout << "The amount of different placings of Your guests is " << count;
    }
}

