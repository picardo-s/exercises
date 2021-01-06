#include <iostream>

struct Date
{
    int day;
    int month;
    int year;
};

int main()
{
    char slash;
    Date date;
    std::cout << "Enter a date (day/month/year).\n";
    std::cin >> date.day >> slash >> date.month >> slash >> date.year;
    std::cout << "You entered: " << date.day << slash << date.month << slash << date.year << '\n';
}

