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
    bMoney(double m)
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
    friend bMoney operator*(const double num, const bMoney& mon2);
    friend double operator/(const double num, const bMoney& mon2);
    friend std::ostream& operator<<(std::ostream& s, bMoney& mon);
    friend std::istream& operator>>(std::istream& s, bMoney& mon);
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
        std::cout << "\nThe result of this operation cannot be less than 0";
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

bMoney operator*(const double num, const bMoney& mon2)
{
    if ((num * mon2.m_money) > 99999999999999990)
    {
        std::cout << "\nOverflow!";
        std::exit(1);
    }
    return bMoney(num * mon2.m_money);
}

double operator/(const double num, const bMoney& mon2)
{
    if (mon2.m_money == 0)
    {
        std::cout << "\nDivision by 0";
        std::exit(1);
    }
    return (num / mon2.m_money);
}

std::ostream& operator<<(std::ostream& s, bMoney& mon)
{
    std::ostrstream strObj;
    strObj.flags(std::ostream::fixed);
    strObj.precision(2);
    strObj << mon.m_money << std::ends;
    std::string ustring = strObj.str();

    std::string moneyStr("$");
    for (int i = 1; i <= ustring.size(); i++)
    {
        moneyStr += ustring.at(i - 1);
        if (((ustring.size() - i) % 3) == 0 && ((ustring.size() - i) > 3))
            moneyStr += ",";
    }
    moneyStr += '\0';
    s << moneyStr;
    return s;
}

std::istream& operator>>(std::istream& s, bMoney& mon)
{
    const int MAX = 30;
    char money[MAX];
    std::cin >> std::setw(MAX) >> money;

    if (strlen(money) > mon.STR_MAX)
    {
        std::cout << "\nThe number is too big!";
        std::exit(1);
    }
    char numStr[mon.NUM_MAX];
    int strLength = strlen(money) + 1;
    for (int i = 0, j = 0; i < strLength; i++)
    {
        if ((money[i] == '$' || money[i] == ',') || money[i] == '-')
            continue;
        else
            numStr[j++] = money[i];
    }
    mon.m_money = atof(numStr);
    return s;
}

int main()
{
    bMoney m1, m2, m3;
    double dNum;
    char manip;

    do
    {
        std::cout << "Enter the first amount of dollars (bM1): ";
        std::cin >> m1;
        std::cout << "Enter the second amount of dollars (bM2): ";
        std::cin >> m2;
        std::cout << "Enter a float number (num): ";
        std::cin >> dNum;

        std::cout << "\nbM1 + bM2 = " << (m3 = m1 + m2);
        std::cout << "\nbM1 - bM2 = " << (m3 = m1 - m2);
        std::cout << "\nbM1 * num = " << (m3 = m1 * dNum);
        std::cout << "\nbM1 / num = " << (m3 = m1 / dNum);
        double rez;
        std::cout << "\nbM1 / bM2 = " << (rez = m1 / m2);
        std::cout << "\ndNum * m1 = " << (m3 = dNum * m1);
        std::cout << "\ndNum / m1 = " << (rez = dNum / m1);

        std::cout << "\nContinue?(y/n): ";
        std::cin >> manip;
        std::cout << '\n';

    } while (manip != 'n');
}
