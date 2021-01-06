#include <iostream>

double power(double num, int pow = 2);
double power(float num, int pow = 2);
double power(long num, int pow = 2);
double power(int num, int pow = 2);
double power(char num, int pow = 2);


int main()
{
    double doubleNum = 3.0, result;
    float floatNum = 5.0F;
    long longNum = 7L;
    int intNum = 8, pow;
    char charNum = 'a';

    std::cout << "Enter a power of a number: ";
    std::cin >> pow;

    result = power(doubleNum, pow);
    std::cout << doubleNum << " to the power of " << pow << " is: " << result << '\n';

    result = power(floatNum, pow);
    std::cout << floatNum << " to the power of " << pow << " is: " << result << '\n';

    result = power(longNum, pow);
    std::cout << longNum << " to the power of " << pow << " is: " << result << '\n';

    result = power(intNum, pow);
    std::cout << intNum << " to the power of " << pow << " is: " << result << '\n';

    result = power(charNum, pow);
    std::cout << charNum << " to the power of " << pow << " is: " << result << '\n';
}

double power(double num, int pow)
{
    std::cout << "\nDouble!" << '\n';
    double result = 1;
    if (pow == 0)
        return result;
    for (; pow > 0; --pow)
        result *= num;
    return result;
}

double power(float num, int pow)
{
    std::cout << "\nFloat!" << '\n';
    float result = 1;
    if (pow == 0)
        return result;
    for (; pow > 0; --pow)
        result *= num;
    return result;
}

double power(long num, int pow)
{
    std::cout << "\nLong!" << '\n';
    long result = 1;
    if (pow == 0)
        return result;
    for (; pow > 0; --pow)
        result *= num;
    return result;
}

double power(int num, int pow)
{
    std::cout << "\nInt!" << '\n';
    int result = 1;
    if (pow == 0)
        return result;
    for (; pow > 0; --pow)
        result *= num;
    return result;
}

double power(char num, int pow)
{
    std::cout << "\nChar!" << '\n';
    char result = 1;
    if (pow == 0)
        return result;
    for (; pow > 0; --pow)
        result *= num;
    return result;
}