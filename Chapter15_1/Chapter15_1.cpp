#include <iostream>
#include <algorithm>
#include <vector>

float get_flt_num()
{
    float temp;
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

constexpr int MAX = 100;

int main()
{
    float flt_arr[MAX];
    int i = 0;
    char manip;

    do
    {
        std::cout << "Enter a float number: ";
        flt_arr[i++] = get_flt_num();
        std::cout << "Continue?(y/n): ";
        std::cin >> manip;
        std::cin.ignore(1000, '\n');
    } while (manip != 'n' && i < MAX);

    std::sort(flt_arr, flt_arr + i);

    for (int j = 0; j < i; j++)
        std::cout << flt_arr[j] << " ";
}


//int main()
//{
//    std::vector<float> flt_vect;
//    char manip;
//
//    do
//    {
//        std::cout << "Enter a float number: ";
//        flt_vect.push_back(get_flt_num());
//        std::cout << "Continue?(y/n): ";
//        std::cin >> manip;
//        std::cin.ignore(1000, '\n');
//    } while (manip != 'n');
//
//    sort(flt_vect.begin(), flt_vect.end());
//
//    std::vector<float>::iterator iter = flt_vect.begin();
//    while (iter != flt_vect.end())
//        std::cout << *iter++ << " ";
//}