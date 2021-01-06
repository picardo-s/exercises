#include <iostream>

int main()
{
    double dollarsInPound = 1.487;
    double dollarsInFrank = 0.172;
    double dollarsInMark = 0.584;
    double dollarsInYen = 0.00955;
    
    double dollar;
    std::cout << "Enter an amount of dollars: ";
    std::cin >> dollar;
    std::cout << dollar / dollarsInPound << " pound(s).\n"
        << dollar / dollarsInFrank << " frank(s).\n"
        << dollar / dollarsInMark << " mark(s).\n"
        << dollar / dollarsInYen << " yen(s)";
}
