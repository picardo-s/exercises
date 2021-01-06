#include <iostream>

unsigned constexpr char GRADE = '\xF8';

class Angle
{
private:
    int m_degree;
    float m_minute;
    char m_direction;
public:
    Angle(int deg, float min, char dir) :
        m_degree(deg), m_minute(min), m_direction(dir)
    {}

    void set()
    {
        std::cout << "\nEnter coordinates.\nDegrees: ";
        std::cin >> m_degree;
        std::cout << "Minutes: ";
        std::cin >> m_minute;
        std::cout << "Direction: ";
        std::cin >> m_direction;
    }

    void display() const
    {
        std::cout << "Your coordinates are " << m_degree << GRADE << m_minute << "\' " << m_direction << '\n';
    }
};


int main()
{
    Angle ang(151, 14.4f, 'E');
    ang.display();

    char manip = 'a';
    while (manip != 'n')
    {
        ang.set();
        ang.display();
        std::cout << "Continue(y/n)?: ";
        std::cin >> manip;
    }
}
