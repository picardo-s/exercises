#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string get_string()
{
    std::string temp;
    std::cin >> temp;
    std::cin.ignore(1000, '\n');
    return temp;
}

int main()
{
    std::vector<std::string> str_vect;
    char manip;

    do
    {
        std::cout << "Enter a word: ";
        str_vect.push_back(get_string());
        std::cout << "Continue?(y/n): ";
        std::cin >> manip;
        std::cin.ignore(1000, '\n');
    } while (manip != 'n');

    std::sort(str_vect.begin(), str_vect.end());

    for (int i = 0; i < str_vect.size(); i++)
        std::cout << str_vect[i] << " ";
}

