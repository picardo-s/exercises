#include <iostream>
#include <fstream>
#include <string>

struct Link
{
    int data;
    Link* next;
};

class LinkList
{
private:
    Link* m_first;
    std::string path;
    void deleteData() const;
    void checkFilePath() const;
public:
    LinkList(const std::string& file_path = "non") 
        : m_first{nullptr}, path{file_path}
    {}
    ~LinkList()
    {
        deleteData();
    }
    void additem(int d);
    void display() const;
    void writeData() const;
    void readData();
    void setFilePath(const std::string&);
    std::string getFilePath() const;
};

void LinkList::deleteData() const
{
    Link* current = m_first;
    Link* next = m_first->next;
    while (1)
    {
        delete current;
        current = next;
        if (current == nullptr)
            break;
        next = next->next;
    }
}

void LinkList::checkFilePath() const
{
    static const std::string format{ ".txt" };
    bool err_flag{ false };

    if (path.size() < (format.size() + 1))
        err_flag = true;

    if (!err_flag)
    {
        std::string curr_format{};
        for (unsigned int i{ path.size() - format.size() }; i < path.size(); i++)
            curr_format += path[i];
        if (curr_format != format)
            err_flag = true;
    }
    if (err_flag)
        throw std::runtime_error("Wrong file's format. \'.txt\' is expected");
}

void LinkList::additem(int d)
{
    Link* newLink = new Link;
    newLink->data = d;
    newLink->next = m_first;
    m_first = newLink;
}

void LinkList::display() const
{
    Link* current = m_first;
    if (current == nullptr)
        std::cout << "No data. Empty list";
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void LinkList::writeData() const
{
    checkFilePath();
    Link* current = m_first;
    if (current == nullptr)
    {
        std::cout << "There is no data to write\n";
        return;
    }
    std::ofstream outFile(path, std::ios::trunc);
    while (current)
    {
        outFile << current->data << '\n';
        current = current->next;
    }
    if (outFile.fail())
        throw std::runtime_error("FAIL! Cannot write the file");
    else
        std::cout << "Succsessfully wrote\n";
}

void LinkList::readData()
{
    checkFilePath();
    if (m_first != nullptr)
        deleteData();
    m_first = nullptr;

    int tempBuff{};

    std::ifstream inFile(path, std::ios::_Nocreate);
    while (inFile >> tempBuff)
    {
        if (!m_first)
        {
            m_first = new Link;
            m_first->data = tempBuff;
            m_first->next = nullptr;
        }
        else
        {
            Link* temp = m_first;
            while (temp->next)
                temp = temp->next;

            Link* newLink = new Link;
            newLink->data = tempBuff;
            newLink->next = nullptr;
            temp->next = newLink;
        }
    }
    if(inFile.eof())
        std::cout << "Succsessfully read\n";
    else
        throw std::runtime_error("FAIL! Cannot read the file");
}

void LinkList::setFilePath(const std::string& file_path)
{
    path = file_path;
}

std::string LinkList::getFilePath() const
{
    return path;
}

char get_user_char()
{
    char temp{}, ch{};
    std::cin >> temp;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return temp;
}

int get_user_integer()
{
    int temp{};
    while (true)
    {
        std::cin >> temp;
        if (!std::cin)
        {
            std::cout << "Wrong input. Again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else return temp;
    }
}

std::string get_user_string()
{
    std::string temp{};
    std::getline(std::cin, temp);
    return temp;
}

int main()
{
    LinkList lst;
    char manip{};
    std::cout << "\n\'a\' - add new data\n"
        << "\'p\' - print current data\n"
        << "\'f\' - set/change file path\n"
        << "\'w\' - write current data into the file\n"
        << "\'r\' - read data from the file\n"
        << "\'x\' - exit\n";
        do
        {
            try {

                std::cout << ">: ";
                manip = get_user_char();
                switch (manip)
                {
                case 'a':
                {
                    std::cout << "Enter an integer: ";
                    lst.additem(get_user_integer()); break;
                }
                case 'p': lst.display(); break;
                case 'f': 
                    std::cout << "Enter file path (*.txt): ";
                    lst.setFilePath(get_user_string()); break;
                case 'w': lst.writeData(); break;
                case 'r': lst.readData(); break;
                case 'x': std::exit(0); break;
                default: std::cout << "Wrong letter\n";
                }
            }
            catch (std::exception& e)
            {
                std::cout << "Exception!" << e.what() << '\n';
            }
        } while (manip != 'x');
}
