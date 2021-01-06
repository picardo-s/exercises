#include <iostream>
#include <cmath>
#include <iomanip>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction() : m_numerator(0), m_denominator(1)
    {}
    Fraction(int num, int den) : m_numerator(num), m_denominator(den)
    {
        lowTerms();
    }

    void setFract();
    void setFract(int num, int den);
    void setNum(int num);
    void setDen(int den);
    int getNum() const;
    int getDen() const;
    void print() const;
    Fraction add_fract(const Fraction& fract) const;
    Fraction sub_fract(const Fraction& fract) const;
    Fraction mul_fract(const Fraction& fract) const;
    Fraction div_fract(const Fraction& fract) const;
    void lowTerms();
};

void Fraction::setFract()
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

void Fraction::setFract(int num, int den)
{
    m_numerator = num;
    m_denominator = den;
}

void Fraction::setNum(int num)
{
    m_numerator = num;
}

void Fraction::setDen(int den)
{
    m_denominator = den;
}

int Fraction::getNum() const
{
    return m_numerator;
}

int Fraction::getDen() const
{
    return m_denominator;
}

void Fraction::print() const
{
    std::cout << m_numerator << "/" << m_denominator;
}

Fraction Fraction::add_fract(const Fraction& fract) const
{
    Fraction tempFract;
    tempFract.m_numerator = m_numerator * fract.m_denominator + m_denominator * fract.m_numerator;
    tempFract.m_denominator = m_denominator * fract.m_denominator;
    tempFract.lowTerms();
    return tempFract;
}

Fraction Fraction::sub_fract(const Fraction& fract) const
{
    Fraction tempFract;
    tempFract.m_numerator = m_numerator * fract.m_denominator - m_denominator * fract.m_numerator;
    tempFract.m_denominator = m_denominator * fract.m_denominator;
    tempFract.lowTerms();
    return tempFract;
}

Fraction Fraction::mul_fract(const Fraction& fract) const
{
    Fraction tempFract;
    tempFract.m_numerator = m_numerator * fract.m_numerator;
    tempFract.m_denominator = m_denominator * fract.m_denominator;
    tempFract.lowTerms();
    return tempFract;
}

Fraction Fraction::div_fract(const Fraction& fract) const
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
        throw std::runtime_error("Denominator can not be 0! ");
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
    int num = 1, den;

    try
    {
        Fraction fract, rowFract, colFract;

        std::cout << "Enter a denominator: ";
        std::cin >> den;
        Fraction defFract(num, den);

        std::cout << std::setiosflags(std::ios::left) << std::setw(den * 2) << "";//*

        fract = defFract;
        for (; num < den; num++)
        {
            std::cout << fract.getNum() << "/" << std::setw(den + 2) << fract.getDen();
            fract = fract.add_fract(defFract);
        }
        std::cout << '\n';

        for (int i = 0; i < den * (den + 5); i++)
            std::cout << "-";
        std::cout << '\n';

        colFract = rowFract = defFract;
        for (int i = 0; (colFract.getNum() / colFract.getDen()) < 1; i++)
        {
            if (i == 0)
            {
                std::cout << colFract.getNum() << "/" << std::setw(den + 2) << colFract.getDen();
                continue;
            }
            if ((i % den) == 0)
            {
                colFract = colFract.add_fract(defFract);
                if (colFract.getNum() / colFract.getDen() == 1)
                    continue;
                std::cout << '\n' << colFract.getNum() << "/" << std::setw(den + 2) << colFract.getDen();
                rowFract = defFract;
            }
            else
            {
                fract = rowFract.mul_fract(colFract);
                std::cout << fract.getNum() << "/" << std::setw(den + 2) << fract.getDen();
                rowFract = rowFract.add_fract(defFract);
            }
        }
    }
    catch (std::exception const& e)
    {
        std::cout << "Exception: " << e.what() << '\n';
    }
}


//int main()
//{
//    int num = 1, den;
//    while (1)
//    {
//        try
//        {
//            Fraction fract, rowFract, colFract;
//
//            std::cout << "Enter a denominator: ";
//            std::cin >> den;
//            Fraction defFract(num, den);
//
//            std::cout << std::setiosflags(std::ios::left) << std::setw(den * 2) << "";//*
//
//            fract = defFract;
//            for (; num < den; num++)
//            {
//                std::cout << fract.getNum() << "/" << std::setw(den + 2) << fract.getDen();
//                fract = fract.add_fract(defFract);
//            }
//            std::cout << '\n';
//
//            for (int i = 0; i < den * (den + 5); i++)
//                std::cout << "-";
//            std::cout << '\n';
//
//            colFract = rowFract = defFract;
//            for (int i = 0; (colFract.getNum() / colFract.getDen()) < 1; i++)
//            {
//                if (i == 0)
//                {
//                    std::cout << colFract.getNum() << "/" << std::setw(den + 2) << colFract.getDen();
//                    continue;
//                }
//                if ((i % den) == 0)
//                {
//                    colFract = colFract.add_fract(defFract);
//                    if (colFract.getNum() / colFract.getDen() == 1)
//                        continue;
//                    std::cout << '\n' << colFract.getNum() << "/" << std::setw(den + 2) << colFract.getDen();
//                    rowFract = defFract;
//                }
//                else
//                {
//                    fract = rowFract.mul_fract(colFract);
//                    std::cout << fract.getNum() << "/" << std::setw(den + 2) << fract.getDen();
//                    rowFract = rowFract.add_fract(defFract);
//                }
//            }
//        }
//        catch (std::exception const& e)
//        {
//            std::cout << "Exception: " << e.what() << '\n';
//            continue;
//        }
//        break;
//    }
//}
