#include <iostream>

int main()
{
    int a, b, c, d;
    char fractChar;
    std::cout << "Enter the first fraction: ";
    std::cin >> a >> fractChar >> b;
    std::cout << "Enter the second fraction: ";
    std::cin >> c >> fractChar >> d;
    std::cout << "Sum = " << (a * d + b * c) << "/" << (b * d) << '\n';
}
