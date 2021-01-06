#include <iostream>

struct Link
{
    int data;
    Link* next;
};

class LinkList
{
private:
    Link* m_first;
public:
    LinkList() : m_first(nullptr)
    {}
    ~LinkList()
    {
        Link* current = m_first;
        Link* next = m_first->next;
        while (1)
        {
            delete current;
            std::cout << "--Deleted!--\n";
            current = next;
            if (current == nullptr)
                break;
            next = next->next;
        }
    }
    void additem(int d);
    void display();
};

void LinkList::additem(int d)
{
    if (!m_first)
    {
        m_first = new Link;
        m_first->data = d;
        m_first->next = nullptr;
    }
    else
    {
        Link* temp = m_first;
        while (temp->next)
            temp = temp->next;

        Link* newLink = new Link;
        newLink->data = d;
        newLink->next = nullptr;
        temp->next = newLink;
    }
}

void LinkList::display()
{
    Link* current = m_first;
    while (current)
    {
        std::cout << current->data << '\n';
        current = current->next;
    }
}

int main()
{
    LinkList lst;

    lst.additem(1);
    lst.additem(2);
    lst.additem(3);

    lst.display();
}
