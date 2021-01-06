#include <iostream>

int main()
{
    double decPounds;
    int pounds;
    double decFract;

    std::cout << "Enter an amount of decimal pound: ";
    std::cin >> decPounds;

    pounds = static_cast<int>(decPounds);
    decFract = decPounds - pounds;

    int penInPound = 240;
    int penInShill = 12;
    unsigned char poundCh = 156;

    int shilling = (decFract * penInPound) / penInShill;
    int penny = decFract * penInPound - shilling * penInShill; //int penny = static_cast<int>(decFract * penInPound) % penInShill;
    std::cout << "An equivalent sum is " << poundCh << pounds << "." << shilling << "." << penny;
}