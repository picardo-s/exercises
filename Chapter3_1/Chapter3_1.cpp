#include <iostream>
#include <iomanip>

int main()
{
    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;
    for (int i = 1; i <= 200; ++i)
    {
        std::cout << std::setw(5) << num * i;
        if (i % 10 == 0)
            std::cout << '\n';
    }
}

