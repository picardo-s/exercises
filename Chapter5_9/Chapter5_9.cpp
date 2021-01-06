#include <iostream>
#include <iomanip>

struct Time
{
    int hours;
    int minutes;
    int seconds;

    friend std::ostream& operator<<(std::ostream& out, const Time& t)
    {
        out << std::setfill('0') << std::setw(2) << t.hours << ":" << std::setw(2)
            << t.minutes << ":" << std::setw(2) << t.seconds;
        return out;
    }

    //void swap(Time& t2_out)
    //{
    //    std::cout << "\nSwapping...\n";
    //    std::swap(this->hours, t2_out.hours);
    //    std::swap(this->minutes, t2_out.minutes);
    //    std::swap(this->seconds, t2_out.seconds);
    //}
};

void swap(Time& t1_out, Time& t2_out);

int main()
{
    Time time1 = { 11, 15, 45 }, time2 = { 5, 25, 10 };

    std::cout << "Time1 = " << time1 << ", time2 = " << time2;

    swap(time1, time2);
    //time1.swap(time2);
    std::cout << "Now time1 = " << time1 << ", time2 = " << time2;
}

void swap(Time& t1_out, Time& t2_out)
{
    std::cout << "\nSwapping...\n";
    std::swap(t1_out.hours, t2_out.hours);
    std::swap(t1_out.minutes, t2_out.minutes);
    std::swap(t1_out.seconds, t2_out.seconds);
}