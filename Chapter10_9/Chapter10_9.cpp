#include <iostream>

int main()
{
    const int LIM = 10;
    int a0[LIM], a1[LIM], a2[LIM], a3[LIM], a4[LIM], a5[LIM], a6[LIM], a7[LIM], a8[LIM], a9[LIM];
    int* ap[] = {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9};

    int n = 1;
    for(int i = 0; i < LIM; i++)
        for (int j = 0; j < LIM; j++)
            ap[i][j] = n++;

    for (int i = 0; i < LIM; i++)
    {
        std::cout << "a[" << i << "]: ";
        for (int j = 0; j < LIM; j++)
        {
            std::cout << ap[i][j] << " ";
            if (j == LIM - 1)
                std::cout << '\n';
        }
    }
}
