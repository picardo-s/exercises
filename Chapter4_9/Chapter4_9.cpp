#include <iostream>

struct Time
{
    int hours;
    int minutes;
    int seconds;
};

int main()
{
    Time time;
    
    std::cout << "Enter time (hours, minutes, seconds): ";
    std::cin >> time.hours >> time.minutes >> time.seconds;

    long totalsec = time.hours * 3600 + time.minutes * 60 + time.seconds;

    std::cout << "The total amount of seconds is " << totalsec;
}
