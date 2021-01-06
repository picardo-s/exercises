#include <iostream>
#include <iomanip>

constexpr int sterl_STR_MAX = 24;
constexpr int sterl_NUM_MAX = 20;

class Sterling
{
private:
    void check_sterl(long pound, int shill, int pen);
protected:
    long m_pounds;
    int m_shillings;
    int m_pence;
public:
    Sterling() : m_pounds(0), m_shillings(0), m_pence(0)
    {}
    Sterling(const char s[])
    {
        set_sterling(s);
        check_sterl(m_pounds, m_shillings, m_pence);
    }
    Sterling(double sterl)
    {
        if (sterl <= 0)
            throw std::runtime_error("\nDivision by 0 or result is less than 0");

        m_pounds = long(sterl) / 240;
        sterl = long(sterl) % 240;
        m_shillings = int(sterl) / 12;
        sterl = int(sterl) % 12;
        m_pence = sterl;
    }
    Sterling(long pound, int shill, int pen) :
        m_pounds(pound), m_shillings(shill), m_pence(pen)
    {
        check_sterl(pound, shill, pen);
    }
    operator double() const
    {
        return (m_pounds * 240 + m_shillings * 12 + m_pence);
    }

    void set_sterling();
    void set_sterling(const char s[]);
    void display() const;
    Sterling operator+(const Sterling& sterl) const;
    Sterling operator-(const Sterling& sterl) const;
    Sterling operator*(const double num) const;
    double operator/(const Sterling& sterl) const;
    Sterling operator/(const double num) const;
};

void Sterling::check_sterl(long pound, int shill, int pen)
{
    if (pound < 0 && (shill < 0 || shill >= 20) && (pen < 0 || pen >= 12))
        throw std::runtime_error("Overflow");
}

void Sterling::set_sterling(const char str[])
{
    if (strlen(str) > sterl_STR_MAX)
        throw std::runtime_error("\nSterling::put_sterling: the number is too big!");
    int strLength = strlen(str) + 1;
    char numStr[sterl_NUM_MAX];
    for (int i = 0, j = 0; i < strLength; i++)
    {
        if ((str[i] == 'J' || str[i] == '.'))// || str[i] == '-')
            continue;
        else
            numStr[j++] = str[i];
    }

    long money = atol(numStr);
    m_pounds = money / 10000;
    money %= 10000;
    m_shillings = money / 100;
    m_pence = money % 100;
}

void Sterling::set_sterling()
{
    char str[sterl_STR_MAX];
    std::cout << "sterling (Jx.xx.xx): ";
    std::cin.get(str, sterl_STR_MAX, '\n');
    std::cin.ignore(1, '\n');
    set_sterling(str);
}

void Sterling::display() const
{
    std::cout << "J" << m_pounds << "." << std::setfill('0') << std::setw(2) <<
        m_shillings << "." << std::setw(2) << m_pence;
}

Sterling Sterling::operator+(const Sterling& sterl) const
{
    return Sterling(double(Sterling(m_pounds, m_shillings, m_pence)) + double(sterl));
}

Sterling Sterling::operator-(const Sterling& sterl) const
{
    return Sterling(double(Sterling(m_pounds, m_shillings, m_pence)) - double(sterl));
}

Sterling Sterling::operator*(const double num) const
{
    return Sterling(double(Sterling(m_pounds, m_shillings, m_pence)) * num);
}

double Sterling::operator/(const Sterling& sterl) const
{
    return (double(Sterling(m_pounds, m_shillings, m_pence)) /
        double(Sterling(sterl.m_pounds, sterl.m_shillings, sterl.m_pence)));
}

Sterling Sterling::operator/(const double num) const
{
    return Sterling(double(Sterling(m_pounds, m_shillings, m_pence)) / num);
}

//-------------------------------------------------------------------------------------------

class Fraction
{
protected:
    int m_numerator;
    int m_denominator;
public:
    Fraction() : m_numerator(0), m_denominator(1)
    {}
    Fraction(int num, int den) : m_numerator(num), m_denominator(den)
    {
        lowTerms();
    }

    void set_fract();
    void display() const;
    int get_num() const;
    int get_den() const;
    void lowTerms();
};

void Fraction::set_fract()
{
    char charDiv;
    std::cout << "fraction(num/den): ";
    while (1)
    {
        std::cin >> m_numerator >> charDiv >> m_denominator;
        std::cin.ignore(100, '\n');
        if (std::cin.fail())
        {
            std::cout << "Wrong input. Again: ";
            std::cin.clear();
            std::cin.ignore(100, '\n');
            continue;
        }
        lowTerms();
        break;
    }
}

void Fraction::display() const
{
    std::cout << m_numerator << "/" << m_denominator << '\n';
}

int Fraction::get_num() const
{
    return m_numerator;
}

int Fraction::get_den() const
{
    return m_denominator;
}

void Fraction::lowTerms()
{
    long tnum, tden, temp, gcd;
    tnum = abs(m_numerator);
    tden = abs(m_denominator);
    if (tden == 0)
    {
        throw std::runtime_error("Fraction: denominator can not be 0!");
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

//-------------------------------------------------------------------------------------------

constexpr int STER_FRACT_DEN = 8;

class SterFract : private Sterling
{
private:
    void check_eights(int eights);
    int mult_den(int den);
protected:
    Fraction fract;
public:
    SterFract() : Sterling(), fract(Fraction())
    {}
    SterFract(double sterl, int eights) : Sterling(sterl)
    {
        check_eights(eights);
        fract = Fraction(eights, STER_FRACT_DEN);
    }
    SterFract(long pound, int shil, int pen, int eights) : Sterling(pound, shil, pen)
    {
        check_eights(eights);
        fract = Fraction(eights, STER_FRACT_DEN);
    }
    void set_sterFract();
    void display();
    SterFract operator+(const SterFract& ster);
    SterFract operator-(const SterFract& ster);
    SterFract operator*(const double num);
    SterFract operator/(const double num);
};

void SterFract::check_eights(int eights)
{
    if (eights > STER_FRACT_DEN || eights < 0)
        throw std::runtime_error("Eights is expected to be \'0 < eights < 8\'");
}

int SterFract::mult_den(int den)
{
    if (den == 2)
        return 4;
    else if (den == 4)
        return 2;
    else return 1;
}

void SterFract::set_sterFract()
{
    Sterling::set_sterling();
    std::cout << "Enter eighths. ";
    while (1)
    {
        fract.set_fract();
        if (fract.get_den() != 2 && fract.get_den() != 4 && fract.get_den() != 8)
        {
            std::cout << "Denominator have to be 2, 4 or 8. Again: ";
            continue;
        }
        break;
    }
}

void SterFract::display()
{
    Sterling::display();
    std::cout << "-";
    fract.display();
}

SterFract SterFract::operator+(const SterFract& ster)
{
    double dblTemp = Sterling(m_pounds, m_shillings, m_pence) + Sterling(ster.m_pounds, ster.m_shillings, ster.m_pence);
    int tempEighths = fract.get_num() * mult_den(fract.get_den()) + ster.fract.get_num() * mult_den(ster.fract.get_den());
    if (tempEighths >= 8)
    {
        dblTemp += 1;
        tempEighths -= 8;
    }
    return SterFract(dblTemp, tempEighths);
}

SterFract SterFract::operator-(const SterFract& ster)
{
    double dblTemp = Sterling(m_pounds, m_shillings, m_pence) - Sterling(ster.m_pounds, ster.m_shillings, ster.m_pence);
    int tempEighths = fract.get_num() * mult_den(fract.get_den()) - ster.fract.get_num() * mult_den(ster.fract.get_den());
    if (tempEighths < 0)
    {
        dblTemp -= 1;
        tempEighths += STER_FRACT_DEN;
    }
    return SterFract(dblTemp, tempEighths);
}

SterFract SterFract::operator*(const double num)
{
    double dblTemp = Sterling(m_pounds, m_shillings, m_pence) * num;
    int tempEighths = fract.get_num()*mult_den(fract.get_den()) * num;
    if (tempEighths >= STER_FRACT_DEN)
    {
        dblTemp += int(tempEighths / STER_FRACT_DEN);
        tempEighths = int(tempEighths % STER_FRACT_DEN);
    }
    return SterFract(dblTemp, tempEighths);
}

SterFract SterFract::operator/(const double num)
{
    double dblTemp = Sterling(m_pounds, m_shillings, m_pence) / num;
    int tempEighths = fract.get_num() * mult_den(fract.get_den()) / num; //we allow here an admission that a modulo is avoided
    return SterFract(dblTemp, tempEighths);
}

int main()
{
    try
    {
        SterFract sf1, sf2;
        std::cout << "sf1: ";
        sf1.set_sterFract();
        std::cout << "sf2: ";
        sf2.set_sterFract();
        std::cout << "Enter the double num: ";
        double dNum;
        std::cin >> dNum;

        std::cout << "\nsf1 = ";
        sf1.display();
        std::cout << "sf2 = ";
        sf2.display();
        std::cout << "dNum = " << dNum;

        SterFract sf3;
        std::cout << "\n\nsf1 + sf2 = ";
        sf3 = sf1 + sf2;
        sf3.display();

        std::cout << "\nsf1 - sf2 = ";
        sf3 = sf1 - sf2;
        sf3.display();

        std::cout << "\nsf1 * dNum = ";
        sf3 = sf1 * dNum;
        sf3.display();

        std::cout << "\nsf1 / dNum = ";
        sf3 = sf1 / dNum;
        sf3.display();
    }
    catch(std::exception & e)
    {
        std::cout << "Exception: " << e.what();
    }
}
