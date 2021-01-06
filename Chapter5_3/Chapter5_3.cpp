#include <iostream>

void zeroSmaller(int& a, int& b);

int main()
{
    int a, b, min;
    
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;

    min = a < b ? a : b;
    zeroSmaller(a, b);
    if (a != min && b != min)
        std::cout << "zeroSmaller() is correct";
    else
        std::cout << "zeroSmaller() is\'t correct";
}

void zeroSmaller(int& a, int& b)
{
    if (a < b)
        a = 0;
    else
        b = 0;
}