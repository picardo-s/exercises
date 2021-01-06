#include <iostream>
#include <iomanip>
#include <string>
#include <strstream>

class Sterling
{
private:
    long m_pounds;
    int m_shillings;
    int m_pence;
    static const int STR_MAX = 24;
    static const int NUM_MAX = 20;
public:
    Sterling() : m_pounds(0), m_shillings(0), m_pence(0)
    {}
    explicit Sterling(char s[])
    {
        putSterling(s);
    }
    explicit Sterling(double sterl)
    {
        if (sterl < 0)
        {
            std::cout << "The result is less than 0!";
            std::exit(1);
        }
        m_pounds = long(sterl) / 240;
        sterl = long(sterl) % 240;
        m_shillings = int(sterl) / 12;
        sterl = int(sterl) % 12;
        m_pence = sterl;
    }
    Sterling(long pound, int shil, int pen) :
        m_pounds(pound), m_shillings(shil), m_pence(pen)
    {}
    operator double() const
    {
        return (m_pounds * 240 + m_shillings * 12 + m_pence);
    }
    void putSterling();
    void putSterling(char s[]);
    void getSterling();
    Sterling operator+(const Sterling& sterl);
    Sterling operator-(const Sterling& sterl);
    Sterling operator*(const double num);
    double operator/(const Sterling& sterl);
    Sterling operator/(const double num);
};

void Sterling::putSterling()
{
    char str[STR_MAX];                                                   //There is the shorter way to do it: 
    std::cout << "\nEnter an amount of sterlings (Jx.xx.xx): ";          //  char poundCh, chDiv;
    std::cin >> std::setw(STR_MAX) >> str;                               //  std::cin >> poundCh >> m_pounds >> chDiv >> m_shillings >> chDiv >> m_pence;
    int strLength = strlen(str) + 1;
    char numStr[NUM_MAX];
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

    if (m_pence >= 12 || m_shillings >= 20)
    {
        std::cout << "Overflow!";
        std::exit(1);
    }
}

void Sterling::putSterling(char str[])
{
    if (strlen(str) > STR_MAX)
    {
        std::cout << "\nThe number is too big!";
        return;
    }
    int strLength = strlen(str) + 1;
    char numStr[NUM_MAX];
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

    if (m_pence >= 12 || m_shillings >= 20)
    {
        std::cout << "Overflow!";
        std::exit(1);
    }
}

void Sterling::getSterling()
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

class bMoney
{
private:
    double m_money;
    static const int NUM_MAX = 23;
    static const int STR_MAX = 30;
    const double DTS;
public:
    bMoney() : m_money(0), DTS(4.8)
    {}
    explicit bMoney(char s[]) : DTS(4.8)
    {
        putmoney(s);
    }
    explicit bMoney(double m) : DTS(4.8)
    {
        if (m > 99999999999999990)
        {
            std::cout << "\nOverflow!";
            std::exit(1);
        }
        m_money = m / DTS;
    }

    operator Sterling() const
    {
        return Sterling(m_money * DTS);
    }

    bMoney operator+(const bMoney& mon);
    bMoney operator-(const bMoney& mon);
    bMoney operator*(const double num);
    double operator/(const bMoney& mon);
    bMoney operator/(const double num);
    std::string getmoney();
    void putmoney(char str[]);
    void putmoney();
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

void bMoney::putmoney()
{
    char str[STR_MAX]; 
    std::cout << "\nEnter an amount of dollars ($x): ";
    std::cin >> std::setw(STR_MAX) >> str;
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
    std::cout << "From Sterling to bMoney: \n";
    Sterling st;
    st.putSterling();
    bMoney mon(st);
    std::cout << mon.getmoney();

    std::cout << "\nFrom bMoney to Sterling: \n";
    bMoney mn;
    mn.putmoney();
    Sterling ste = mn;
    ste.getSterling();
}
