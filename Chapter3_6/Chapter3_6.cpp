#include <iostream>

int main()
{
    unsigned int numb;
    unsigned long fact;

    do
    {
        fact = 1;
        std::cout << "Enter an integer: ";
        std::cin >> numb;
        if (numb == 0)
            break;
        for (int j = numb; j > 0; j--)
            fact *= j;
        std::cout << "The factorial of " << numb << " is " << fact << '\n';
    } while (1);
}

