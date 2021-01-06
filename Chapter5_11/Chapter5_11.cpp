#include <iostream>

constexpr int penInShill = 12;
constexpr int shilInPound = 20;

struct Sterling
{
    int pounds;
    int shillings;
    int pence;
};

Sterling getSterling();
Sterling sumSterling(const Sterling& sterl1, const Sterling& sterl2);
void displaySterling(const Sterling& sterl);


int main()
{
    Sterling sterl1, sterl2;

    std::cout << "Enter the first amount of pounds: ";
    sterl1 = getSterling();

    std::cout << "Enter the second amount of pounds: ";
    sterl2 = getSterling();

    Sterling sumSterl = sumSterling(sterl1, sterl2);
    displaySterling(sumSterl);
}

Sterling getSterling()
{
    int pound, shilling, penny;
    unsigned char charPound, charDiv;
    
    while(1)
    {
        std::cin >> charPound
                 >> pound
                 >> charDiv
                 >> shilling
                 >> charDiv
                 >> penny;

        if (std::cin.fail())
        {
            std::cin.ignore(1000, '\n');
            std::cin.clear();
            std::cout << "Wrong input. Try again: ";
            continue;
        }

        if (charPound != 'J' || charDiv != '.')
        {
            std::cout << "Wrong pound or division symbol. Try again: ";
            continue;
        }

        if (pound < 0 || (shilling < 0 || shilling >= shilInPound) || (penny < 0 || penny >= penInShill))
        {
            std::cout << "Overflow or negative input. Try again: ";
            continue;
        }
        break;
    }

    Sterling sterl = { pound, shilling, penny };
    return sterl;
}

Sterling sumSterling(const Sterling& sterl1, const Sterling& sterl2)
{
    Sterling sumSterl = { 0, 0, 0 };

    sumSterl.pence = sterl1.pence + sterl2.pence;
    if ((sterl1.pence + sterl2.pence) >= penInShill)
    {
        sumSterl.shillings += 1;
        sumSterl.pence -= penInShill;
    }

    sumSterl.shillings += (sterl1.shillings + sterl2.shillings);
    if ((sterl1.shillings + sterl2.shillings) >= shilInPound)
    {
        sumSterl.pounds += 1;
        sumSterl.shillings -= shilInPound;
    }

    sumSterl.pounds += (sterl1.pounds + sterl2.pounds);

    return sumSterl;
}

void displaySterling(const Sterling& sterl)
{
    std::cout << "The result is: J" << sterl.pounds << "." << sterl.shillings << "." << sterl.pence << '\n';
}