#include <iostream>
#include <iomanip>

class Date
{
private:
    int m_month;
    int m_day;
    int m_year;
public:
    Date() : m_month(0), m_day(0), m_year(0)
    {}

    void getDate(int month, int day, int year)
    {
        m_month = month;
        m_day = day;
        m_year = year;
    }

    void showDate() const
    {
        std::cout << std::setfill('0') << "Date: " << std::setw(2) << m_month << "/"
            << std::setw(2) << m_day << "/" << std::setw(2) << m_year;
    }
};

int main()
{
    Date date;
    date.getDate(5, 23, 7);
    date.showDate();
}
