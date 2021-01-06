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
    {
        this->correct();
    }
    void display() const
    {
        std::cout << std::setfill('0') << std::setw(2) << m_hours << ":"
            << std::setw(2) << m_minutes << ":" << std::setw(2) << m_seconds;
    }

    void correct();
    Time operator+(const Time& t);
    Time operator-(const Time& t);
    Time operator*(float num);
    Time operator++();
    Time operator--();
    Time operator++(int);
    Time operator--(int);
};

void Time::correct()
{
    if (m_seconds >= 60)
    {
        m_seconds -= 60;
        ++m_minutes;
    }
    else if (m_seconds < 0)
    {
        m_seconds += 60;
        --m_minutes;
    }

    if (m_minutes >= 60)
    {
        m_minutes -= 60;
        ++m_hours;
    }
    else if (m_minutes < 0)
    {
        m_minutes += 60;
        --m_hours;
    }

    if (m_hours >= 12)
        m_hours -= 12;
    else if (m_hours < 0)
        m_hours += 12;
}

Time Time::operator+(const Time& t)
{
    Time temp(0, 0, 0);
    temp.m_seconds = m_seconds + t.m_seconds;
    temp.m_minutes = m_minutes + t.m_minutes;
    temp.m_hours = m_hours + t.m_hours;
    temp.correct();
    return temp;
}

Time Time::operator-(const Time& t)
{
    Time temp(0, 0, 0);
    temp.m_seconds = m_seconds - t.m_seconds;
    temp.m_minutes = m_minutes - t.m_minutes;
    temp.m_hours = m_hours - t.m_hours;
    temp.correct();
    return temp;
}

Time Time::operator*(float num)
{
    float timeSec = m_hours * 3600 + m_minutes * 60 + m_seconds;
    timeSec *= num;
    int hours = static_cast<int>(timeSec) / 3600;
    timeSec -= hours * 3600;
    int minutes = static_cast<int>(timeSec) / 60;
    timeSec -= minutes * 60;
    int seconds = static_cast<int>(timeSec);
    return Time(hours, minutes, seconds);
}

Time Time::operator++()
{
    Time temp(++m_hours, m_minutes, m_seconds);
    this->correct();
    return temp;
}

Time Time::operator--()
{
    Time temp(--m_hours, m_minutes, m_seconds);
    this->correct();
    return temp;
}

Time Time::operator++(int)
{
    Time temp(m_hours++, m_minutes, m_seconds);
    this->correct();
    return temp;
}

Time Time::operator--(int)
{
    Time temp(m_hours--, m_minutes, m_seconds);
    this->correct();
    return temp;
}


int main()
{
    Time t1(2, 10, 15), t2(4, 20, 31), t3;
    t1 = t1 * 2;
    t1.display();
    std::cout << '\n';
    t3 = t1 - t2;
    t3.display();
}
