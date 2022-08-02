#include <iostream>
using namespace std;

class Deque
{
private:
    int DeArr[10] = {0};
    int front = 0, back = 0;

public:
    void Push()
    {
        if (((back + 1) % 10) == front)
        {
            cout << "Deque is Full!" << endl;
            return;
        }

        string point;
        cin >> point;

        if (point == "front")
        {
            int data;
            cin >> data;
            DeArr[front] = data;
            front = (front + 9) % 10;
        }

        if (point == "back")
        {
            int data;
            cin >> data;
            back = (back + 1) % 10;
            DeArr[back] = data;
        }
    }

    void Pop()
    {
        if (front == back)
        {
            cout << "Deque is Empty!" << endl;
            return;
        }

        string point;
        cin >> point;

        if (point == "front")
        {
            front = (front + 1) % 10;
            cout << DeArr[front] << endl;
        }

        if(point == "back")
        {
            cout << DeArr[back] << endl;
            back = (back + 9) % 10;
        }

    }

    void Empty()
    {
        if(front == back) cout << "Deque is Empty" << endl;
        else cout << "Deque is not Empty" << endl;
    }

    void Size()
    {
        if (back > front) cout << back - front << endl;
        if (back < front) cout << front - back << endl;
        if (back == front) cout << 0 << endl;
    }

    void Front()
    {
        if (front == back) cout << "Deque is Empty" << endl;
        else cout << DeArr[front + 1] << endl;
    }

    void Back()
    {
        if (front == back) cout << "Deque is Empty" << endl;
        else cout << DeArr[back] << endl;
    }
};

int main(void){
    Deque q;
    
    string order;

    while (1)
    {
        cin >> order;

        if (order == "push") q.Push();
        if (order == "pop") q.Pop();
        if (order == "empty") q.Empty();
        if (order == "size") q.Size();
        if (order == "front") q.Front();
        if (order == "back") q.Back();
    }

}