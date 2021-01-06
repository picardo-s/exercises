#include <iostream>

struct Sterling
{
    int pounds;
    int shillings;
    int pence;
};

int main()
{
    constexpr int penInShill = 12;
    constexpr int penInPound = 240;

    double decPounds, decFract;
    Sterling sterl;
    
    std::cout << "Enter an amount of decimal pounds: ";
    std::cin >> decPounds;

    sterl.pounds = static_cast<int>(decPounds);
    decFract = decPounds - sterl.pounds;
    sterl.shillings = (decFract * penInPound) / penInShill;
    sterl.pence = decFract * penInPound - sterl.shillings * penInShill;

    std::cout << 'J' << decPounds << " is equal to " << 'J' << sterl.pounds << "." << sterl.shillings 
                << "." << sterl.pence << '\n';
}
