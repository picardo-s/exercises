#include <iostream>
#include <fstream>
#include <typeinfo>

const int LEN = 32;
const int MAXEM = 100;
enum employee_type {tmanager,
                    tscientist,
                    tlaborer};

class Employee
{
private:
    char m_name[LEN];
    unsigned long m_number;
    static int m_n;
    static Employee* m_arrap[];
public:
    virtual void getdata()
    {
        std::cin.ignore(100, '\n');
        std::cout << "\nEnter a name: ";
        std::cin >> m_name;
        std::cout << "Enter an ID: ";
        std::cin >> m_number;
    }
    virtual void putdata()
    {
        std::cout << "\nName: " << m_name;
        std::cout << "\nID: " << m_number;
    }
    virtual employee_type get_type();
    static void add();
    static void display();
    static void read();
    static void write();
    static void find(unsigned long);
};

int Employee::m_n;
Employee* Employee::m_arrap[MAXEM];

class Manager : public Employee
{
private:
    char m_title[LEN];
    double m_dues;
public:
    void getdata()
    {
        Employee::getdata();
        std::cout << "Enter a title: ";
        std::cin >> m_title;
        std::cout << "Enter dues: ";
        std::cin >> m_dues;
    }
    void putdata()
    {
        Employee::putdata();
        std::cout << "\nTitle: " << m_title;
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
    void putdata()
    {
        Employee::putdata();
        std::cout << "\nAmount of publications: " << m_pubs;
    }
};

class Laborer : public Employee
{

};

void Employee::add()
{
    char ch;
    std::cout << "\n'm' - add a manager"
        << "\n's' - add a scientist"
        << "\n'l' - add a laborer"
        << "\nYour choise: ";
    std::cin >> ch;
    switch (ch)
    {
    case 'm': m_arrap[m_n] = new Manager; break;
    case 's': m_arrap[m_n] = new Scientist; break;
    case 'l': m_arrap[m_n] = new Laborer; break;
    default: "\nWrong type\n"; return;
    }
    m_arrap[m_n++]->getdata();
}

void Employee::display()
{
    for (int i = 0; i < m_n; i++)
    {
        std::cout << (i + 1) << ". ";
        switch (m_arrap[i]->get_type())
        {
        case tmanager: std::cout << "Type: manager"; break;
        case tscientist: std::cout << "Type: scientist"; break;
        case tlaborer: std::cout << "Type: laborer"; break;
        default: std::cout << "Type: unknown";
        }
        m_arrap[i]->putdata();
        std::cout << '\n' << std::endl;
    }
}

employee_type Employee::get_type()
{
    if (typeid(*this) == typeid(Manager))
        return tmanager;
    else if (typeid(*this) == typeid(Scientist))
        return tscientist;
    else if (typeid(*this) == typeid(Laborer))
        return tlaborer;
    else
    {
        std::cerr << "Wrong employee type";
        std::exit(1);
    }
    return tmanager;
}

void Employee::write()
{
    int size;
    std::cout << "Writing...(" << m_n << " employers).\n";
    std::ofstream ouf;
    employee_type etype;

    ouf.open("S:/perfect_circle/Chapter12_12/EMPLOY.DAT", std::ios::trunc | std::ios::binary);
    if (!ouf)
    {
        std::cout << "\nCan't open the file\n";
        return;
    }
    for (int j = 0; j < m_n; j++)
    {
        etype = m_arrap[j]->get_type();
        ouf.write((char*)&etype, sizeof(etype));
        switch (etype)
        {
        case tmanager: size = sizeof(Manager); break;
        case tscientist: size = sizeof(Scientist); break;
        case tlaborer: size = sizeof(Laborer); break;
        }
        ouf.write((char*)(m_arrap[j]), size);
        if (!ouf)
        {
            std::cout << "\nCan't open the file\n";
            return;
        }
    }
}
void Employee::read()
{
    int size;
    employee_type etype;
    std::ifstream inf;
    inf.open("S:/perfect_circle/Chapter12_12/EMPLOY.DAT", std::ios::binary);
    if (!inf)
    {
        std::cout << "\nCan't open the file\n";
        return;
    }
    m_n = 0;
    while (true)
    {
        inf.read((char*)&etype, sizeof(etype));
        if (inf.eof())
            break;
        if (!inf)
        {
            std::cout << "\nCan't read the file\n";
            return;
        }
        switch (etype)
        {
        case tmanager:
            m_arrap[m_n] = new Manager;
            size = sizeof(Manager);
            break;
        case tscientist:
            m_arrap[m_n] = new Scientist;
            size = sizeof(Scientist);
            break;
        case tlaborer:
            m_arrap[m_n] = new Laborer;
            size = sizeof(Laborer);
            break;
        default: 
            std::cout << "\nWrong type in file\n"; return;
        }
        inf.read((char*)(m_arrap[m_n]), size);
        if (!inf)
        {
            std::cout << "\nReading is disable\n";
            return;
        }
        m_n++;
    }
    std::cout << "Reading...(" << m_n << " employers).\n";
}

void Employee::find(unsigned long num)
{
    int size;
    employee_type etype;
    std::ifstream inf;
    Employee* find_empl;
    inf.open("S:/perfect_circle/Chapter12_12/EMPLOY.DAT", std::ios::binary);
    if (!inf)
    {
        std::cout << "\nCan't open the file\n";
        return;
    }
    while (true)
    {
        inf.read((char*)&etype, sizeof(etype));
        if (inf.eof())
            break;
        if (!inf)
        {
            std::cout << "\nCan't read the file\n";
            return;
        }
        switch (etype)
        {
        case tmanager:
            find_empl = new Manager;
            size = sizeof(Manager);
            break;
        case tscientist:
            find_empl = new Scientist;
            size = sizeof(Scientist);
            break;
        case tlaborer:
            find_empl = new Laborer;
            size = sizeof(Laborer);
            break;
        default:
            std::cout << "\nWrong type in file\n"; return;
        }
        inf.read((char*)(find_empl), size);
        if (!inf)
        {
            std::cout << "\nReading is disable\n";
            return;
        }
        if (num == find_empl->m_number)
        {
            switch (etype)
            {
            case tmanager: std::cout << "Type: manager"; break;
            case tscientist: std::cout << "Type: scientist"; break;
            case tlaborer: std::cout << "Type: laborer"; break;
            default: std::cout << "Type: unknown";
            }
            find_empl->putdata();
            std::cout << '\n';
            delete find_empl;
            return;
        }
        delete find_empl;
    }
    std::cout << "The id \'" << num << "\' was not found.\n";
}


int main()
{
    char ch;
    unsigned long id;
    while (true)
    {
        std::cout << "\n'a' - add data"
            << "\n'd' - display data"
            << "\n'w' - write data"
            << "\n'r' - read data"
            << "\n'f' - find employee"
            << "\n'x' - exit"
            << "\nYour choise: ";
        std::cin >> ch;
        switch (ch)
        {
        case 'a': Employee::add(); break;
        case 'd': Employee::display(); break;
        case 'w': Employee::write(); break;
        case 'r': Employee::read(); break;
        case 'f': 
            std::cout << "\nEnter an id for searching: ";
            std::cin >> id;
            Employee::find(id);
            break;
        case 'x': std::exit(0);
        default: std::cout << "\n--Wrong command--\n";
        }
    }
}
