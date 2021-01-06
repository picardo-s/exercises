#include "Sterling_H.h"

Sterling::Sterling() : m_pounds(0), m_shillings(0), m_pence(0)
{}

Sterling::Sterling(long pound, int shil, int pen) :
    m_pounds(pound), m_shillings(shil), m_pence(pen)
{}

Sterling::Sterling(const char s[])
{
    put_sterling(s);
}
Sterling::Sterling(double sterl)
{
    //sterl *= DTS;
    if (sterl > 99999999999999990)
        throw std::runtime_error("\nOverflow");
    if (sterl <= 0)
        throw std::runtime_error("\nDivision by 0 or result is less than 0");

    m_pounds = long(sterl) / 240;
    sterl = long(sterl) % 240;
    m_shillings = int(sterl) / 12;
    sterl = int(sterl) % 12;
    m_pence = sterl;
}

Sterling::operator double() const
{
    return (m_pounds * 240 + m_shillings * 12 + m_pence);
}

void Sterling::put_sterling(const char str[])
{
    if (strlen(str) > sterl_STR_MAX)
        throw std::runtime_error("\nSterling::put_sterling: the number is too big!");
    int strLength = strlen(str) + 1;
    char numStr[sterl_NUM_MAX];
    for (int i = 0, j = 0; i < strLength; i++)
    {
        if ((str[i] == 'J' || str[i] == '.') || str[i] == '-')
            continue;
        else
            numStr[j++] = str[i];
    }

    long money = atol(numStr);
    m_pounds = money / 10000;
    money %= 10000;
    m_shillings = money / 100;
    m_pence = money % 100;

    /*if (m_pence >= 12 || m_shillings >= 20)
    {
        std::cout << "Overflow!";
        std::exit(1);
    }*/
}

void Sterling::put_sterling()
{
    char str[sterl_STR_MAX];
    std::cin.get(str, sterl_STR_MAX, '\n');
    std::cin.ignore(1, '\n');
    put_sterling(str);
}

void Sterling::display()
{
    std::cout << "J" << m_pounds << "." << std::setfill('0') << std::setw(2) <<
        m_shillings << "." << std::setw(2) << m_pence;
}

Sterling Sterling::operator+(const Sterling& sterl)
{
    return Sterling(double(Sterling(m_pounds, m_shillings, m_pence)) + double(sterl));
}

Sterling Sterling::operator-(const Sterling& sterl)
{
    return Sterling(double(Sterling(m_pounds, m_shillings, m_pence)) - double(sterl));
}

Sterling Sterling::operator*(const double num)
{
    return Sterling(double(Sterling(m_pounds, m_shillings, m_pence)) * num);
}

double Sterling::operator/(const Sterling& sterl)
{
    return (double(Sterling(m_pounds, m_shillings, m_pence)) /
        double(Sterling(sterl.m_pounds, sterl.m_shillings, sterl.m_pence)));
}

Sterling Sterling::operator/(const double num)
{
    return Sterling(double(Sterling(m_pounds, m_shillings, m_pence)) / num);
}