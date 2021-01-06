#include <iostream>
#include <strstream>
#include <string>
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
        for (int i = 0, j = 0; i < strLength; i++)
        {
            if ((str[i] == '$' || str[i] == ',') || str[i] == '-')
                continue;
            else
                numStr[j++] = str[i];
        }
        m_amount = atof(numStr);
        return atof(numStr);
    }

    std::string ldtoms(double number)
    {
        if (number > 9999999999999990.00)
        {
            std::cout << "The number is too big!";
            std::exit(1);
        }
        std::ostrstream strObj;
        strObj.flags(std::ostream::fixed);
        strObj.precision(2);
        strObj << number << std::ends;
        std::string ustring = strObj.str();

        std::string moneyStr("$");
        for (int i = 1; i <= ustring.size(); i++) //I decided to apply a different approach here, avoiding operations with 0's
        {        
            moneyStr += ustring.at(i - 1);
            if (((ustring.size() - i) % 3) == 0 && ((ustring.size() - i) > 3))
                moneyStr += ",";
        }
        moneyStr += '\0'; //I am not sure that it should  be here
        return moneyStr;
    }
};

int main()
{
    Money m;

    int i = 0;
    while (i++ < 3)
    {
        std::cout << "\nEnter a float number: ";
        double num;
        std::cin >> num;
        std::cout << "This number is: " << m.ldtoms(num) << '\n';
    }
}