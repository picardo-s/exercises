#include <iostream>
#include <string>
#include <strstream>
#include <iomanip>

class bMoney
{
private:
    double m_money;
    static const int NUM_MAX = 23;
    static const int STR_MAX = 30; 
public:
    bMoney()
    {}
    explicit bMoney(char s[])
    {
        putmoney(s);
    }
    explicit bMoney(double m)
    {
        if (m > 99999999999999990)
        {
            std::cout << "\nOverflow!";
            std::exit(1);
        }
        m_money = m;
    }

    bMoney operator+(const bMoney& mon);
    bMoney operator-(const bMoney& mon);
    bMoney operator*(const double num);
    double operator/(const bMoney& mon);
    bMoney operator/(const double num);
    std::string getmoney();
    void putmoney(char str[]);
};

bMoney bMoney::operator+(const bMoney& mon)
{
    if ((m_money + mon.m_money) > 99999999999999990)
    {
        std::cout << "\nOverflow!";
        std::exit(1);
    }
    return bMoney(m_money + mon.m_money);
}

bMoney bMoney::operator-(const bMoney& mon)
{
    if ((m_money - mon.m_money) < 0)
    {
        std::cout << "\nThe result of this operaton cannot be less than 0";
        std::exit(1);
    }
    return bMoney(m_money - mon.m_money);
}

bMoney bMoney::operator*(const double num)
{
    if ((m_money * num) > 99999999999999990)
    {
        std::cout << "\nOverflow!";
        std::exit(1);
    }
    return bMoney(m_money * num);
}

double bMoney::operator/(const bMoney& mon)
{
    if (mon.m_money == 0)
    {
        std::cout << "\nDivision by 0";
        std::exit(1);
    }
    return m_money/mon.m_money;
}

bMoney bMoney::operator/(const double num)
{
    if (num == 0)
    {
        std::cout << "\nDivision by 0";
        std::exit(1);
    }
    return bMoney(m_money / num);
}

void bMoney::putmoney(char str[])
{
    if (strlen(str) > STR_MAX)
    {
        std::cout << "\nThe number is too big!";
        return;
    }
    char numStr[NUM_MAX];
    int strLength = strlen(str) + 1;
    for (int i = 0, j = 0; i < strLength; i++)
    {
        if ((str[i] == '$' || str[i] == ',') || str[i] == '-')
            continue;
        else
            numStr[j++] = str[i];
    }
    m_money = atof(numStr);
}

std::string bMoney::getmoney()
{
    std::ostrstream strObj;
    strObj.flags(std::ostream::fixed);
    strObj.precision(2);
    strObj << m_money << std::ends;
    std::string ustring = strObj.str();

    std::string moneyStr("$");
    for (int i = 1; i <= ustring.size(); i++)
    {
        moneyStr += ustring.at(i - 1);
        if (((ustring.size() - i) % 3) == 0 && ((ustring.size() - i) > 3))
            moneyStr += ",";
    }
    moneyStr += '\0';
    return moneyStr;
}

int main()
{
    bMoney m1, m2, m3;
    double dNum;
    const int MAX = 30;
    char money[MAX], manip;

    do
    {
        std::cout << "Enter the first amount of dollars (bM1): ";
        std::cin >> std::setw(MAX) >> money;
        m1.putmoney(money);

        std::cout << "Enter the second amount of dollars (bM2): ";
        std::cin >> std::setw(MAX) >> money;
        m2.putmoney(money);

        std::cout << "Enter a float number (num): ";
        std::cin >> dNum;

        m3 = m1 + m2;
        std::cout << "\nbM1 + bM2 = " << m3.getmoney();

        m3 = m1 - m2;
        std::cout << "\nbM1 - bM2 = " << m3.getmoney();

        m3 = m1 * dNum;
        std::cout << "\nbM1 * num = " << m3.getmoney();

        m3 = m1 / dNum;
        std::cout << "\nbM1 / num = " << m3.getmoney();

        dNum = m1 / m2;
        std::cout << "\nbM1 / bM2 = " << dNum;
        std::cout << "\nContinue?(y/n): ";
        std::cin >> manip;
        std::cout << '\n';

    } while (manip != 'n');
}
