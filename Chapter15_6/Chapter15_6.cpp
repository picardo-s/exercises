#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vect_int;
    for (int i = 1; i < 19; i++)
    {
        vect_int.push_back(i);
        std::cout << vect_int[i - 1] << " ";
    }

    std::vector<int>::iterator iter = vect_int.begin();
    std::vector<int>::reverse_iterator rev_iter = vect_int.rbegin();

    int i = 0;
    while (i++ <= (vect_int.size() / 2))
        std::swap(*(iter++), *(rev_iter++));

    std::cout << "\nReversed:\n";
    iter = vect_int.begin();
    while (iter != vect_int.end())
        std::cout << *iter++ << " ";
}
