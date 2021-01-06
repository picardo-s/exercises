#include <iostream>
#include <conio.h>
int main()
{
    char ch = 'a';
    long sum = 0;
    int count = 0;

    std::cout << "Enter a number: ";
    while (count < 6)
    {
        ch = _getche();
        sum += static_cast<long>(ch - '0');
        if (count < 5)
            sum *= 10;
        ++count;
    }
    std::cout << '\n' << "You entered: " << sum << '\n';
}

