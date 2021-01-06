#include <iostream>
#include <iomanip>

class Time
{
private:
    int m_hours;
    int m_minutes;
    int m_seconds;
public:
    Time() :m_hours(0), m_minutes(0), m_seconds(0)
    {}
    Time(int hour, int min, int sec)
        :m_hours(hour), m_minutes(min), m_seconds(sec)
    {}
    void display() const
    {
        std::cout << std::setfill('0') << std::setw(2) << m_hours << ":"
            << std::setw(2) << m_minutes << ":" << std::setw(2) << m_seconds;
    }
    
    Time operator+(const Time& t);
};

Time Time::operator+(const Time& t)
{
    Time temp(0, 0, 0);

    temp.m_seconds = m_seconds + t.m_seconds;
    if (temp.m_seconds >= 60)
    {
        temp.m_seconds -= 60;
        ++temp.m_minutes;
    }
    temp.m_minutes = m_minutes + t.m_minutes;
    if (temp.m_minutes >= 60)
    {
        temp.m_minutes -= 60;
        ++temp.m_hours;
    }
    temp.m_hours = m_hours + t.m_hours;
    if (temp.m_hours >= 12)
        temp.m_hours -= 12;

    return temp;
}

int main()
{
    Time t1(10, 35, 40), t2(4, 30, 35);
    Time t3 = t1 + t2;
    t3.display();
}