#include <iostream>

struct Fraction
{
    int numerator;
    int denominator;
};

int main()
{
    Fraction fract1, fract2, fract3;
    char fractChar;

    std::cout << "Enter the first fraction: ";
    std::cin >> fract1.numerator >> fractChar >> fract1.denominator;
    std::cout << "Enter the second fraction: ";
    std::cin >> fract2.numerator >> fractChar >> fract2.denominator;

    fract3.numerator = fract1.numerator * fract2.denominator + fract1.denominator * fract2.numerator;
    fract3.denominator = fract1.denominator * fract2.denominator;

    std::cout << "The sum is " << fract3.numerator << fractChar << fract3.denominator;
}