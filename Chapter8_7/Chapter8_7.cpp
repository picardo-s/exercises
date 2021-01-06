#include <iostream>

#include <cmath>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction() : m_numerator(1), m_denominator(1)
    {}
    Fraction(int num, int den) : m_numerator(num), m_denominator(den)
    {}

    void setFract();
    void print() const;
    Fraction operator+(const Fraction& fract);
    Fraction operator-(const Fraction& fract);
    Fraction operator*(const Fraction& fract);
    Fraction operator/(const Fraction& fract);
    bool operator==(const Fraction& fract);
    bool operator!=(const Fraction& fract);
    Fraction lowTerms();
};

void Fraction::setFract()
{
    char charDiv;
    std::cout << "\n(numerator/denominator): ";
    std::cin >> m_numerator >> charDiv >> m_denominator;
}

void Fraction::print() const
{
    std::cout << m_numerator << "/" << m_denominator << '\n';
}

Fraction Fraction::operator+(const Fraction& fract)
{
    Fraction temp;
    temp.m_numerator = m_numerator * fract.m_denominator + m_denominator * fract.m_numerator;
    temp.m_denominator = m_denominator * fract.m_denominator;
    return temp.lowTerms();
}

Fraction Fraction::operator-(const Fraction& fract)
{
    Fraction tempFract;
    tempFract.m_numerator = m_numerator * fract.m_denominator - m_denominator * fract.m_numerator;
    tempFract.m_denominator = m_denominator * fract.m_denominator;
    return tempFract.lowTerms();
}

Fraction Fraction::operator*(const Fraction& fract)
{
    Fraction tempFract;
    tempFract.m_numerator = m_numerator * fract.m_numerator;
    tempFract.m_denominator = m_denominator * fract.m_denominator;
    return tempFract.lowTerms();
}

Fraction Fraction::operator/(const Fraction& fract)
{
    Fraction tempFract;
    tempFract.m_numerator = m_numerator * fract.m_denominator;
    tempFract.m_denominator = m_denominator * fract.m_numerator;
    return tempFract.lowTerms();
}

bool Fraction::operator==(const Fraction& fract)
{
    return (m_numerator == fract.m_numerator && m_denominator == fract.m_denominator) ? true : false;
}


bool Fraction::operator!=(const Fraction& fract)
{
    return (m_numerator != fract.m_numerator || m_denominator != fract.m_denominator) ? true : false;
}

Fraction Fraction::lowTerms()
{
    long tnum, tden, temp, gcd;
    tnum = abs(m_numerator);
    tden = abs(m_denominator);
    if (tden == 0)
    {
        std::cout << "Denominator can not be 0! ";
        exit(1);
    }
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

int main()
{
    char oper;
    Fraction fract1, fract2, resultFract;
    do
    {
        std::cout << "Enter the first fraction: ";
        fract1.setFract();
        std::cout << "Enter an operator(+, -, / or *): ";
        std::cin >> oper;
        std::cout << "Enter the second fraction: ";
        fract2.setFract();

        if (oper != '+' && oper != '-' && oper != '/' && oper != '*')
        {
            std::cout << "Wrong operator. Try again!\n";
            continue;
        }

        if (fract1 == Fraction(0, 1) || fract2 == Fraction(0, 1)) // I could understand the conditions of this task incorrectly
        {
            std::cout << "Some Fraction is 0/1";
            break;
        }

        switch (oper)
        {
        case '+':
            resultFract = fract1 + fract2;
            break;
        case '-':
            resultFract = fract1 - fract2;
            break;
        case '/':
            resultFract = fract1 / fract2;
            break;
        case '*':
            resultFract = fract1 * fract2;
            break;
        }
        std::cout << "The result is ";
        resultFract.print();
        std::cout << "One more time? (y/n): ";
        std::cin >> oper;
        std::cout << '\n';
    } while (oper != 'n');
}
