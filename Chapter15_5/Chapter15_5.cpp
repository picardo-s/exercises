#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main()
{
    int int_arr[] = {3, 9, 5, 7, 1};
    std::sort(int_arr, int_arr + 5);

    std::set<int> set_int;
    std::vector<int> vect_int;

    for (int i = 2; i <= 10; i += 2)
        set_int.insert(i);

    std::merge(int_arr, int_arr + 5, set_int.begin(), set_int.end(), std::back_inserter(vect_int));

    for (int i = 0; i < vect_int.size(); i++)
        std::cout << vect_int[i] << " ";
}
