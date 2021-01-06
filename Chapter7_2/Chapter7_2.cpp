#include <iostream>
#include <string>

class Employee
{
private:
    std::string m_name;
    long m_id;
public:
    void getdata()
    {
        std::cout << "\nEnter a name: ";
        std::cin >> m_name;  //According to Russian-language book std::getline(std::cin, m_name) have to be here. But it works incorrectly. There is something wrong with CIN
        std::cout << "Enter an id: ";
        std::cin >> m_id;
    }
    void putdata() const
    {
        std::cout << "\nName: " << m_name << "\nID: " << m_id << '\n';
    }
};

int main()
{
    const int MAX = 100;
    Employee empArr[MAX];
    char manip = 'a';
    int count = 0;
    do
    {
        std::cout << "Employee #" << count + 1;
        empArr[count++].getdata();
        std::cout << "Continue?(y/n): ";
        std::cin >> manip;
        std::cout << '\n';
    } while ((manip != 'n') && (count < MAX));

    for (int i = 0; i < count; i++)
    {
        std::cout << "Employee #" << i + 1 << ":";
        empArr[i].putdata();
        std::cout << '\n';
    }

}
