#include <iostream>

int main()
{
    int shillInPound = 20;
    int penInShill = 12;

    int pound_1, shilling_1, penny_1;
    int pound_2, shilling_2, penny_2;
    char char_pound, ch;

    do
    {
        std::cout << "Enter the first amount: ";
        std::cin >> char_pound >> pound_1 >> ch >> shilling_1 >> ch >> penny_1;
        std::cout << "Enter the second amount: ";
        std::cin >> char_pound >> pound_2 >> ch >> shilling_2 >> ch >> penny_2;

        if (penny_1 + penny_2 > penInShill)
        {
            shilling_1 += 1;
            penny_1 = (penny_1 + penny_2) - penInShill;
        }
        else if (penny_1 + penny_2 == penInShill)
        {
            shilling_1 += 1;
            penny_1 = 0;
        }
        else
            penny_1 += penny_2;

        if (shilling_1 + shilling_2 > shillInPound)
        {
            pound_1 += 1;
            shilling_1 = (shilling_1 + shilling_2) - shillInPound;
        }
        else if (shilling_1 + shilling_2 > shillInPound)
        {
            pound_1 += 1;
            shilling_1 = 0;
        }
        else
            shilling_1 += shilling_2;

        pound_1 += pound_2;

        std::cout << "The total is " << char_pound << pound_1 << ch << shilling_1 << ch << penny_1 << '\n';
        std::cout << "Continue(y/n)? ";
        std::cin >> ch;

    } while (ch != 'n');
}
