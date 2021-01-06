#include <iostream>

double power(double num, int pow = 2);

int main()
{
    double number, result;
    int pow;

    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "Enter a power of the number: ";
    std::cin >> pow;

    result = power(number, pow);
    std::cout << number << " to the power of " << pow << " is: " << result;
}

double power(double num, int pow)
{
    double result = 1;
    if (pow == 0)
        return result;
    for (; pow > 0; --pow)
        result *= num;
    return result;
}