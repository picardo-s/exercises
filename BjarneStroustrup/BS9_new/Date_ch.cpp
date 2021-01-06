#include "Date_ch.h"
Date::Date(int yy, Month mm, int dd) : y{ yy }, m{ mm }, d{ dd }
{
    if (!is_date(yy, mm, dd)) throw std::runtime_error("Invalid date");
}

const Date& default_date()
{
    static Date dd(2001, Month::jan, 1);
    return dd;
}

Date::Date()
    : y{ default_date().year() },
    m{default_date().month()},
    d(default_date().day())
{}

bool leapyear(int y)
{
    return (y % 4 == 0) ? true : false;
}

bool is_date(int y, Month m, int d)
{
    if (d < 0) return false;
    if (m < Month::jan || Month::dec < m) return false;
    int days_in_month = 31;
    switch (m)
    {
    case Month::feb:
        days_in_month = (leapyear(y)) ? 29 : 28;
        break;
    case Month::apr: case Month::jun:
    case Month::sep: case Month::nov:
        days_in_month = 30;
        break;
    }
    if (days_in_month < d) return false;
    return true;
}

void Date::add_day(int n)
{
    std::cout << "Undone function";
}
void Date::add_month(int n)
{
    std::cout << "Undone function";
}
void Date::add_year(int n)
{
    std::cout << "Undone function";
}