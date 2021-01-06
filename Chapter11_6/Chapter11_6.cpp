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
    friend bMoney round(const bMoney& mon);
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
    return m_money / mon.m_money;
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

bMoney round(const bMoney& mon)
{
    long wholeNum = static_cast<long>(mon.m_money);
    double difNum = mon.m_money - wholeNum;
    return (difNum < 0.5) ? bMoney(mon.m_money - difNum) : bMoney(mon.m_money - difNum + 1);
}

int main()
{
    bMoney m1(0.49), m2(1.5), m3(2.51);
    bMoney m4 = round(m1);
    std::cout << "m1 = " << m1.getmoney() << " after rounding is " << m4.getmoney();

    m4 = round(m2);
    std::cout << "\nm2 = " << m2.getmoney() << " after rounding is " << m4.getmoney();

    m4 = round(m3);
    std::cout << "\nm3 = " << m3.getmoney() << " after rounding is " << m4.getmoney();
}