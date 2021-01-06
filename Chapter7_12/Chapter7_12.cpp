#include <iostream>
#include <string>
#include <strstream>
#include <iomanip>

constexpr int MAX_STR = 30;

class bMoney
{
private:
    double m_money;
    static constexpr int NUM_MAX = 23; //for keeping 17-char number
public:
    bMoney() : m_money(0)
    {}
    bMoney(const char s[])
    {
        put_money(s);
    }
    void madd(const bMoney& mon);
    std::string get_money() const;
    void put_money(const char str[]);
    void put_money();
};

void bMoney::put_money(const char str[])
{
    if (strlen(str) > MAX_STR)
        throw std::runtime_error("The number is too big");

    char numStr[NUM_MAX];
    int strLength = strlen(str);
    for (int i = 0, j = 0; i < strLength; i++)
    {
        if (str[i] == '$' || str[i] == ',')// || str[i] == '-')
            continue;
        else if((str[i] < '0' || str[i] > '9') && str[i] != '.')
            throw std::runtime_error("Wrong symbol");     
        else numStr[j++] = str[i];
    }
    m_money = atof(numStr);
}

void bMoney::put_money()
{
    char money[MAX_STR];
    std::cin.get(money, MAX_STR, '\n');
    std::cin.ignore(1, '\n');
    put_money(money);
}

std::string bMoney::get_money() const
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

void bMoney::madd(const bMoney& mon)
{
    if ((m_money + mon.m_money) > 99999999999999990) //this number have to be constexpr variable
        throw std::runtime_error("Overflow");
    m_money += mon.m_money;
}

int main()
{
    try
    {
        bMoney m1, m2;

        std::cout << "Enter the first amount of dollars: ";
        m1.put_money();

        std::cout << "Enter the second amount of dollars: ";
        m2.put_money();

        m1.madd(m2);
        std::cout << "The sum is: " << m1.get_money();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what();
    }

}