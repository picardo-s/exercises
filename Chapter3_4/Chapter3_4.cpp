#include <iostream>

int main()
{
    char oper;
    double firstOperand, secondOperand;
    do
    {
        std::cout << "Enter the first operand, operator and the second operand: ";
        std::cin >> firstOperand >> oper >> secondOperand;
        std::cout << "The result is: ";
        switch (oper)
        {
            case '+': std::cout << firstOperand + secondOperand; break;
            case '-': std::cout << firstOperand - secondOperand; break;
            case '*': std::cout << firstOperand * secondOperand; break;
            case '/': std::cout << firstOperand / secondOperand; break;
            default: std::cout << "Something went wrong..."; 
        }
        std::cout << '\n' << "One more time (y/n)? ";
        std::cin >> oper;
    } while (oper != 'n');
}

