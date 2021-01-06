#include <iostream>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;
public:
    void setFract();
    void print() const;
    Fraction add_fract(const Fraction& fract);
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
    return tempFract;
}

int main()
{
    Fraction fract1, fract2, sumFract;
    char manip = 'a';
    do
    {
        std::cout << "Enter the first fraction: ";
        fract1.setFract();
        std::cout << "Enter the second fraction: ";
        fract2.setFract();
        sumFract = fract1.add_fract(fract2);
        std::cout << "The sum is : ";
        sumFract.print();

        std::cout << "One more time?(y/n): ";
        std::cin >> manip;
        std::cout << '\n';
    } while (manip != 'n');
}
