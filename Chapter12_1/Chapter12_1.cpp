#include <iostream>
#include <fstream>

class Distance
{
private:
    int m_feet;
    float m_inches;
public:
    Distance() : m_feet(0), m_inches(0)
    {}
    Distance(int ft, float inch) : m_feet(ft), m_inches(inch)
    {}
    void getDist()
    {
        std::cout << "\nEnter feet: ";
        std::cin >> m_feet;
        std::cout << "Enter inches: ";
        std::cin >> m_inches;
    }
    void showDist()
    {
        std::cout << m_feet << "\'-" << m_inches << "\"";
    }
};

int main()
{
    char manip;
    Distance d1;
    std::fstream file;

    file.open("S:/perfect_circle/Chapter12_1/DIST.DAT", std::ios::app | std::ios::in | std::ios::out | std::ios::binary);

    do
    {
        std::cout << "\nEnter the distance: ";
        d1.getDist();
        file.write((char*)(&d1), sizeof(d1));
        std::cout << "Continue?(y/n): ";
        std::cin >> manip;
    } while (manip == 'y');

    file.seekg(0);
    file.read((char*)(&d1), sizeof(d1));
    
    while (file)
    {
        std::cout << "\nDistance: ";
        d1.showDist();
        file.read((char*)(&d1), sizeof(d1));
    }
    std::cout << std::endl;
}
