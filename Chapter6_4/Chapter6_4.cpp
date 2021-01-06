#include <iostream>

class Employee
{
private:
    int m_id;
    float m_salary;
public:
    Employee() : m_id(0), m_salary(0)
    {}

    void enter()
    {
        std::cout << "Enter the id: ";
        std::cin >> m_id;
        std::cout << "Enter an amount of the salary: ";
        std::cin >> m_salary;
    }

    void display() const
    {
        std::cout << "\nID: " << m_id << "\nSalary: " << m_salary << '\n';
    }
};

int main()
{
    Employee emp1, emp2, emp3;
    emp1.enter();
    emp2.enter();
    emp3.enter();

    std::cout << "\nEmployee #1: ";
    emp1.display();
    std::cout << "Employee #2: ";
    emp2.display();
    std::cout << "Employee #3: ";
    emp3.display();
}
