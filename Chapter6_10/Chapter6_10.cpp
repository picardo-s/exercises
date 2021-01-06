#include <iostream>

unsigned const char GRADE = '\xF8';

class Angle
{
private:
    int m_degree;
    float m_minute;
    char m_direction;
    void check(const int deg, const float min, const char dir)
    {
        if (deg < 0 || min < 0 || deg > 180 || min > 60 || (deg == 180 && min != 0))
            throw std::runtime_error("Angle cannot be less than 0 or more than 180 "
            "or minutes cannot be less than 0 or more than 60");
        if (dir != 'N' && dir != 'S' && dir != 'W' && dir != 'E')
            throw std::runtime_error("Direction must be N, S, W, or E");
    }
public:
    Angle() :
        m_degree(0), m_minute(0), m_direction('-')
    {}
    Angle(int deg, float min, char dir) :
        m_degree(deg), m_minute(min), m_direction(dir)
    {
        check(deg, min, dir);
    }

    void set()
    {
        bool flag = true;
        int deg = 0;
        float min = 0;
        char dir = 'N';
        while (1)
        {
            std::cout << "\nDegree: ";
            std::cin >> deg;

            if (std::cin.fail())
            {
                std::cout << "Wrong input\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }
            break;
        }

        if (deg >= 180)
            flag = false;

        while (flag)
        {
            std::cout << "Minutes: ";
            std::cin >> min;

            if (std::cin.fail())
            {
                std::cout << "Wrong input\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }
            break;
        }

        std::cout << "Direction: ";
        std::cin >> dir;
        std::cin.ignore(1000, '\n');
        
        check(deg, min, dir);
        m_degree = deg;
        m_minute = min;
        m_direction = dir;
        std::cout << '\n';
    }

    void display() const
    {
        std::cout << m_degree << GRADE << m_minute << "\' " << m_direction << '\n';
    }

    int getDegree() const
    {
        return m_degree;
    }

    float getMinute() const
    {
        return m_minute;
    }

    char getDirection() const
    {
        return m_direction;
    }
};

class Ship
{
private:
    int m_shipNumber;
    static int m_shipCount;
    Angle latitude;
    Angle longitude;
public:
    Ship() : m_shipNumber(++m_shipCount)
    {}

    void setData()
    {
        while (1)
        {
            std::cout << "Enter the latitude of the ship (0 - 90, S or N): ";
            latitude.set();
            if (latitude.getDegree() > 90 || (latitude.getDegree() == 90 && latitude.getMinute() != 0))
            {
                std::cout << "Latitude cannot be more than 90\n";
                continue;
            }
            if (latitude.getDirection() != 'S' && latitude.getDirection() != 'N')
            {
                std::cout << "Latitude is expected to be \'S\' or \'N\'\n";
                continue;
            }
            break;
        }
        while (1)
        {
            std::cout << "Enter the longitude of the ship (0 - 180, W or E): ";
            longitude.set();
            if (longitude.getDirection() != 'W' && longitude.getDirection() != 'E')
            {
                std::cout << "Longitude is expected to be \'W\' or \'E\'\n";
                continue;
            }
            break;
        }
        std::cout << '\n';
    }
    void displayData() const
    {
        std::cout << "The ship\'s number: " << m_shipNumber << '\n';
        std::cout << "Latitude: ";
        latitude.display();
        std::cout << "Longitude: ";
        longitude.display();
        std::cout << '\n';
    }
};

int Ship::m_shipCount = 0;

int main()
{
    char manip = 'a';
    do
    {
        try
        {
            Ship ship;  //in order to show how m_shipCount works
            ship.setData();
            ship.displayData();
        }
        catch (std::exception const& e)
        {
            std::cout << "Exception: " << e.what() << '\n';
            continue;
        }
        std::cout << "Continue?(y/n): ";
        std::cin >> manip;
        std::cin.ignore(1000, '\n');
    } while (manip != 'n');

}


//Angle(int deg, float min, char dir) :
//    m_degree(deg), m_minute(min), m_direction(dir)
//{
//    bool flag = false;
//    if (deg < 0 || min < 0 || deg > 180 || min > 60 || (deg == 180 && min != 0))
//    {
//        flag = true;
//        try
//        {
//            throw std::runtime_error("Angle cannot be less than 0 or more than 180");
//        }
//        catch (std::exception const& e)
//        {
//            std::cout << "Exception: " << e.what() << '\n';
//            m_degree = deg < 0 ? 0 : deg;
//            m_degree = deg > 180 ? 180 : m_degree;
//            m_minute = min < 0 ? 0 : min;
//            m_minute = min > 60 ? 60 : m_minute;
//            m_minute = m_degree == 180 ? 0 : m_minute;
//        }
//    }
//    if (dir != 'N' && dir != 'S' && dir != 'W' && dir != 'E')
//    {
//        flag = true;
//        try
//        {
//            throw std::runtime_error("Direction must be N, S, W, or E");
//        }
//        catch (std::exception const& e)
//        {
//            std::cout << "Exception: " << e.what() << '\n';
//            m_direction = 'N';
//        }
//    }
//    if (flag)
//    {
//        std::cout << "Now the angle = ";
//        this->display();
//    }
//}

//class Angle
//{
//private:
//    int m_degree;
//    float m_minute;
//    char m_direction;
//public:
//    Angle() :
//        m_degree(0), m_minute(0), m_direction('-')
//    {}
//    Angle(int deg, float min, char dir) :
//        m_degree(deg), m_minute(min), m_direction(dir)
//    {
//        if (deg < 0 || min < 0 || deg > 180 || min > 60 || (deg == 180 && min != 0))
//            throw std::runtime_error("Angle cannot be less than 0 or more than 180");
//        if (dir != 'N' && dir != 'S' && dir != 'W' && dir != 'E')
//            throw std::runtime_error("Direction must be N, S, W, or E");
//    }
//
//    void set()
//    {
//        bool flag = true;
//        int deg = 0;
//        float min = 0;
//        char dir = 'N';
//        while (1)
//        {
//            std::cout << "\nDegree: ";
//            std::cin >> deg;
//
//            if (std::cin.fail())
//            {
//                std::cout << "Wrong input\n";
//                std::cin.clear();
//                std::cin.ignore(1000, '\n');
//                continue;
//            }
//            break;
//        }
//
//        if (deg >= 180)
//            flag = false;
//
//        while (flag)
//        {
//            std::cout << "Minutes: ";
//            std::cin >> min;
//
//            if (std::cin.fail())
//            {
//                std::cout << "Wrong input\n";
//                std::cin.clear();
//                std::cin.ignore(1000, '\n');
//                continue;
//            }
//            break;
//        }
//
//        std::cout << "Direction: ";
//        std::cin >> dir;
//        std::cin.ignore(1000, '\n');
//
//        *this = Angle(deg, min, dir);
//        std::cout << '\n';
//    }