#include <iostream>
#include <iomanip>

class Sterling
{
private:
    long m_pounds;
    int m_shillings;
    int m_pence;
public:
    Sterling()
    {}
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
    void getSterling();
    void putSterling();
    operator double() const
    {
        return (m_pounds * 240 + m_shillings * 12 + m_pence);
    }
    Sterling operator+(const Sterling& sterl);
    Sterling operator-(const Sterling& sterl);
    Sterling operator*(const double num);
    double operator/(const Sterling& sterl);
    Sterling operator/(const double num);
};

void Sterling::getSterling()
{
    char str[24];                                                   //There is the shorter way to do it: 
    std::cout << "\nEnter an amount of sterlings (Jx.xx.xx): ";     //  char poundCh, chDiv;
    std::cin >> std::setw(24) >> str;                               //  std::cin >> poundCh >> m_pounds >> chDiv >> m_shillings >> chDiv >> m_pence;
    int strLength = strlen(str) + 1;                                //
    char numStr[20];
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

void Sterling::putSterling()
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

int main()
{
    Sterling s1, s2, s3;
    double dNum;
    std::cout << "Enter a double number: ";
    std::cin >> dNum;

    s1.getSterling();
    std::cout << "s1 = ";
    s1.putSterling();

    s2.getSterling();
    std::cout << "s2 = ";
    s2.putSterling();

    s3 = s1 + s2;
    std::cout << "\ns1 + s2 = ";
    s3.putSterling();

    s3 = s1 - s2;
    std::cout << "\ns1 - s2 = ";
    s3.putSterling();

    s3 = s1 * dNum;
    std::cout << "\ns1 * dNum = ";
    s3.putSterling();

    s3 = s1 / dNum;
    std::cout << "\ns1 / dNum = ";
    s3.putSterling();

    dNum = s1 / s2;
    std::cout << "\ns1 / s2 = ";
    std::cout << dNum;
}