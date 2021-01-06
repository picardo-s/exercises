#include <iostream>
#include <iomanip>

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

long time_to_secs(Time time);
Time secs_to_time(long sec);

int main()
{
    char timeDiv;
    Time time1, time2, sumTime;

    std::cout << "Enter the first time (12:59:59): ";
    std::cin >> time1.hours >> timeDiv >> time1.minutes >> timeDiv >> time1.seconds;
    std::cout << "Enter the second time (12:59:59): ";
    std::cin >> time2.hours >> timeDiv >> time2.minutes >> timeDiv >> time2.seconds;

    long totalSumSec = time_to_secs(time1) + time_to_secs(time2);
    sumTime = secs_to_time(totalSumSec);
    std::cout << "The total time is: " << std::setw(2) << std::setfill('0') << sumTime.hours << timeDiv << std::setw(2)
        << sumTime.minutes << timeDiv << std::setw(2) << sumTime.seconds;
}

long time_to_secs(Time time)
{
    return (time.hours * 3600 + time.minutes * 60 + time.seconds);
}

Time secs_to_time(long sec)
{
    Time tempTime;
    tempTime.hours = sec / 3600;
    sec %= 3600;
    tempTime.minutes = sec / 60;
    sec %= 60;
    tempTime.seconds = sec;

    if (tempTime.hours > 12)
        tempTime.hours %= 12;

    return tempTime;
}