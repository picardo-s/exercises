#include <iostream>
#include <cmath>
#include <utility>
#include <string>

std::string get_user_string()
{
    std::string temp{};
    std::getline(std::cin, temp);
    return temp;
}

char get_user_char()
{
    char temp{}, ch{};
    std::cin >> temp;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return temp;
}

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
    static std::pair<int, int> fromString(const std::string&);
    Fraction lowTerms();
public:
    Fraction() : m_numerator(1), m_denominator(1)
    {}
    Fraction(int num, int den) : m_numerator(num), m_denominator(den)
    {}

    Fraction operator+(const Fraction& fract) const;
    Fraction operator-(const Fraction& fract) const;
    Fraction operator*(const Fraction& fract) const;
    Fraction operator/(const Fraction& fract) const;
    bool operator==(const Fraction& fract) const;
    bool operator!=(const Fraction& fract) const;
    friend std::ostream& operator<<(std::ostream& s, const Fraction& frac);
    friend std::istream& operator>>(std::istream& s, Fraction& frac);
};

Fraction Fraction::operator+(const Fraction& fract) const
{
    Fraction temp;
    temp.m_numerator = m_numerator * fract.m_denominator + m_denominator * fract.m_numerator;
    temp.m_denominator = m_denominator * fract.m_denominator;
    return temp.lowTerms();
}

Fraction Fraction::operator-(const Fraction& fract) const
{
    Fraction tempFract;
    tempFract.m_numerator = m_numerator * fract.m_denominator - m_denominator * fract.m_numerator;
    tempFract.m_denominator = m_denominator * fract.m_denominator;
    return tempFract.lowTerms();
}

Fraction Fraction::operator*(const Fraction& fract) const
{
    Fraction tempFract;
    tempFract.m_numerator = m_numerator * fract.m_numerator;
    tempFract.m_denominator = m_denominator * fract.m_denominator;
    return tempFract.lowTerms();
}

Fraction Fraction::operator/(const Fraction& fract) const
{
    Fraction tempFract;
    tempFract.m_numerator = m_numerator * fract.m_denominator;
    tempFract.m_denominator = m_denominator * fract.m_numerator;
    return tempFract.lowTerms();
}

bool Fraction::operator==(const Fraction& fract) const
{
    return (m_numerator == fract.m_numerator && m_denominator == fract.m_denominator) ? true : false;
}


bool Fraction::operator!=(const Fraction& fract) const
{
    return !(*this == fract);
}

Fraction Fraction::lowTerms()
{
    long tnum, tden, temp, gcd;
    tnum = abs(m_numerator);
    tden = abs(m_denominator);
    if (tden == 0)
        throw std::runtime_error("Denominator can not be 0!");
    else if (tnum == 0)
    {
        m_numerator = 0;
        m_denominator = 1;
        return Fraction(0, 1);
    }
    while (tnum != 0)
    {
        if (tnum < tden)
        {
            temp = tnum;
            tnum = tden;
            tden = temp;
        }
        tnum = tnum - tden;
    }
    gcd = tden;
    m_numerator = m_numerator / gcd;
    m_denominator = m_denominator / gcd;
    return Fraction(m_numerator, m_denominator);
}

std::pair<int, int> Fraction::fromString(const std::string& str)
{
    std::string num{}, den{};
    bool slash{false};
    int i{};

    if (str[0] == '-')
    {
        i++;
        num += str[0];
    }

    for (; i < str.size(); i++)
    {
        if (str[i] == '/')
            if (!slash)
            {
                slash = true;
                continue;
            }

        if (isdigit(str[i]))
        {
            if (!slash)
                num += str[i];
            else den += str[i];
        }
        else throw std::runtime_error(" Wrong letter");
    }
    return std::make_pair(atoi(num.c_str()), atoi(den.c_str()));
}

std::ostream& operator<<(std::ostream& s, const Fraction& frac)
{
    std::cout << frac.m_numerator << "/" << frac.m_denominator << '\n';
    return s;
}

std::istream& operator>>(std::istream& s, Fraction& frac)
{
    auto numbers = frac.fromString(get_user_string());
    frac.m_numerator = numbers.first;
    frac.m_denominator = numbers.second;
    return s;
}

int main()
{
    try
    {
        char oper{};
        Fraction fract1, fract2;
        do
        {
            std::cout << "Enter the first fraction: ";
            std::cin >> fract1;
            std::cout << "Enter an operator (+,-,*,/): ";
            while (1)
            {
                oper = get_user_char();
                if (oper == '+' || oper == '-' || oper == '*' || oper == '/')
                    break;
                std::cout << "Wrong operator. Try again: ";
            }
            std::cout << "Enter the second fraction: ";
            std::cin >> fract2;
            std::cout << "Result: ";

            switch (oper)
            {
            case '+':
                std::cout << (fract1 + fract2);
                break;
            case '-': 
                std::cout << (fract1 - fract2);
                break;
            case '/':
                std::cout << (fract1 / fract2);
                break;
            case '*':
                std::cout << (fract1 * fract2);
                break;
            }
            std::cout << "One more time? (y/n): ";
            oper = get_user_char();
            std::cout << '\n';
        } while (oper != 'n');
    }
    catch (std::exception& e)
    {
        std::cout << "Exception! " << e.what();
    }
}
