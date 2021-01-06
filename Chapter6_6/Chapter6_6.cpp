#include <iostream>
#include <iomanip>

enum etype {
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};

class Date
{
private:
    int m_month;
    int m_day;
    int m_year;
public:
    Date() : m_month(0), m_day(0), m_year(0)
    {}

    void getDate(int month, int day, int year)
    {
        m_month = month;
        m_day = day;
        m_year = year;
    }

    void showDate() const
    {
        std::cout << std::setfill('0') << "Employment date: " << std::setw(2) << m_month << "/"
            << std::setw(2) << m_day << "/" << std::setw(2) << m_year << '\n';
    }
};

class Employee
{
private:
    int m_id;
    float m_salary;
    Date m_emplDate;
    etype m_position;
public:
    void getEmploy();
    void putEmploy();
};

void Employee::getEmploy()
{
    char letter;
    int month, day, year;

    std::cout << "Enter the id: ";
    std::cin >> m_id;
    std::cout << "Enter an amount of the salary: ";
    std::cin >> m_salary;

    std::cout << "Enter the employment date (mm dd yy): ";
    std::cin >> month >> day >> year;
    m_emplDate.getDate(month, day, year);

    std::cout << "Enter the first letter of any position \n"
        << "(laborer, secretary, manager, accountant, executive, researcher):";
    std::cin >> letter;
    std::cout << '\n';
    switch (letter)
    {
    case 'l': m_position = etype::laborer; break;
    case 's': m_position = etype::secretary; break;
    case 'm': m_position = etype::manager; break;
    case 'a': m_position = etype::accountant; break;
    case 'e': m_position = etype::executive; break;
    case 'r': m_position = etype::researcher; break;
    }
}

void Employee::putEmploy()
{
    std::cout << "\n\nID: " << m_id << "\nSalary: " << m_salary << '\n';
    m_emplDate.showDate();
    std::cout << "Position: ";
    switch(m_position)
    {
    case etype::laborer: std::cout << "laborer"; break;
    case etype::secretary: std::cout << "secretary"; break;
    case etype::manager: std::cout << "manager"; break;
    case etype::accountant: std::cout << "accountant"; break;
    case etype::executive: std::cout << "executive"; break;
    case etype::researcher: std::cout << "researcher"; break;
    default: std::cout << "-";
    }
}

int main()
{
    Employee emp1, emp2, emp3;
    emp1.getEmploy();
    emp2.getEmploy();
    emp3.getEmploy();

    emp1.putEmploy();
    emp2.putEmploy();
    emp3.putEmploy();
}