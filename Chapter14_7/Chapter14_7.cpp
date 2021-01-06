#include <iostream>

#include <cmath>

template<class Type>
class Fraction
{
private:
    Type m_numerator;
    Type m_denominator;
public:
    Fraction() : m_numerator(1), m_denominator(1)
    {}
    Fraction(Type num, Type den) : m_numerator(num), m_denominator(den)
    {}

    void setFract();
    void print() const;
    Fraction operator+(const Fraction& fract) const;
    Fraction operator-(const Fraction& fract) const;
    Fraction operator*(const Fraction& fract) const;
    Fraction operator/(const Fraction& fract) const;
    bool operator==(const Fraction& fract) const;
    bool operator!=(const Fraction& fract) const;
    Fraction lowTerms();
};

template<class Type>
void Fraction<Type>::setFract()
{
    char charDiv;
    while (1)
    {
        std::cout << "\n(numerator/denominator): ";
        std::cin >> m_numerator >> charDiv >> m_denominator;
        if (std::cin.fail())
        {
            std::cout << "Wrong input";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        if (charDiv != '/')
        {
            std::cout << "Wrong division symbol";
            continue;
        }
        std::cin.ignore(1000, '\n');
        break;
    }
}

template<class Type>
void Fraction<Type>::print() const
{
    std::cout << long(m_numerator) << "/" << long(m_denominator) << '\n';
}

template<class Type>
Fraction<Type> Fraction<Type>::operator+(const Fraction& fract) const
{
    Fraction temp;
    temp.m_numerator = m_numerator * fract.m_denominator + m_denominator * fract.m_numerator;
    temp.m_denominator = m_denominator * fract.m_denominator;
    return temp.lowTerms();
}

template<class Type>
Fraction<Type> Fraction<Type>::operator-(const Fraction& fract) const
{
    Fraction tempFract;
    tempFract.m_numerator = m_numerator * fract.m_denominator - m_denominator * fract.m_numerator;
    tempFract.m_denominator = m_denominator * fract.m_denominator;
    return tempFract.lowTerms();
}

template<class Type>
Fraction<Type> Fraction<Type>::operator*(const Fraction& fract) const
{
    Fraction tempFract;
    tempFract.m_numerator = m_numerator * fract.m_numerator;
    tempFract.m_denominator = m_denominator * fract.m_denominator;
    return tempFract.lowTerms();
}

template<class Type>
Fraction<Type> Fraction<Type>::operator/(const Fraction& fract) const
{
    Fraction tempFract;
    tempFract.m_numerator = m_numerator * fract.m_denominator;
    tempFract.m_denominator = m_denominator * fract.m_numerator;
    return tempFract.lowTerms();
}

template<class Type>
bool Fraction<Type>::operator==(const Fraction& fract) const
{
    return (m_numerator == fract.m_numerator && m_denominator == fract.m_denominator) ? true : false;
}

template<class Type>
bool Fraction<Type>::operator!=(const Fraction& fract) const
{
    return (m_numerator != fract.m_numerator || m_denominator != fract.m_denominator) ? true : false;
}

template<class Type>
Fraction<Type> Fraction<Type>::lowTerms()
{
    Type tnum, tden, temp, gcd;
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

void set_fract_operator(char& oper)
{
    while (1)
    {
        std::cin >> oper;
        std::cin.ignore(1000, '\n');
        if (oper != '+' && oper != '-' && oper != '/' && oper != '*')
        {
            std::cout << "Wrong operator.\n Try again: ";
            continue;
        }
        break;
    }
}

int main()
{
    typedef char fract_t;
    char oper;
    Fraction<fract_t> fract1, fract2, resultFract;
    do
    {
        std::cout << "Enter the first fraction: ";
        fract1.setFract();
        std::cout << "Enter an operator(+, -, / or *): ";
        set_fract_operator(oper);
        std::cout << "Enter the second fraction: ";
        fract2.setFract();

        if (fract1 == Fraction<fract_t>(0, 1) || fract2 == Fraction<fract_t>(0, 1)) // I could understand the conditions of this task incorrectly
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
        std::cin.ignore(1000, '\n');
        std::cout << '\n';
    } while (oper != 'n');
}