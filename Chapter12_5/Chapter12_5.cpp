#include <iostream>
#include <iomanip>

class Time
{
private:
    int m_hours;
    int m_minutes;
    int m_seconds;

    bool isOK(std::istream& in)
    {
        if (in.good())
        {
            std::cin.ignore(100, '\n');
            return true;
        }
        std::cin.clear();
        std::cin.ignore(100, '\n');
        return false;
    }

public:
    Time() :m_hours(0), m_minutes(0), m_seconds(0)
    {}
    void get_time()
    {
        while (1)
        {
            std::cout << "Enter hours: ";
            std::cin.unsetf(std::ios::skipws);
            std::cin >> m_hours;
            if (isOK(std::cin) && m_hours >= 0 && m_hours <= 23)
                break;
            std::cout << "Wrong hours!\n";
        }
        while (1)
        {
            std::cout << "Enter minutes: ";
            std::cin >> m_minutes;
            if (isOK(std::cin) && m_minutes >= 0 && m_minutes <= 59)
                break;
            std::cout << "Wrong minutes!\n";
        }
        while (1)
        {
            std::cout << "Enter seconds: ";
            std::cin >> m_seconds;
            if (isOK(std::cin) && m_seconds >= 0 && m_seconds <= 59)
                break;
            std::cout << "Wrong seconds!\n";
        }
    }
    void put_time()
    {
        std::cout << "\nTime = " << std::setfill('0') << std::setw(2) << m_hours
            << ":" << std::setw(2) << m_minutes << ":" << std::setw(2) << m_seconds;
    }
};

int main()
{
    Time t;
    char manip;

    do
    {
        t.get_time();
        t.put_time();
        std::cout << "\nContinue?(y/n): ";
        std::cin >> manip;
        std::cin.ignore(100, '\n');
        std::cout << std::endl;
    } while (manip == 'y');
}
