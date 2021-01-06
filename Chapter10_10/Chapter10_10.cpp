#include <iostream>

int main()
{
    const int LIM = 10;
    int* ap[LIM];

    int n = 1;
    for (int i = 0; i < LIM; i++)
    {
        *(ap + i) = new int[LIM];
        for (int j = 0; j < LIM; j++)
            *(*(ap + i) + j) = n++;
    }

    for (int i = 0; i < LIM; i++)
    {
        std::cout << "a[" << i << "]: ";
        for (int j = 0; j < LIM; j++)
        {
            std::cout << *(*(ap + i) + j) << " ";
            if (j == LIM - 1)
                std::cout << '\n';
        }
    }
}
