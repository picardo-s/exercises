#include <iostream>

struct Distance
{
    int feet;
    float inches;
};

struct Volume
{
    Distance length;
    Distance width;
    Distance height;
};

int main()
{
    int inchInFoot = 12;
    Volume vol = { {11, 6.25},
                   {12, 1.5} ,
                   {3, 9.75} };

    float length = vol.length.feet + vol.length.inches / inchInFoot;
    float width = vol.width.feet + vol.width.inches / inchInFoot;
    float height = vol.height.feet + vol.height.inches / inchInFoot;

    std::cout << "The volume is " << length * width * height << '\n';
                        
}

