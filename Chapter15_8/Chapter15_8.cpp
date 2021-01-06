#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

int get_int()
{
    int num;
    while (1)
    {
        std::cin >> num;
        std::cin.ignore(1000, '\n');
        if (std::cin.fail())
        {
            std::cout << "Wrong input.\nAgain: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        return num;
    }
}

int get_user_choise(int bottom, int top)
{
    int num;
    while (1)
    {
        num = get_int();
        if (num < bottom || num > top)
        {
            std::cout << "Wrong number.\nAgain: ";
            continue;
        }
        return num;
    }
}

int main()
{
    char manip;
    int begin, end, position;
    std::deque<int> int_deq;
    
    do
    {
        std::cout << "Enter an integer: ";
        int_deq.push_back(get_int());
        std::cout << "Continue?(y/n): ";
        std::cin >> manip;
        std::cin.ignore(1000, '\n');
    } while (manip != 'n');

    std::cout << "\nEnter a range to copy.\nBeginning position (from 1 to "
        << int_deq.size() << "): ";
    begin = get_user_choise(1, int_deq.size());

    std::cout << "\nEnding position (from " << begin << " to " << int_deq.size() << "): ";
    end = get_user_choise(begin, int_deq.size());

    std::cout << "\nPosition to insert the range (from 1 to "
        << int_deq.size() << "): ";
    position = get_user_choise(1, int_deq.size());

    std::deque<int>::iterator iter1 = int_deq.begin() + (begin - 1);
    std::deque<int>::iterator iter2 = int_deq.begin() + end;

    std::copy(iter1, iter2, std::inserter(int_deq, int_deq.begin() + (position - 1)));
    //std::copy_backward(iter1, iter2, int_deq.end())

    std::cout << "Result: ";
    for (int i = 0; i < int_deq.size(); i++)
        std::cout << int_deq[i] << " ";
}
