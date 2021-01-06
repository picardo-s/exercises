#include <iostream>
#include <iomanip>

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

bool get_time(Time& time)
{
    char timeDiv;
    std::cin >> time.hours >> timeDiv >> time.minutes >> timeDiv >> time.seconds;
    if (((time.hours > 12) || (time.hours < 0)) || ((time.minutes > 59) || (time.minutes < 0)) || ((time.seconds > 59) || (time.seconds < 0)))
    {
        std::cout << "Wrong input!\n";
        return 1;
    }
    return 0;
}

int main()
{
    Time time1, time2, sumTime;

    do
    {
        std::cout << "Enter the first time (12:59:59): ";
    } while (get_time(time1));

    do
    {
        std::cout << "Enter the second time (12:59:59): ";
    } while (get_time(time2));


    long totalSec1 = time1.hours * 3600 + time1.minutes * 60 + time1.seconds;
    long totalSec2 = time2.hours * 3600 + time2.minutes * 60 + time2.seconds;
    long totalSumSec = totalSec1 + totalSec2;

    sumTime.hours = totalSumSec / 3600;
    totalSumSec %= 3600;
    sumTime.minutes = totalSumSec / 60;
    totalSumSec %= 60;
    sumTime.seconds = totalSumSec;

    if (sumTime.hours > 12)
        sumTime.hours %= 12;

    std::cout << std::setw(2) << std::setfill('0') << sumTime.hours << ":" << std::setw(2) 
        << sumTime.minutes << ":" << std::setw(2) << sumTime.seconds;
}
