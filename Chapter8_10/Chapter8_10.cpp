#include <iostream>
#include <cmath>
#include <iomanip>

constexpr double PI = 3.14159;

class Polar
{
private:
    double m_radius;
    double m_angle;
public:
    Polar(double r = 0, double an = 0.0) : m_radius(r), m_angle(an)
    {
        if (an < 0 || an >(2 * PI))
            throw std::runtime_error("Wrong value");
    }

    void display();
    Polar operator+(const Polar& pol);
};

void Polar::display()
{
    std::cout << std::setprecision(5) << "(" << m_radius << ";" << std::setprecision(3) << m_angle << ")\n";
}

Polar Polar::operator+(const Polar& pol)
{
    double a_x = m_radius * cos(m_angle);
    double a_y = m_radius * sin(m_angle);
    double b_x = pol.m_radius * cos(pol.m_angle);
    double b_y = pol.m_radius * sin(pol.m_angle);
    double r_x = a_x + b_x, r_y = a_y + b_y;
    double r = sqrt((r_x * r_x) + (r_y * r_y));
    double an = acos(r_x / r);
    return Polar(r, an);
}


int main()
{
    try
    {
        Polar p1(-5, PI / 4), p2(7, PI / 2);
        Polar p3 = p1 + p2;
        p3.display();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what();
    }
}
