#include <iostream>
#include <set>
#include <algorithm>
#include <functional>

inline void enter_string(std::string& str);

int main()
{
    char manip;
    std::string name;
    std::set<std::string> name_set;

    do
    {
        std::cout << "Enter a name: ";
        enter_string(name);
        name_set.insert(name);
        std::cout << "Continue?(y/n): ";
        std::cin >> manip;
        std::cin.ignore(1000, '\n');
    } while (manip != 'n');

    std::set<std::string>::iterator search_iter;

    std::cout << "Enter a name for searching: ";
    enter_string(name);

    search_iter = std::find_if(name_set.begin(), name_set.end(), std::bind1st(std::equal_to<std::string>(), name));

    if (search_iter == name_set.end())
        std::cout << "The name \'" << name << "\' was not found";
    else
    {
        int i = 0;
        std::set<std::string>::iterator count_iter = name_set.begin();
        while (search_iter != count_iter++)
            i++;
        std::cout << "The name \'" << name << "\' was found at " << i;
    }
}

inline void enter_string(std::string& str)
{
    std::cin >> str;
    std::cin.ignore(1000, '\n');
}