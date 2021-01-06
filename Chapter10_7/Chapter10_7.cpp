#include <iostream>

class Person
{
protected:
    std::string m_name;
    float m_salary;
public:
    void setData()
    {
        std::cout << "Enter the name: ";
        std::cin >> m_name;
        std::cout << "Enter the salary: ";
        std::cin >> m_salary;
    }

    void printData()
    {
        std::cout << "\n\nName: " << m_name;
        std::cout << "\nSalary: " << m_salary;
    }

    std::string getName()
    {
        return m_name;
    }

    float getSalary()
    {
        return m_salary;
    }
};

void salSort(Person** pers, const int len);

int main()
{
    Person* persPtr[100];
    int n = 0;
    char manip;

    do
    {
        persPtr[n] = new Person;
        persPtr[n]->setData();
        n++;
        std::cout << "Continue?(y/n): ";
        std::cin >> manip;
    } while (manip == 'y');

    std::cout << "\nUnsorted array: ";
    for (int i = 0; i < n; i++)
        persPtr[i]->printData();

    salSort(persPtr, n);

    std::cout << "\n\nSorted array: ";
    for (int i = 0; i < n; i++)
        persPtr[i]->printData();
}

void salSort(Person** pers, const int len)
{
    int j, k;
    for(j = 0; j < len - 1; j++)
        for(k = j + 1; k < len; k++)
            if ((*(pers + j))->getSalary() > (*(pers + k))->getSalary())
            {
                Person* temp = *(pers + j);
                *(pers + j) = *(pers + k);
                *(pers + k) = temp;
            }
}