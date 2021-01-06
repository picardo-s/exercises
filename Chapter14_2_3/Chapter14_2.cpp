#include <iostream>
#include <conio.h>

template<class Type>
class Queue
{
private:
    static const int LIM = 10;
    Type m_arr[LIM];
    int m_head;
    int m_tail;
    int m_count;
public:
    Queue() :m_head(0), m_tail(0), m_count(0)
    {}

    void put(Type num)
    {
        if (m_tail == LIM)
            m_tail = 0;
        if (m_count == LIM)
            throw Full();
        m_arr[m_tail++] = num;
        m_count++;
    }

    Type get()
    {
        if (m_head == LIM)
            m_head = 0;
        if (m_count == 0)
            throw Empty();
        m_count--;
        return m_arr[m_head++];
    }
    class Full
    {};
    class Empty
    {};
};

int main()
{
    typedef long queue_t;
    Queue<queue_t> q;
    queue_t num;
    char ch;
    std::cout << "Press \'p\' to put an integer in the queue, \'g\' to get an integer from the queue, " <<
        " \'e\' to exit.\n";
    while (1)
    {
        try {
            while ((ch = _getche()) != 'e')
            {
                if (ch == 'p')
                {
                    std::cout << "\nPut: ";
                    while (1)
                    {
                        std::cin >> num;
                        if (std::cin.fail())
                        {
                            std::cin.clear();                          
                            std::cin.ignore(1000, '\n');
                            std::cout << "Wrong input\n";
                            continue;
                        }
                        break;
                    }
                    q.put(num);
                }
                if (ch == 'g')
                    std::cout << "\nGot: " << q.get() << '\n';
            }
        }
        catch (Queue<queue_t>::Empty)
        {
            std::cout << "\nThe queue is empty!\n";
            continue;
        }
        catch (Queue<queue_t>::Full)
        {
            std::cout << "\nThe queue is full!\n";
            continue;
        }
        break;
    }
}