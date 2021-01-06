#include <iostream>
#include <fstream>
#include <string>

const int MAX = 100;

class Name
{
private:
    std::string m_firstName;
    std::string m_middleInit;
    std::string m_lastName;
    unsigned long m_id;
    static std::fstream m_file;
public:
    static void open_stream()
    {
        if (!m_file.is_open())
        {
            m_file.open("S:/perfect_circle/Chapter12_6/namedata.txt", std::ios::in | std::ios::out | std::ios::app);
        }
    }
    static void reset_file_pointer()
    {
        m_file.seekg(0);
    }

    void get_data()
    {
        if (!m_file.is_open())
        {
            std::cout << "\nThere is no associated file. Open the stream if You haven't done it\n";
            return;
        }
        std::cout << "\nEnter name: ";
        std::cin >> m_firstName;
        std::cout << "Enter middle initial: ";
        std::cin >> m_middleInit;
        std::cout << "Enter surname: ";
        std::cin >> m_lastName;
        std::cout << "Enter ID: ";
        std::cin >> m_id;
        m_file.seekg(0, std::ios::end);
        m_file << m_firstName << " " << m_middleInit << " " << m_lastName << " " << m_id;
    }

    void put_data()
    {
        if (!m_file.is_open())
        {
            std::cout << "\nThere is no associated file. Open the stream if You haven't done it\n";
            return;
        }
        Name::reset_file_pointer();
        while (!m_file.eof())
        {
            m_file >> m_firstName >> m_middleInit >> m_lastName >> m_id;
            std::cout << "\nName: " << m_firstName << std::endl
                << "Middle initial: " << m_middleInit << std::endl
                << "Surname: " << m_lastName << std::endl
                << "ID: " << m_id << std::endl;
        }
    }

    void put_data(std::string& str)
    {
        if (!m_file.is_open())
        {
            std::cout << "\nThere is no associated file. Open the stream if You haven't done it\n";
            return;
        }
        Name::reset_file_pointer();
        std::cout << "\nThe results of searching by \"" << str << "\": \n";
        while (!m_file.eof())
        {
            m_file >> m_firstName >> m_middleInit >> m_lastName >> m_id;
            if (str == m_firstName || str == m_middleInit || str == m_lastName)
            {
                std::cout << "\nName: " << m_firstName << std::endl
                    << "Middle initial: " << m_middleInit << std::endl
                    << "Surname: " << m_lastName << std::endl
                    << "ID: " << m_id << std::endl;
            }
        }
    }

    void put_data(unsigned long id)
    {
        if (!m_file.is_open())
        {
            std::cout << "\nThere is no associated file. Open the stream if You haven't done it\n";
            return;
        }
        Name::reset_file_pointer();
        std::cout << "\nThe results of searching by \"" << id << "\": \n";
        while (!m_file.eof())
        {
            m_file >> m_firstName >> m_middleInit >> m_lastName >> m_id;
            if (id == m_id)
            {
                std::cout << "\nName: " << m_firstName << std::endl
                    << "Middle initial: " << m_middleInit << std::endl
                    << "Surname: " << m_lastName << std::endl
                    << "ID: " << m_id << std::endl;
            }
        }
    }
};

std::fstream Name::m_file;

int main()
{
    Name name;
    char manip;
    name.open_stream();
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

