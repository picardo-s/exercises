#include <iostream>
#include <list>
#include <algorithm>

int get_int_num()
{
    int temp;
    while (1)
    {
        std::cin >> temp;
        if (std::cin.fail())
        {
            std::cout << "Wrong input.\nAgain: ";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else break;
    }
    std::cin.ignore(100, '\n');
    return temp;

}

void print_list(std::list<int>& list, std::list<int>::iterator& iter)
{
    iter = list.begin();
    while (iter != list.end())
        std::cout << *iter++ << " ";
}

int main()
{
    std::list<int> int_list;
    char manip;

    do
    {
        std::cout << "Enter an integer: ";
        int_list.push_back(get_int_num());
        std::cout << "Continue?(y/n): ";
        std::cin >> manip;
        std::cin.ignore(1000, '\n');
    } while (manip != 'n');

    std::list<int>::iterator asc_iter;
    std::list<int>::iterator desc_iter;

    std::cout << "\nBefore reversing:\n";
    print_list(int_list, asc_iter);

    asc_iter = int_list.begin();
    desc_iter = int_list.end();
    --desc_iter;
    int list_count = int_list.size();

    while (asc_iter != desc_iter && (int_list.size() / 2) < list_count--)
        std::swap(*(asc_iter++), *(desc_iter--));

    std::cout << "\nAfter reversing:\n";
    print_list(int_list, asc_iter);
}
