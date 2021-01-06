#include <iostream>
#include <fstream>
#include <string>

class Name
{
private:
    std::string m_firstName;
    std::string m_middleInit;
    std::string m_lastName;
    unsigned long m_id;
public:
    void get_data()
    {
        std::cout << "\nEnter name: ";
        std::cin >> m_firstName;
        std::cout << "Enter middle initial: ";
        std::cin >> m_middleInit;
        std::cout << "Enter surname: ";
        std::cin >> m_lastName;
        std::cout << "Enter ID: ";
        std::cin >> m_id;
        std::ofstream outFile("S:/perfect_circle/Chapter12_6/namedata.txt", std::ios::app);
        outFile << m_firstName << " " << m_middleInit << " " << m_lastName << " " << m_id;
        outFile.close();
    }

    void put_data()
    {
        std::ifstream inFile("S:/perfect_circle/Chapter12_6/namedata.txt");
        while (!inFile.eof())
        {
            inFile >> m_firstName >> m_middleInit >> m_lastName >> m_id;
            std::cout << "\nName: " << m_firstName << std::endl
                << "Middle initial: " << m_middleInit << std::endl
                << "Surname: " << m_lastName << std::endl
                << "ID: " << m_id << std::endl;
        }
        inFile.close();
    }

    void put_data(std::string& str)
    {
        std::ifstream inFile("S:/perfect_circle/Chapter12_6/namedata.txt");
        std::cout << "\nThe results of searching by \"" << str << "\": \n";
        while (!inFile.eof())
        {
            inFile >> m_firstName >> m_middleInit >> m_lastName >> m_id;
            if (str == m_firstName || str == m_middleInit || str ==m_lastName)
            {
                std::cout << "\nName: " << m_firstName << std::endl
                    << "Middle initial: " << m_middleInit << std::endl
                    << "Surname: " << m_lastName << std::endl
                    << "ID: " << m_id << std::endl;
            }
        }
        std::cout << std::endl;
        inFile.close();
    }

    void put_data(unsigned long id)
    {
        std::ifstream inFile("S:/perfect_circle/Chapter12_6/namedata.txt");
        std::cout << "\nThe results of searching by \"" << id << "\": \n";
        while (!inFile.eof())
        {
            inFile >> m_firstName >>m_middleInit >> m_lastName >> m_id;
            if (id == m_id)
            {
                std::cout << "\nName: " << m_firstName << std::endl
                    << "Middle initial: " << m_middleInit << std::endl
                    << "Surname: " << m_lastName << std::endl
                    << "ID: " << m_id << std::endl;
            }
        }
        std::cout << std::endl;
        inFile.close();
    }

};

int main()
{
    Name name;
    char manip;

    do
    {
        std::cout << "\n\'e\' - enter data\n" <<
            "\'p\' - print data\n" <<
            "\'n\' - search by name\n" <<
            "\'i\' - search by id\n" <<
            "\'x\' - exit\n" <<
            "Yor choise: ";
        std::cin >> manip;
        switch (manip)
        {
            case 'e': name.get_data(); break;
            case 'p': name.put_data(); break;
            case 'n':
            {
                 std::string str;
                 std::cout << "\nEnter a name for searching: ";
                 std::cin >> str;
                 name.put_data(str);
                 break;
            }
            case 'i':
            {
                unsigned long id;
                std::cout << "\nEnter an id for searching: ";
                std::cin >> id;
                name.put_data(id);
                break;
            }
            case 'x': std::exit(0); break;
            default: 
                std::cout << "Wrong type!\n";
        }
        std::cout << "Continue?(y/n): ";
        std::cin.ignore(100, '\n');
        std::cin >> manip;
    } while (manip == 'y');
}
