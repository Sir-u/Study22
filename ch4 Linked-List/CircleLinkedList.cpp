#include <iostream>
using namespace std;
#define endl "\n";

template <typename T>
struct Node
{
public:
    T value;
    struct Node<T> *next = nullptr;
};

template <typename T>
class CirclelinkedList
{
private:
    Node<T> *head;
    int size = 0;

public:
    CirclelinkedList() : head(nullptr) {}
    ~CirclelinkedList() {}

    void AddNode(T _value)
    {
        Node<T> *node = new Node<T>;

        size++;
        node->value = _value;

        if(head == nullptr)
        {
            head = node;
            node->next = head;
        }
        else
        {
            Node<T> *tail = head;
            while(tail->next != head){
                tail = tail->next;
            }
            tail->next = node;
            node->next = head;
        }
    }

    void RemoveNode(T _value)
    {
        Node<T> *ptr = head;
        Node<T> *tmp = ptr;

        while(ptr != nullptr)
        {
            if(ptr->value == _value)
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
            cout << "Value of deleted node : " << ptr->value << endl;
            tmp->next = ptr->next;
            delete ptr;
        }
    }
    void Show()
    {
        Node<T> *node = head;

        cout << node->value << "->";
        node = node->next;
        
        while(node != head)
        {
            cout << node->value << "->";
            node = node->next;
        }

        cout << "Head" << endl;
    }

    void DeleteList()
    {
        Node<T> *ptr = head;

        while(size != 1)
        {
            head = ptr->next;
            delete ptr;
            ptr = head;
            size--;
        }
        delete head;
        size = 0;
        cout << "List deleted" << endl;
    }

    void RemoveTail()
    {
        Node<T> *ptr = head;
        Node<T> *tmp = new Node<T>;

        if(ptr == nullptr)
        {
            cout << "List empty" << endl;
        }
        else
        {
            while (ptr->next != head)
            {
                tmp = ptr;
                ptr = ptr->next;
            }
            size--;
            tmp->next = head;
            delete ptr;
        }
    }

    void RemoveHead()
    {
        Node<T> *ptr = head;

        if(head == nullptr)
        {
            cout << "List empty" << endl;
        }
        else
        {
            Node<T> *tail = head;

            while(tail->next != head)
            {
                tail = tail->next;
            }
            if(tail == head)
            {
                head = nullptr;
            }
            else
            {
                head = head->next;
                tail->next = head;
            }
            size--;
            delete ptr;
        }
    }
    
    void AddHead(T _value)
    {
        Node<T> *ptr = new Node<T>;
        ptr->value = _value;
        size++;
        if(head == nullptr)
        {
            head = ptr;
            ptr->next = head;
        }
        else{
            Node<T> *tail = head;
            while(tail->next != head)
            {
                tail = tail->next;
            }
            ptr->next = head;
            head = ptr;
            tail->next = head;
        }
    }

    void AddPosition(int _index, T _value)
    {
        if(size+1 < _index || 0 > _index)
        {
            cout << "Error: Invalid position" << endl;
            return;
        }

        Node<T> *ptr = head;
        Node<T> *tmp = ptr;
        Node<T> *node = new Node<T>;

        node->value = _value;
        node->next = nullptr;

        if(_index == 1)
        {
            Node<T> *tail = head;
            while(tail->next != head)
            {
                tail = tail->next;
            }
            node->next = head;
            head = node;
            tail->next = head;
        }
        else if(_index == size + 1)
        {
            Node<T> *tail = head;
            while(tail->next != head){
                tail = tail->next;
            }
            tail->next = node;
            node->next = head;
        }
        else
        {
            for (int i = 0; i < _index - 1; i++)
            {
                tmp = ptr;
                ptr = ptr->next;
            }
            tmp->next = node;
            node->next = ptr;
        }
        size++;
    }

    void SearchValue(T _value)
    {
        Node<T> *ptr = head;
        int index = 0;
        bool found = false;

        Node<T> *tail = head;
        while(tail->next != head){
            tail = tail->next;
        }

        while(ptr->next != tail)
        {
            index++;
            if(ptr->value == _value)
            {
                cout << _value << " is in index " << index << endl;
                return;
            }
            else
            {
                ptr = ptr->next;
            }
        }

        if(found == false)
        {
            cout << _value << " is not found" << endl;
        }
    }

    void Size()
    {
        cout << size << endl;
    }
};

int main(void)
{
    // SinglelinkedList<int> *List = new SinglelinkedList<int>();
    // List->AddNode(10);
    // delete List;

    CirclelinkedList<char> List;
    List.AddNode('a');
    List.AddNode('b');
    List.AddNode('c');
    List.RemoveNode('c');
    List.AddNode('d');
    List.Show();
    List.RemoveTail();
    List.Show();
    List.AddNode('u');
    List.AddNode('e');
    List.AddNode('w');
    List.Show();
    List.RemoveHead();
    List.Show();
    List.AddHead('M');
    List.Show();
    List.Size();
    List.AddPosition(6, 'H');
    List.Show();
    List.SearchValue('e');
    List.Show();

}