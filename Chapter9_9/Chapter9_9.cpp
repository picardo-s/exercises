#include <iostream>
#include <string>
#include <iomanip>


double get_user_number()
{
    double temp;
    std::cin >> temp;
    std::cin.ignore(1000, '\n');
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        throw std::runtime_error("Wrong input\n");
    }
    return temp;
}

std::string get_user_string()
{
    std::string temp;
    std::getline(std::cin, temp);
    return temp;
}

double get_more_than_zero()
{
    double temp;
    while (1)
    {
        temp = get_user_number();
        if (temp < 0)
        {
            std::cout << "Cannot be less than 0. Again: ";
            continue;
        }
        return temp;
    }
}

class Date
{
private:
    int m_month;
    int m_day;
    int m_year;

    void check_date(int month, int day, int year)
    {
        if (month < 1 || day < 1 || year < 0)
            throw std::runtime_error("month/day/year cannot be less than 1/1/0");
        if (month > 12 || day > 31)
            throw std::runtime_error("Overflow: month or year");
    }
public:
    Date() : m_month(0), m_day(0), m_year(0)
    {}
    Date(int month, int day, int year)
        : m_month(month), m_day(day), m_year(year)
    {
        check_date(month, day, year);
    }
    void get_date()
    {
        char chDiv;
        std::cout << "Enter date (mm/dd/yy): ";
        while (1)
        {
            std::cin >> m_month >> chDiv >> m_day >> chDiv >> m_year;
            std::cin.ignore(100, '\n');
            if (std::cin.fail())
            {
                std::cout << "Wrong input. Again: ";
                std::cin.clear();
                std::cin.ignore(100, '\n');
                continue;
            }
            check_date(m_month, m_day, m_year);
            break;
        }
    }

    void show_date() const
    {
        std::cout << std::setfill('0') << std::setw(2) << m_month << "/"
            << std::setw(2) << m_day << "/" << std::setw(2) << m_year << '\n';
    }
};

class Publication
{
private:
    std::string m_name;
    double m_cost;
public:
    Publication() : m_name("N/A"), m_cost(0)
    {}
    Publication(const std::string& name, double cost)
        : m_name(name), m_cost(cost)
    {
        if (cost < 0)
            throw std::runtime_error("Cost cannot be less than 0");
    }
    void get_data()
    {
        std::cout << "Enter a name of the book: ";
        m_name = get_user_string();
        std::cout << "Enter cost of the book: ";
        m_cost = get_more_than_zero();
    }
    void put_data() const
    {
        std::cout << "\nName: " << m_name << "\nCost: " << m_cost << '\n';
    }
};

class Publication2 : public Publication, private Date
{
public:
    Publication2() : Publication(), Date()
    {}
    Publication2(const std::string& name, double cost,
        int month, int day, int year)
        : Publication(name, cost), Date(month, day, year)
    {}

    void get_data()
    {
        Publication::get_data();
        Date::get_date();
    }
    void put_data() const
    {
        Publication::put_data();
        std::cout << "Publication's date: ";
        Date::show_date();
    }
};

class Book : public Publication2
{
private:
    int m_pages;
public:
    Book() : Publication2(), m_pages(0)
    {}
    Book(const std::string& name, double cost,
        int month, int day, int year, int pages)
        : Publication2(name, cost, month, day, year), m_pages(pages)
    {
        if (pages < 0)
            throw std::runtime_error("Pages cannot be less than 0");
    }

    void get_data()
    {
        Publication2::get_data();
        std::cout << "Enter an amount of pages: ";
        m_pages = get_more_than_zero();
    }
    void put_data() const
    {
        Publication2::put_data();
        std::cout << "Amount of pages: " << m_pages << '\n';
    }
};

class Tape : public Publication2
{
private:
    double m_lasting;
public:
    Tape() : Publication2(), m_lasting(0)
    {}
    Tape(const std::string& name, double cost,
        int month, int day, int year, double lasting)
        : Publication2(name, cost, month, day, year), m_lasting(lasting)
    {
        if (lasting < 0)
            throw std::runtime_error("Lasting cannot be less than 0");
    }

    void get_data()
    {
        Publication2::get_data();
        std::cout << "Enter lasting of the tape (min): ";
        m_lasting = get_more_than_zero();
    }
    void put_data() const
    {
        Publication2::put_data();
        std::cout << "Lasting (min): " << m_lasting << '\n';
    }

};

int main()
{
    try
    {
        Book bk("ABC", 123.5, 10, 10, 2001, 100);
        bk.put_data();
        Tape tp("XYZ", 120, 5, 7, 1800, 500);
        tp.put_data();

        std::cout << "Book:\n";
        Book book;
        book.get_data();
        Tape type;
        std::cout << "\nTape:\n";
        type.get_data();
        std::cout << "\nBook:";
        book.put_data();
        std::cout << "\nTape:";
        type.put_data();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what();
    }
}
