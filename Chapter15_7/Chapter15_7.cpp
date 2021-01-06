#include <iostream>
#include <list>
#include <numeric>
#include <iomanip>

constexpr int MAX_HOUR = 23;
constexpr int MAX_MINUTE = 59;

class AirTime
{
private:
    int hours;
    int minutes;
    void check_time(int h, int m)
    {
        if (h < 0 || h > MAX_HOUR)
            throw std::runtime_error("Hours either more than 23 or less than 0");
        if (m < 0 || m > MAX_MINUTE)
            throw std::runtime_error("Minutes either more than 59 or less than 0");
    }
public:
    AirTime() : hours(0), minutes(0)
    {}

    AirTime(int h, int m) : hours(h), minutes(m)
    {
        check_time(h, m);
    }

    void display_time() const
    {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << minutes;
    }

    void get_time()
    {
        char time_div;
        std::cout << "Enter time(hh:mm): ";
        while (1)
        {
            std::cin >> hours >> time_div >> minutes;          
            if (std::cin.fail() || time_div != ':')
            {
                std::cout << "Wrong input.\nAgain: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }
            std::cin.ignore(1000, '\n');
            check_time(hours, minutes);
            break;
        }
    }

    AirTime operator+(const AirTime& right) const
    {
        int temp_h = hours + right.hours;
        int temp_m = minutes + right.minutes;
        if (temp_m > MAX_MINUTE)
        {
            temp_h++;
            temp_m -= (MAX_MINUTE + 1);
        }
        if (temp_h > MAX_HOUR)
            temp_h -= (MAX_HOUR + 1);
        return AirTime(temp_h, temp_m);
    }

    bool operator==(const AirTime& at2) const
    {
        return (hours == at2.hours) && (minutes == at2.minutes);
    }

    bool operator<(const AirTime& at2) const
    {
        return (hours < at2.hours) || (hours == at2.hours && minutes < at2.minutes);
    }

    bool operator!=(const AirTime& at2) const
    {
        return !(*this == at2);
    }

    bool operator>(const AirTime& at2) const
    {
        return !(*this < at2) && !(*this == at2);
    }
};

int main()
{
    char manip;
    std::list<AirTime> air_list;

    try
    {
        AirTime temp, sum;
        do
        {
            temp.get_time();
            air_list.push_back(temp);
            std::cout << "Continue?(y/n): ";
            std::cin >> manip;
            std::cin.ignore(1000, '\n');
        } while (manip != 'n');

        sum = std::accumulate(air_list.begin(), air_list.end(), AirTime(0, 0));

        std::cout << "Sum = ";
        sum.display_time();
    }
    catch (std::exception e)
    {
        std::cout << e.what();
    }
}
