#include <iostream>
#include <ctype.h>    

int main()
{
    char ch;
    std::cout << "Enter a character: ";
    std::cin >> ch;
    std::cout << islower(ch);
}

