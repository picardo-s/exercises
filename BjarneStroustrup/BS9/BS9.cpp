#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template<class T>
T get_user_number()
{
    T temp;
    std::cin >> temp;
    std::cin.ignore(1000, '\n');
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        throw std::runtime_error("Wrong input\n");
    }
    return temp;
}

std::string get_user_string()
{
    std::string temp;
    std::getline(std::cin, temp);
    return temp;
}

using std::vector;
using std::string;

//Exercise 2 -----------------------------------------------

const string STOP_WORD{ "stop" };

class Name_pairs
{
private:
    vector<string> name{};
    vector<double> age{};
    int find_name(const vector<string>&, const string&);
public:
    void read_names();
    void read_ages();
    //void print() const;
    void sort();
    std::ostream& operator<<(std::ostream&, const Name_pairs&);
};

void Name_pairs::read_names()
{
    string temp{};
    std::cout << "Enter names (\'" << STOP_WORD << "\' to stop entering): ";
    while (1)
    {
        temp = get_user_string();
        if (temp == STOP_WORD)
            break;
        name.push_back(temp);
    }
}

void Name_pairs::read_ages()
{
    static int current_name_iter{ 0 };
    int names_left{ static_cast<int>(name.size() - age.size()) };
    if (names_left == 0)
        throw std::runtime_error("read_ages: There is no initialized names");

    while (names_left--)
    {
        std::cout << "Enter age for \'" << name[current_name_iter] << "\': ";
        age.push_back(get_user_number<double>());
        current_name_iter++;
        if(names_left)
            std::cout << names_left << " name(s) left\n";
    }
}

//void Name_pairs::print() const
//{
//    if (name.size() == 0)
//        throw std::runtime_error("print: Vector of names is empty");
//
//    for (unsigned int i = 0; i < name.size(); i++)
//    {
//        std::cout << "(" << name[i] << ", ";
//        if (i < age.size())
//            std::cout << age[i];
//        else std::cout << "N/A";
//        std::cout << ")\n";
//    }
//}

int Name_pairs::find_name(const vector<string>& v_str, const string& str)
{
    for (int i = 0; i < v_str.size(); i++)
        if (str == v_str[i])
            return i;
    return -1;
}

void Name_pairs::sort()
{
    if (name.size() != age.size())
        throw std::runtime_error("sort: Vector of names' size doesn't match vector of age's one");

    std::vector<std::string> name_copy{ name };
    std::vector<double> age_copy{ age };
    std::sort(name.begin(), name.end());

    for (int i = 0; i < name.size(); i++)
        age[i] = name[i] == name_copy[i] ? age_copy[i] : age_copy[find_name(name_copy, name[i])];
}

std::ostream& Name_pairs::operator<<(std::ostream& os, const Name_pairs& np)
{
        if (name.size() == 0)
            throw std::runtime_error("print: Vector of names is empty");
    
        for (unsigned int i = 0; i < name.size(); i++)
        {
            std::cout << "(" << name[i] << ", ";
            if (i < age.size())
                std::cout << age[i];
            else std::cout << "N/A";
            std::cout << ")\n";
        }
}

int main()
{
    try
    {
        Name_pairs np{};
        np.read_names();
        np.read_ages();
        np.read_names();
        np.sort();
        np.print();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what();
    }
}
