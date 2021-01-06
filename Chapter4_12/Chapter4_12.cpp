#include <iostream>

struct Fraction
{
    int numerator;
    int denominator;
};

int main()
{
    char fractChar, oper;
    Fraction fract1, fract2, resultFract;

    do
    {
    std::cout << "Enter the first fraction: ";
    std::cin >> fract1.numerator >> fractChar >> fract1.denominator;
    std::cout << "Enter an operator(+, -, / or *): ";
    std::cin >> oper;
    std::cout << "Enter the second fraction: ";
    std::cin >> fract2.numerator >> fractChar >> fract2.denominator;
    
    if (oper != '+' && oper != '-' && oper != '/' && oper != '*')
    {
        std::cout << "Try again!\n";
        continue;
    }
    
    switch (oper)
        {
        case '+':
            resultFract.numerator = fract1.numerator * fract2.denominator + fract1.denominator * fract2.numerator;
            resultFract.denominator = fract1.denominator * fract2.denominator;
            break;
        case '-':
            resultFract.numerator = fract1.numerator * fract2.denominator - fract1.denominator * fract2.numerator;
            resultFract.denominator = fract1.denominator * fract2.denominator;
            break;
        case '/':
            resultFract.numerator = fract1.numerator * fract2.denominator;
            resultFract.denominator = fract1.denominator * fract2.numerator;
            break;
        case '*':
            resultFract.numerator = fract1.numerator * fract2.numerator;
            resultFract.denominator = fract1.denominator * fract2.denominator;
            break;
        }
    std::cout << "The result is " << resultFract.numerator << fractChar << resultFract.denominator;
    std::cout << '\n' << "One more time (y/n)? ";
    std::cin >> oper;
    } while (oper != 'n');
}