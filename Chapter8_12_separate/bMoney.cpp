#include "bMoney_H.h"

bMoney::bMoney() : m_money(0)
{}

bMoney::bMoney(const char s[])
{
    put_money(s);
}

//bMoney::bMoney(const Sterling& st)
//{
//    m_money = st;
//}

bMoney::bMoney(double m)
{
    if (m > 99999999999999990)
        throw std::runtime_error("\nOverflow");
    if (m <= 0)
        throw std::runtime_error("\nDivision by 0 or result is less than 0");
    m_money = m;// / DTS;
}

bMoney::operator double() const
{
    return m_money;
}

//bMoney::operator Sterling() const
//{
//    return Sterling(m_money * DTS);
//}

bMoney bMoney::operator+(const bMoney& mon)
{
    return bMoney(m_money + mon.m_money);
}

bMoney bMoney::operator-(const bMoney& mon)
{
    return bMoney(m_money - mon.m_money);
}

bMoney bMoney::operator*(const double num)
{
    return bMoney(m_money * num);
}

double bMoney::operator/(const bMoney& mon)
{
    if (mon.m_money == 0)
        throw std::runtime_error("\nDivision by 0");
    return m_money / mon.m_money;
}

bMoney bMoney::operator/(const double num)
{
    return bMoney(m_money / num);
}

void bMoney::put_money(const char str[])
{
    if (strlen(str) > bMoney_STR_MAX)
        throw std::runtime_error("\nbMoney::put_money: the number is too big!");
    char numStr[bMoney_NUM_MAX];
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

void bMoney::put_money()
{
    char money[bMoney_STR_MAX];
    std::cin.get(money, bMoney_STR_MAX, '\n');
    std::cin.ignore(1, '\n');
    put_money(money);
}

std::string bMoney::get_money()
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