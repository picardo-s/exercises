#include <iostream>

class TenArray
{
private:
    static const int LIM = 10;
    int* m_arr[LIM];
public:
    TenArray(const int default_num = 0)
    {
        for (int i = 0; i < LIM; i++)
        {
            *(m_arr + i) = new int[LIM];
            for (int j = 0; j < LIM; j++)
                *(*(m_arr + i) + j) = default_num;
        }
    }
    ~TenArray()
    {
        for (int i = 0; i < LIM; i++)
        {
            delete[] *(m_arr + i);
            std::cout << "\n--Deleted--";
        }
    }
    int& operator[](int n)
    {
        if (n < 0 || n >= LIM * LIM)
            throw std::runtime_error("Out of bounds");

        int a = n / LIM;
        int b = n - (a * LIM);
        return *(*(m_arr + a) + b);
    }
    const int& operator[](int n) const
    {
        if (n < 0 || n >= LIM * LIM)
            throw std::runtime_error("Out of bounds");

        int a = n / LIM;
        int b = n - (a * LIM);
        return *(*(m_arr + a) + b);
    }
};

int main()
{
    try
    {
        TenArray ta;
        
        int n = 0;
        for (int i = 0; i < 100; i++)
            ta[i] = ++n;

        for (int i = 0; i < 100; i++)
            std::cout << "ta[" << i << "]:" << ta[i] << " ";

        const TenArray taa(5);

        for (int i = 0; i < 100; i++)
            std::cout << "taa[" << i << "]:" << taa[i] << " ";
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what();
    }
}
