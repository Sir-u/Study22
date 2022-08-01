#include <iostream>
using namespace std;

class CircleQueue
{
private:
    int Qarr[10] = {0};
    int front = 0, rear = 0;

public:
    void Push()
    {
        if (((rear + 1) % 10) == front)
            cout << "Queue is Full" << endl;
        else
        {
            int data;
            cin >> data;
            rear = (rear + 1) % 10;
            Qarr[rear] = data;
        }
    }

    void Pop(){
        if(front == rear) {
            cout << "Queue is Empty" << endl;
            return;
        }
        front = (front + 1) % 10;
        cout << Qarr[front] << endl;
    }

    void Empty()
    {
        if(front == rear) cout << "Queue is Empty" << endl;
        else cout << "Queue is not Empty" << endl;
    }

    void Size()
    {
        cout << rear - front << endl;
    }

    void Front(){
        if (front == rear) {cout << "Queue is Empty" << endl;}
        else {cout << Qarr[front+1] << endl;}
    }

    void Back(){
        if (front == rear) {cout << "Queue is Empty" << endl;}
        else {cout << Qarr[rear] << endl;}
    }
};

int main (void){
    
    CircleQueue q;
    
    int N;
    string order;

    cin >> N;

    for(int i=0; i < N; i++){
        cin >> order;

        if(order == "push") q.Push();
        if(order == "pop") q.Pop();
        if(order == "size") q.Size();
        if(order == "empty") q.Empty();
        if(order == "front") q.Front();
        if(order == "back") q.Back();
    }
}