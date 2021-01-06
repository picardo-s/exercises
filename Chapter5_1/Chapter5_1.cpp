#include <iostream>

const float PI = 3.14159f;
float circarea(float radius);

int main()
{
    float radius;
    std::cout << "Enter a radius of a circle: ";
    std::cin >> radius;
    std::cout << "Area of the circle is: " << circarea(radius);
}

float circarea(float radius)
{
    return (PI * radius * radius);
}