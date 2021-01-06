#include <iostream>
struct Employee
{
    int id;
    float salary;
};

int main()
{
    Employee emp1, emp2, emp3;

    std::cout << "Enter information (id, salary) about Your employees.\n";
    std::cout << "#1: ";
    std::cin >> emp1.id >> emp1.salary;
    std::cout << "#2: ";
    std::cin >> emp2.id >> emp2.salary;
    std::cout << "#3: ";
    std::cin >> emp3.id >> emp3.salary;
    std::cout << "Employee #1: id - " << emp1.id << ", salary - " << emp1.salary << '\n'
        << "Employee #2: id - " << emp2.id << ", salary - " << emp2.salary << '\n'
        << "Employee #3: id - " << emp3.id << ", salary - " << emp3.salary << '\n';
        
}
