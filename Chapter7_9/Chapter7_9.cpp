#include <iostream>
#include <conio.h>

class Queue
{
private:
    static const int LIM = 10;
    int m_arr[LIM];
    int m_head;
    int m_tail;
    int m_count;
public:
    Queue():m_head(0), m_tail(0), m_count(0)
    {}

    void put(int num)
    {
        if (m_tail == LIM)
            m_tail = 0;
        if (m_count == LIM)
        {
            std::cout << "\nThe queue is full!\n";
            return;
        }
        m_arr[m_tail++] = num;
        m_count++;
    }

    int get()
    {
        if (m_head == LIM)
            m_head = 0;
        if (m_count == 0)
        {
            std::cout << "\nThe queue is empty!\n";
            return -1;
        }
        m_count--;
        return m_arr[m_head++];
    }
};

int main()
{
    Queue q;
    char ch;
    int num;
    std::cout << "Press \'p\' to put an integer in the queue, \'g\' to get an integer from the queue, " <<
        " \'n\' to exit.\n";
    while ((ch = _getche()) != 'n')
    {
        if (ch == 'p')
        {
            std::cout << "\nPut: ";
            std::cin >> num;
            q.put(num);
        }
        if (ch == 'g')
            std::cout << "\nGot: " << q.get() << '\n';
    }
}
