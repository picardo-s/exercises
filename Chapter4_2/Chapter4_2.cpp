#include <iostream>

struct Point
{
    int x;
    int y;
};

int main()
{
    Point p1, p2, p3;
    
    std::cout << "Enter p1's coordinates: ";
    std::cin >> p1.x >> p1.y;
    std::cout << "Enter p2's coordinates: ";
    std::cin >> p2.x >> p2.y;

    p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;

    std::cout << "Coordinates of the point p1+p2 are: " << p3.x << ", " << p3.y << '\n';
}

