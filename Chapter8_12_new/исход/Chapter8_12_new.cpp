#include <iostream>
#include <iomanip>
#include <string>
#include <strstream>

constexpr int sterl_STR_MAX = 24;
constexpr int sterl_NUM_MAX = 20;

class Sterling
{
private:
    long m_pounds;
    int m_shillings;
    int m_pence;
public:
    Sterling() : m_pounds(0), m_shillings(0), m_pence(0)
    {}
    explicit Sterling(const char s[])
    {
        put_sterling(s);
    }
    explicit Sterling(double sterl)
    {
        if (sterl > 99999999999999990)
            throw std::runtime_error("\nOverflow");
        if (sterl <= 0)
            throw std::runtime_error("\nDivision by 0 or result is less than 0");

        m_pounds = long(sterl) / 240;
        sterl = long(sterl) % 240;
        m_shillings = int(sterl) / 12; //
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
    void put_sterling();
    void put_sterling(const char s[]);
    void display();
    Sterling operator+(const Sterling& sterl);
    Sterling operator-(const Sterling& sterl);
    Sterling operator*(const double num);
    double operator/(const Sterling& sterl);
    Sterling operator/(const double num);
};

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

//--------------------------------------------------------------------------------------------

constexpr int bMoney_STR_MAX = 30;
constexpr int bMoney_NUM_MAX = 23;
constexpr double DTS = 4.8;

class bMoney
{
private:
    double m_money;
public:
    bMoney() : m_money(0)
    {}
    explicit bMoney(const char s[])
    {
        put_money(s);
    }
    explicit bMoney(double m)
    {
        if (m > 99999999999999990)
            throw std::runtime_error("\nOverflow");
        if (m <= 0)
            throw std::runtime_error("\nDivision by 0 or result is less than 0");
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
    std::string get_money();
    void put_money(const char str[]);
    void put_money();
};

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

int main()
{
    try
    {
        std::cout << "From Sterling to bMoney: \n";
        Sterling st;
        st.put_sterling();
        bMoney mon(st);
        std::cout << mon.get_money();

        std::cout << "\nFrom bMoney to Sterling: \n";
        bMoney mn;
        mn.put_money();
        Sterling ste = mn;
        ste.display();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what();
    }
}