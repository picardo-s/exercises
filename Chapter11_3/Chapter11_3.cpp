#include <iostream>

class Array
{
private:
    int* m_ptr;
    int m_size;
public:
    Array(int s) : m_size(s)
    {
        m_ptr = new int[s];
    }
    Array(Array& arr)
    {
        m_size = arr.m_size;
        m_ptr = new int[arr.m_size];
        for (int i = 0; i < m_size; i++)
            *(m_ptr + i) = arr[i];
    }
    ~Array()
    {
        delete[] m_ptr;
    }

    void print()
    {
        for (int i = 0; i < m_size; i++)
            std::cout << *(m_ptr + i) << " ";
        std::cout << '\n';
    }

    int& operator[](int i)
    {
        return *(m_ptr + i);
    }

    Array& operator=(Array& arr)
    {
        delete[] m_ptr;
        m_size = arr.m_size;
        m_ptr = new int[arr.m_size];
        for (int i = 0; i < m_size; i++)
            *(m_ptr + i) = arr[i];
        return *this;
    }
};

int main()
{
    const int SIZE = 10;
    Array arr(SIZE);
    for (int i = 0; i < SIZE; i++)
        arr[i] = i * i;

    std::cout << "arr: ";
    arr.print();

    std::cout << "\narr2: ";
    Array arr2(arr);
    arr2.print();

    Array arr3(SIZE * 2);
    arr3 = arr;
    std::cout << "\narr3: ";
    arr3.print();
}
