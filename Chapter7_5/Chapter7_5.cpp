#include <iostream>

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
    const int MAX = 100;
    Fraction fractArr[MAX];
    int count = 0;
    char manip = 'a';

    do
    {
        std::cout << "Enter a fraction #" << count + 1;
        fractArr[count++].setFract();
        std::cout << "Continue?(y/n): ";
        std::cin >> manip;
        std::cout << '\n';
    } while (manip != 'n' && count < MAX);

    Fraction sumFract = fractArr[0];
    for (int i = 1; i < count; i++)
    {
        sumFract = sumFract.add_fract(fractArr[i]);
    }

    Fraction divisorFract(count, 1);
    sumFract = sumFract.div_fract(divisorFract);
    std::cout << "The average Fraction is ";
    sumFract.print();
}