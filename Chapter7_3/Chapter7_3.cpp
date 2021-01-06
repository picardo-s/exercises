#include <iostream>

class Distance
{
private:
    int m_feet;
    float m_inches;
public:
    Distance(): m_feet(0), m_inches(0)
    {}

    void getdist()
    {
        std::cout << "\nEnter an amount of feet: ";
        std::cin >> m_feet;
        std::cout << "Enter an amount of inches: ";
        std::cin >> m_inches;
    }

    void showdist() const
    {
        std::cout << m_feet << "\'-" << m_inches << '\"';
    }

    void add_dist(const Distance& dist)
    {
        m_inches += dist.m_inches;
        if (m_inches >= 12)
        {
            m_inches -= 12;
            ++m_feet;
        }
        m_feet += dist.m_feet;
    }

    void div_dist(const Distance& dist, int divisor)
    {
        float floatDist = dist.m_feet + dist.m_inches / 12;
        floatDist /= divisor;
        m_feet = int(floatDist);
        m_inches = (floatDist - m_feet) * 12;
    }
};

int main()
{
    const int MAX = 100;
    Distance distArr[100];
    int count = 0;
    char manip = 'a';

    do
    {
        std::cout << "Distance #" << count + 1;
        distArr[count++].getdist();
        std::cout << "Continue?(y/n): ";
        std::cin >> manip;
        std::cout << '\n';
    } while ((manip != 'n') && (count < MAX));

    std::cout << '\n';

    Distance sumDist;
    for (int i = 0; i < count; i++)
        sumDist.add_dist(distArr[i]);

    sumDist.div_dist(sumDist, count);
    std::cout << "The average Distance is ";
    sumDist.showdist();
}
