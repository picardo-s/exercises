#include <iostream>
#include <iomanip>

class Money
{
private:
   double m_amount;
   static const int STR_MAX = 23;
public:
    double mstold(char str[])
    {
        char numStr[STR_MAX];
        int strLength = strlen(str) + 1;
        for (int i = 0, j = 0; i < strLength ; i++)
        {
            if ((str[i] == '$' || str[i] == ',') || str[i] == '-')
                continue;
            else
                numStr[j++] = str[i];
        }
        return atof(numStr);
    }
};

int main()
{
    Money m;
    const int MAX = 30;
    char money[MAX];

    std::cout << "Enter an amount of dollars: ";
    std::cin >> std::setw(MAX) >> money; //std::cin.get(money, MAX);
    std::cout << "You entered " << std::setiosflags(std::ios::fixed) << std::setprecision(2) << m.mstold(money);
}
