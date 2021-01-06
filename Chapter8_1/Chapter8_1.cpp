#include <iostream>

class Distance
{
private:
    int m_feet;
    float m_inches;
public:
    Distance():m_feet(0), m_inches(0)
    {}
    Distance(int ft, float inch):m_feet(ft), m_inches(inch)
    {}
    void getdist()
    {
        std::cout << "Enter an amount of feet: ";
        std::cin >> m_feet;
        std::cout << "Enter an amount of inches: ";
        std::cin >> m_inches;
    }
    void showdist()
    {
        std::cout << m_feet << "\'-" << m_inches << "\"";
    }
    Distance operator+(const Distance& dist);
    Distance operator-(const Distance& dist);
};

Distance Distance::operator+(const Distance& dist)
{
    int f = m_feet + dist.m_feet;
    float i = m_inches + dist.m_inches;
    if (i >= 12)
    {
        i -= 12;
        ++f;
    }
    return Distance(f, i);
}

Distance Distance::operator-(const Distance& dist)
{
    int f = m_feet - dist.m_feet;
    float i = m_inches - dist.m_inches;
    if (i < 0)
    {
        i = m_inches - dist.m_inches + 12;
        --f;
    }
    if (f < 0)
    {
        std::cout << "Distance cannot be negative!";
        std::exit(1);
    }
    return Distance(f, i);
}



int main()
{
    Distance d1(5, 7.15), d2, d3;
    d2.getdist();
    d3 = d1 - d2;
    d3.showdist();
}
