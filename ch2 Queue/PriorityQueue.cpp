//문제
//정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

//명령은 총 여섯 가지이다.

//push X: 정수 X를 큐에 넣는 연산이다.
//pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//size: 큐에 들어있는 정수의 개수를 출력한다.
//empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
//front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//입력
//첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 2,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

//출력
//출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.


#include <iostream>
#include <algorithm>

using namespace std;

int Qarr[2000001];
int front, rear = 0;
int N;


void Push(){
    int num;
    cin >> num;
    Qarr[rear++] = num;

    for(int i=front; i < rear-1; i++){ // 선택정렬
        for (int j=i+1; j< rear; j++){
            if(Qarr[i] < Qarr[j])
                swap(Qarr[i], Qarr[j]);
        }
    }

}

void Pop(){
    if (front == rear) {cout << -1 << endl;}
    else {
        cout << Qarr[front++] << '\n';
    }
}

void Size(){
    cout << rear - front << '\n';
}

void Empty(){
    if (front == rear) {cout << 1 << '\n';}
    else {cout << 0 << endl;}
}

void Front(){
    if (front == rear) {cout << -1 << '\n';}
    else {cout << Qarr[front] << '\n';}
}

void Back(){
    if (front == rear) {cout << -1 << '\n';}
    else {cout << Qarr[rear-1] << '\n';}
}


int main(void){
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    
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