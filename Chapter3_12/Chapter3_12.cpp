#include <iostream>

int main()
{
    int a, b, c, d;
    char fractChar, oper;

    do
    {
        std::cout << "Enter the first fraction: ";
        std::cin >> a >> fractChar >> b;
        std::cout << "Enter an operator(+, -, / or *): ";
        std::cin >> oper;
        std::cout << "Enter the second fraction: ";
        std::cin >> c >> fractChar >> d;
        std::cout << "The result is: ";

        switch (oper)
        {
            case '+': std::cout << (a * d + b * c) << fractChar << (b * d); break;
            case '-': std::cout << (a * d - b * c) << fractChar << (b * d); break;
            case '/': std::cout << (a * d) << fractChar << (b * c); break;
            case '*': std::cout << (a * c) << fractChar << (b * d); break;
            default: std::cout << "Smth went wrong...";
        }
        std::cout << '\n' << "One more time (y/n)? ";
        std::cin >> oper;
    } while (oper != 'n');
}