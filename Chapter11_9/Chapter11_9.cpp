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
    explicit LinkList(LinkList& list)
    {
        std::cout << "\nCopying!\n";

        Link* temp = list.m_first;
        while (temp)
        {
            Link* newLink = new Link;
            newLink->data = temp->data;
            newLink->next = m_first;
            m_first = newLink;
            temp = temp->next;
        }
    }
    ~LinkList()
    {
        Link* current = m_first;
        Link* next = m_first->next;
        while (1)
        {
            std::cout << "(" << current->data << ")";
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
    LinkList& operator=(const LinkList& list);
};

void LinkList::additem(int d)
{
    Link* newLink = new Link;
    newLink->data = d;
    newLink->next = m_first;
    m_first = newLink;
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

LinkList& LinkList::operator=(const LinkList& list)
{
    std::cout << "\nAssigning!\n";

    if (this == &list)
        return *this;

    delete m_first;
    m_first = nullptr;

    Link* temp = list.m_first;
    while (temp)
    {
        Link* newLink = new Link;
        newLink->data = temp->data;
        newLink->next = m_first;
        m_first = newLink;
        temp = temp->next;
    }
    return *this;
}

int main()
{
    /*LinkList* lst = new LinkList;

    lst->additem(11);
    lst->additem(5);
    lst->additem(13);

    *lst = *lst;

    lst->display();

    LinkList* lst2 = new LinkList(*lst);
    *lst2 = *lst;
    delete lst;

    lst2->display();*/

    LinkList lst;
    lst.additem(11);
    lst.additem(5);
    lst.additem(13);

    lst = lst;

    LinkList lst2(lst);


    lst2.display();

}
