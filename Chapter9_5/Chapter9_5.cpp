#include <iostream>

const int LEN = 80;

class Employee
{
private:
    char m_name[LEN];
    unsigned long m_number;
public:
    void getdata()
    {
        std::cout << "Enter the surname: ";
        std::cin >> std::ws;
        std::cin.get(m_name, LEN);
        std::cout << "\Enter the ID: ";
        std::cin >> m_number;
    }
    void putdata() const
    {
        std::cout << "\nSurname: " << m_name;
        std::cout << "\nID: " << m_number;
    }
};

class Manager : public Employee
{
private:
    char m_title[LEN];
    double m_dues;
public:
    void getdata()
    {
        Employee::getdata();
        std::cout << "Enter the position: ";
        std::cin >> std::ws;
        std::cin.get(m_title, LEN);
        std::cout << "Enter the golf club dues: ";
        std::cin >> m_dues;
    }
    void putdata()
    {
        Employee::putdata();
        std::cout << "\nPosition: " << m_title;
        std::cout << "\nDues: " << m_dues;
    }
};

class Scientist : public Employee
{
private:
    int m_pubs;
public:
    void getdata()
    {
        Employee::getdata();
        std::cout << "Enter an amount of publications: ";
        std::cin >> m_pubs;
    }
    void putdata() const
    {
        Employee::putdata();
        std::cout << "\nPublications: " << m_pubs;
    }
};

class Laborer : public Employee
{

};

class Compensation
{
private:
    enum period { hour, week, month, n };
    double m_comp;
    period m_per;
public:
    void getdata()
    {
        char paym;
        std::cout << "Enter the type of payment period (h - hour, w - week, m - month): ";
        std::cin >> paym;
        switch (paym)
        {
            case 'h': m_per = hour; break;
            case 'w': m_per = week; break;
            case 'm': m_per = month; break;
            default: m_per = n;
        }
        std::cout << "Enter the compensation: ";
        std::cin >> m_comp;
    }

    void putdata()
    {
        std::cout << "\nCompensation: " << m_comp << " per ";
        switch (m_per)
        {
            case hour: std::cout << "hour\n"; break;
            case week: std::cout << "week\n"; break;
            case month: std::cout << "month\n"; break;
            default: std::cout << "-none-\n";
        }
    }
};

class Manager2 : public Manager, public Compensation
{
public:
    void getdata()
    {
        Manager::getdata();
        Compensation::getdata();
    }
    void putdata()
    {
        Manager::putdata();
        Compensation::putdata();
    }
};

class Scientist2 : public Scientist, public Compensation
{
public:
    void getdata()
    {
        Scientist::getdata();
        Compensation::getdata();
    }
    void putdata()
    {
        Scientist::putdata();
        Compensation::putdata();
    }
};

class Laborer2 : public Laborer, public Compensation
{
public:
    void getdata()
    {
        Laborer::getdata();
        Compensation::getdata();
    }
    void putdata()
    {
        Laborer::putdata();
        Compensation::putdata();
    }
};

int main()
{
    Manager2 mng;
    std::cout << "Manager:\n";
    mng.getdata();

    Scientist2 sct;
    std::cout << "\nScientist:\n";
    sct.getdata();

    Laborer2 lbr;
    std::cout << "\nLaborer:\n";
    lbr.getdata();

    std::cout << "\nManager:\n";
    mng.putdata();
    std::cout << "\nScientist:\n";
    sct.putdata();
    std::cout << "\nLaborer:\n";
    lbr.putdata();
}

