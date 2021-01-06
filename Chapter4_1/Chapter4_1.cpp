#include <iostream>

struct Phone
{
    int cityNumber;
    int stationNumber;
    int personNumber;
};

int main()
{
    Phone phone1 = { 212,767,8900 };
    Phone phone2;
    
    std::cout << "Enter a city number, a station number and a person number: ";
    std::cin >> phone2.cityNumber >> phone2.stationNumber >> phone2.personNumber;

    std::cout << "My phone number is: (" << phone1.cityNumber << ") " << phone1.stationNumber
        << "-" << phone1.personNumber << '\n';
    std::cout << "Your phone number is: (" << phone2.cityNumber << ") " << phone2.stationNumber
        << "-" << phone2.personNumber << '\n';
}
