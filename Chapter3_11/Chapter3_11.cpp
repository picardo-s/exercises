#include <iostream>

int main()
{
    int shillInPound = 20;
    int penInShill = 12;
    int penInPound = 240;

    int pound, shilling, penny;
    int sumPound_1, sumPound_2, result, multipl;
    unsigned char char_pound;
    char ch, oper;

    do
    {
        std::cout << "Enter the first operand: ";
        std::cin >> char_pound >> pound >> ch >> shilling >> ch >> penny;
        if (shilling > shillInPound || penny > penInShill)
        {
            std::cout << "Wrong input! Try again\n";
            continue;
        }

        sumPound_1 = pound * penInPound + shilling * penInShill + penny;

        while (1)
        {
            std::cout << "Enter an operator (+, - or *): ";
            std::cin >> oper;
            if (oper != '+' && oper != '-' && oper != '*')
            {
                std::cout << "Wrong operator! Try again\n";
                continue;
            }
            else break;
        }
        if (oper == '*')
        {
            std::cout << "Enter an integer: ";
            std::cin >> multipl;
        }
        else
            while(1)
            {
                std::cout << "Enter the second operand: ";
                std::cin >> char_pound >> pound >> ch >> shilling >> ch >> penny;
                if (shilling > shillInPound || penny > penInShill)
                {
                    std::cout << "Wrong input! Try again\n";
                    continue;
                }
                else
                {
                    sumPound_2 = pound * penInPound + shilling * penInShill + penny;
                    break;
                }
            }
        switch (oper)
        {
            case '+': result = sumPound_1 + sumPound_2; break;
            case '-': result = sumPound_1 - sumPound_2; break;
            case '*': result = sumPound_1 * multipl; break;
            default: std::cout << "Something went wrong...\n"; continue;
        }

        pound = result / penInPound;
        if (std::abs(result) >= penInPound)
            result -= pound * penInPound;
        
        shilling = result / penInShill;
        if (std::abs(result) >= penInShill)
            result -= shilling * penInShill;

        penny = result;

        std::cout << "The total is: " << char_pound << pound << ch << shilling << ch << penny << '\n';
        std::cout << "Continue(y/n)? ";
        std::cin >> ch;

    } while (ch != 'n');
}