#include <iostream>

class Distance
{
private:
    int m_feet;
    float m_inches;
public:
    Distance() : m_feet(0), m_inches(0)
    {}
    Distance(float flt)
    {
        m_feet = static_cast<int>(flt);
        m_inches = 12 * (flt - m_feet);
    }
    Distance(int ft, float inch) : m_feet(ft), m_inches(inch)
    {}
    void showdist()
    {
        std::cout << m_feet << "\'-" << m_inches << "\"";
    }
    friend Distance operator*(Distance dist1, Distance dist2);
};

Distance operator*(Distance dist1, Distance dist2)
{
    float flt_dist1 = dist1.m_feet + dist1.m_inches / 12;
    float flt_dist2 = dist2.m_feet + dist2.m_inches / 12;
    return Distance(flt_dist1 * flt_dist2);
}

int main()
{
    Distance d1(5, 2.5), d2(3, 1.5);
    Distance d3 = d1 * d2;
    std::cout << "d3 = d1 * d2 = ";
    d3.showdist();

    Distance d4 = d1 * 4.8;
    std::cout << "\nd4 = d1 * 4.8 = ";
    d4.showdist();

    Distance d5 = 1.75 * d2;
    std::cout << "\nd5 = 1.75 * d2 = ";
    d5.showdist();

    Distance d6 = 2.5 * 5;
    std::cout << "\nd6 = 2.5 * 5 = ";
    d6.showdist();
}
