//����
//������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

//����� �� ���� �����̴�.

//push X: ���� X�� ť�� �ִ� �����̴�.
//pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
//size: ť�� ����ִ� ������ ������ ����Ѵ�.
//empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
//front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
//back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
//�Է�
//ù° �ٿ� �־����� ����� �� N (1 �� N �� 2,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

//���
//����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.


#include <iostream>
#include <string>

using namespace std;

int Qarr[100001];
int front, rear = 0;
int N;


void Push(){
    int num;
    cin >> num;
    Qarr[rear++] = num;
}

void Pop(){
    if (front == rear) {cout << -1 << endl;}
    else {
        cout << Qarr[front++] << endl;
    }
}

void Size(){
    cout << rear - front << endl;
}

void Empty(){
    if (front == rear) {cout << 1 << endl;}
    else {cout << 0 << endl;}
}

void Front(){
    if (front == rear) {cout << -1 << endl;}
    else {cout << Qarr[front] << endl;}
}

void Back(){
    if (front == rear) {cout << -1 << endl;}
    else {cout << Qarr[rear-1] << endl;}
}


int main(void){
    
    string order;

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> order;

        if(order == "push") Push();
        if(order == "pop") Pop();
        if(order == "size") Size();
        if(order == "empty") Empty();
        if(order == "front") Front();
        if(order == "back") Back();
    }
    
}