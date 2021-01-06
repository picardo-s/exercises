#include <iostream>
#include <cmath>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction() : m_numerator(0), m_denominator(1)
    {}
    Fraction(int num, int den) : m_numerator(num), m_denominator(den)
    {}

    void setFract();
    void print() const;
    Fraction add_fract(const Fraction& fract);
    Fraction sub_fract(const Fraction& fract);
    Fraction mul_fract(const Fraction& fract);
    Fraction div_fract(const Fraction& fract);
    void lowTerms();
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

Fraction Fraction::add_fract(const Fraction& fract)
{
    Fraction tempFract;
    tempFract.m_numerator = m_numerator * fract.m_denominator + m_denominator * fract.m_numerator;
    tempFract.m_denominator = m_denominator * fract.m_denominator;
    tempFract.lowTerms();
    return tempFract;
}

Fraction Fraction::sub_fract(const Fraction& fract)
{
    Fraction tempFract;
    tempFract.m_numerator = m_numerator * fract.m_denominator - m_denominator * fract.m_numerator;
    tempFract.m_denominator = m_denominator * fract.m_denominator;
    tempFract.lowTerms();
    return tempFract;
}

Fraction Fraction::mul_fract(const Fraction& fract)
{
    Fraction tempFract;
    tempFract.m_numerator = m_numerator * fract.m_numerator;
    tempFract.m_denominator = m_denominator * fract.m_denominator;
    tempFract.lowTerms();
    return tempFract;
}

Fraction Fraction::div_fract(const Fraction& fract)
{
    Fraction tempFract;
    tempFract.m_numerator = m_numerator * fract.m_denominator;
    tempFract.m_denominator = m_denominator * fract.m_numerator;
    tempFract.lowTerms();
    return tempFract;
}

void Fraction::lowTerms()
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
        return;
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

    switch (oper)
    {
    case '+':
        resultFract = fract1.add_fract(fract2);
        break;
    case '-':
        resultFract = fract1.sub_fract(fract2);
        break;
    case '/':
        resultFract = fract1.div_fract(fract2);
        break;
    case '*':
        resultFract = fract1.mul_fract(fract2);
        break;
    }
    std::cout << "The result is ";
    resultFract.print();
    std::cout << "One more time? (y/n): ";
    std::cin >> oper;
    std::cout << '\n';
} while (oper != 'n');
}