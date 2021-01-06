#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    constexpr int cm_m = 100;
    constexpr double in_m = 39.37;
    constexpr double ft_m = 3.3;
    double num;
    std::string str;
    std::vector<double> d_vect;
    while (std::cin >> num >> str)
    {
        std::cout << "You entered " << num  << str << '\n';

        if (str == "cm")
            num /= cm_m;
        else if (str == "in")
            num /= in_m;
        else if (str == "ft")
            num /= ft_m;
        else if (str == "m")
        { }
        else
        {
            std::cout << "Wrong type\n";
            continue;
        }
        d_vect.push_back(num);
    }
    std::sort(d_vect.begin(), d_vect.end());
    for (double n : d_vect)
        std::cout << n << " ";
}
