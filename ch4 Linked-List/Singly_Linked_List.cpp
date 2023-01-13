#include <iostream>
using namespace std;
#define endl "\n";

template <typename T>
struct Node
{
public:
    T velue;
    struct Node<T> *next = nullptr;
};

template <typename T>
class SinglelinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size = 0;
public:
    SinglelinkedList() : head(nullptr), tail(nullptr) {}
    ~SinglelinkedList() {}

    void AddNode(T _value)
    {
        Node<T> *node = new Node<T>;

        size++;
        node->velue = _value;
        node->next = nullptr;

        if(head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = tail->next;
        }
    }
    void RemoveNode(T _value)
    {
        Node<T> *ptr = head;
        Node<T> *tmp = ptr;

        while(ptr != nullptr)
        {
            if(ptr->velue == _value)
            {
                break;
            }
            else
            {
                tmp = ptr;
                ptr = ptr->next;
            }
        }

        if(ptr == nullptr)
        {
            cout << "Can't Find Node" << endl;
        }
        else
        {
            size--;
            cout << " Value of deleted node : " << ptr->velue << endl;
            tmp->next = ptr->next;
            delete ptr;
        }
    }
    void Show()
    {
        Node<T> *node = head;

        while(node != nullptr)
        {
            cout << node->velue << "->";
            node = node->next;
        }
        cout << endl;
    }

    void DeleteList()
    {
        Node<T> *ptr = head;

        while(ptr != nullptr)
        {
            head = ptr->next;
            delete ptr;
            ptr = head;
        }
        delete head;
        size = 0;
        cout << "List deleted" << endl;
    }

    void RemoveTail()
    {
        Node<T> *ptr = head;
        Node<T> *tmp = new Node<T>;

        while(ptr->next != nullptr)
        {
            tmp = ptr;
            ptr = ptr->next;
        }
        size--;
        tail = tmp;
        tail->next = nullptr;
        delete ptr;
    }
    void RemoveHead()
    {
        Node<T> *ptr = head;
        head = ptr->next;
        size--;
        delete ptr;
    }
    
    void AddHead(T _value)
    {
        Node<T> *ptr = new Node<T>;

        size++;
        ptr->next = head;
        ptr->velue = _value;
        head = ptr;
    }

    void AddPosition(int _index, T _value)
    {
        if(size < _index || 0 > _index)
        {
            cout << "Error: Invalid position" << endl;
            return;
        }

        Node<T> *ptr = head;
        Node<T> *tmp = ptr;
        Node<T> *node = new Node<T>;

        node->velue = _value;
        node->next = nullptr;

        for(int i = 0; i < _index - 1; i++)
        {
            tmp = ptr;
            ptr = ptr->next;
        }
        tmp->next = node;
        node->next = ptr;
        size++;
    }

    void SearchValue(T _value)
    {
        Node<T> *ptr = head;
        int index = 0;
        bool found = false;

        while(ptr != nullptr)
        {
            index++;
            if(ptr->value == _value)
            {
                cout << _value << "is in index " << index << endl;
            }
        }

        if(found == false)
        {
            cout << _value << " is not found" << endl;
        }
    }

    int Size()
    {
        return size;
    }
};

int main(void)
{
    // SinglelinkedList<int> *List = new SinglelinkedList<int>();
    // List->AddNode(10);
    // delete List;

    SinglelinkedList<int> List;
    List.AddNode(10);
    List.AddNode(11);
    List.AddNode(12);
    List.AddNode(15);
    List.AddHead(5);
    List.Show();
    
}