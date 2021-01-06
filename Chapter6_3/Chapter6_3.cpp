#include <iostream>
#include <iomanip>

class Time
{
private:
    int m_hours;
    int m_minutes;
    int m_seconds;
public:
    Time():m_hours(0), m_minutes(0), m_seconds(0)
    {}
    Time(int hour, int min, int sec)
        :m_hours(hour), m_minutes(min), m_seconds(sec)
    {}
    void display() const
    {
        std::cout << std::setfill('0') << std::setw(2) << m_hours << ":"
            << std::setw(2) << m_minutes << ":" << std::setw(2) << m_seconds;
    }
    void add(const Time& t1, const Time& t2)
    {
        m_seconds = t1.m_seconds + t2.m_seconds;
        if (m_seconds >= 60)
        {
            m_seconds -= 60;
            ++m_minutes;
        }
        m_minutes += t1.m_minutes + t2.m_minutes;
        if (m_minutes >= 60)
        {
            m_minutes -= 60;
            ++m_hours;
        }
        m_hours += t1.m_hours + t2.m_hours;
        if (m_hours >= 12)
            m_hours -= 12;
    }

};

int main()
{
    const Time time1(5, 52, 30), time2(7, 10, 41);
    Time time3;
    time3.add(time1, time2);
    time3.display();
}
