#include <iostream>

int main()
{
    int height = 20;
    int width = height + height - 1;

    for (int i = 1, j = height; i <= width; i += 2, j--)
    {
        for (int k = 1, m = i; k <= width; k++)
        {
            if (k != j)
                std::cout << " ";
            else
                while (m--)
                {
                    std::cout << "X";
                    k++;
                }
        }
        std::cout << '\n';
    }
}

