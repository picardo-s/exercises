#include <iostream>

struct Distance
{
    int feet;
    float inches;
};

Distance maxDistance(Distance d1, Distance d2);

int main()
{
    Distance d1, d2, d3;

    std::cout << "Enter an amount of feet and inches (1): ";
    std::cin >> d1.feet >> d1.inches;
    std::cout << "Enter an amount of feet and inches (2): ";
    std::cin >> d2.feet >> d2.inches;

    d3 = maxDistance(d1, d2);
    std::cout << "The max Distance has " << d3.feet << " feet and " << d3.inches << " inches";
}

Distance maxDistance(Distance d1, Distance d2)
{
    Distance maxDist;
    float dist1 = d1.feet + d1.inches / 12;
    float dist2 = d2.feet + d2.inches / 12;
    if (dist1 > dist2)
        return d1;
    else return d2;
}