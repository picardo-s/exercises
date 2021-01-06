#include <iostream>

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

long hms_to_secs(int hour, int min, int sec);

int main()
{
    Time time;
    long totalSec;

    do
    {
        std::cout << "Enter time (12:59:59).\nEnter hours (-1 to exit the program): ";
        std::cin >> time.hours;
        if (time.hours == -1)
            break;
        std::cout << "Enter minutes: ";
        std::cin >> time.minutes;
        std::cout << "Enter seconds: ";
        std::cin >> time.seconds;

        totalSec = hms_to_secs(time.hours, time.minutes, time.seconds);
        std::cout << "The total amount of seconds is: " << totalSec << '\n';
    } while (1);
}

long hms_to_secs(int hour, int min, int sec)
{
    return (hour * 3600 + min * 60 + sec);
}
