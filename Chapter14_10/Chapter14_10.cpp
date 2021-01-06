#include <iostream>
#include <string>
#include <cstdlib>

class Distance
{
private:
    int feet;
    float inches;
    int isFeet(const std::string&);
public:
    Distance() : feet(0), inches(0)
    {}
    Distance(int ft, float inch) : feet(ft), inches(inch)
    {
        if (ft < -999 || ft > 999)
            throw Distance::RangeException("Feet must be between -999 and 999.", ft);
        if (inch < 0 || inch > 11.99)
            throw Distance::RangeException("Inches must be between 0.0 and 11.99.", inch);
    }

    void show_dist() const
    {
        std::cout << feet << "\'-" << inches << "\"";
    }

    void set_dist();

    class DistException
    {
    public:
        const std::string str_err;
        DistException(const std::string str) : str_err(str)
        {}
    };

    class RangeException : public DistException
    {
    public:
        const double range_err;
        RangeException(const std::string str, double num)
            : DistException(str), range_err(num)
        {}
    };

    class SymbolException : public DistException
    {
    public:
        const char ch_err;
        SymbolException(const std::string str, char ch)
            : DistException(str), ch_err(ch)
        {}
    };
};

void Distance::set_dist()
{
    std::string instr;

    std::cout << "\n\nEnter feet: ";
    std::cin.unsetf(std::ios::skipws);
    std::cin >> instr;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    if (isFeet(instr))
        feet = atoi(instr.c_str());
        

    std::cout << "Enter inches: ";
    std::cin.unsetf(std::ios::skipws);
    std::cin >> inches;
    std::cin.ignore(1000, '\n');
    if (std::cin.fail())
    {
        std::cin.clear();
        throw Distance::DistException("Wrong input.");
    }
    if (inches >= 12 || inches < 0)
        throw Distance::RangeException("Inches must be between 0.0 and 11.99.", inches);
}

int Distance::isFeet(const std::string& str)
{
    int len = str.size();
    if (len == 0)
        throw Distance::DistException("Feet must have a value.");

    for (int i = 0; i < len; i++)
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
            throw Distance::SymbolException("Wrong symbol.", str[i]);

    double n = atof(str.c_str());
    if (n < -999 || n > 999)
        throw Distance::RangeException("Feet must be between -999 and 999.", n);
    return 1; 
}

int main()
{
    char ans = 'y';
    do
    {
        try
        {
            Distance d;
            d.set_dist();
            std::cout << "\nThe distance = ";
            d.show_dist(); 
        }
        catch (Distance::RangeException e)
        {
            std::cout << "Exception: " << e.str_err << " Wrong value: " << e.range_err << '\n';
        }
        catch (Distance::SymbolException e)
        {
            std::cout << "Exception: " << e.str_err << " Wrong symbol: " << e.ch_err << '\n';
        }
        catch (Distance::DistException e)
        {
            std::cout << "Exception: " << e.str_err << '\n';
        }
        std::cout << "\nContinue?(y/n): ";
        std::cin >> ans;
        std::cin.ignore(1000, '\n');
    } while (ans != 'n');
}
