#include <iostream>
using namespace std;

class Stack
{
private:
    int sArr[10];
    int top = -1;

public:
    void Push()
    {
        if(top == 9)
        {
            cout << "Stack is Full!" << endl;
            return;
        }

        int data;
        cin >> data;

        sArr[++top] = data;
    }

    void Pop()
    {
        if(top == -1)
        {
            cout << "Stack is Empty!" << endl;
            return;
        }

        cout << sArr[top] << endl;
        top--;
    }

    void Empty()
    {
        if(top == -1) cout << "Stack is Empty!" << endl;
        else cout << "Stack is not Empty!" << endl;
    }

    void Full()
    {
        if(top == 9) cout << "Stack is Full!" << endl;
        else cout << "Stack is not Full!" << endl;
    }

    void Size()
    {
        cout << top + 1 << endl;
    }

    void Top()
    {
        cout << sArr[top] << endl;
    }
};

int main(void)
{
    Stack s;

    string order;

    while(1)
    {
        cin >> order;

        if (order == "end") break;
        if (order == "push") s.Push();
        if (order == "pop") s.Pop();
        if (order == "empty") s.Empty();
        if (order == "full") s.Full();
        if (order == "size") s.Size();
        if (order == "top") s.Top();
    }
}