#include <iostream>
#include <conio.h>

const double TOLL = 0.5;

class tollBooth
{
private:
    unsigned int carCount;
    double cash;
public:
    tollBooth() : carCount(0), cash(0)
    {}
    void display() const
    {
        std::cout << "\nTotal: " << carCount << " cars, " << cash << "$\n";
    }
    void payingCar()
    {
        ++carCount;
        cash += TOLL;
    }
    void nopayCar() { ++carCount; }
};

int main()
{
    char manip = 'a';
    tollBooth toll;

    std::cout << "Press \'p\' if the fare is paid, \'u\' if unpaid.\n"
        << "Press ESC to exit\n\n";

    while ((manip = _getch()) != 27)
    {
        if (manip == 'p')
        {
            toll.payingCar();
            std::cout << "Paid\n";
        }
        else if (manip == 'u')
        {
            toll.nopayCar();
            std::cout << "Unpaid\n";
        }
        else
            std::cout << "Wrong button...\n";
    }
    toll.display();
}
