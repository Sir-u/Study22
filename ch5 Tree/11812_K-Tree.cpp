// 문제
// 각 노드가 자식을 최대 K개 가질 수 있는 트리를 K진 트리라고 한다.
// 총 N개의 노드로 이루어져 있는 K진 트리가 주어진다.

// 트리는 "적은 에너지" 방법을 이용해서 만든다.
// "적은 에너지" 방법이란, 이전 깊이를 모두 채운 경우에만, 새로운 깊이를 만드는 것이고,
//이 새로운 깊이의 노드는 가장 왼쪽부터 차례대로 추가 한다.

// 아래 그림은 노드 9개로 이루어져 있는 3진 트리이다.



// 노드의 개수 N과 K가 주어졌을 때, 두 노드 x와 y 사이의 거리를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N (1 ≤ N ≤ 1015)과 K (1 ≤ K ≤ 1 000), 그리고 거리를 구해야 하는 노드 쌍의 개수 Q (1 ≤ Q ≤ 100 000)가 주어진다.

// 다음 Q개 줄에는 거리를 구해야 하는 두 노드 x와 y가 주어진다. (1 ≤ x, y ≤ N, x ≠ y)

// 출력
// 총 Q개의 줄을 출력한다. 각 줄에는 입력으로 주어진 두 노드 사이의 거리를 출력한다.


#include <iostream>
#include <algorithm>
using namespace std;
#define endl "\n";

long long int N;
int K, Q;

long long int is_Depth(long long int data)
{
    long long int depth = 0;

    if (K == 1) depth = data;
    else
    {
        if(data != 0)
        {
            depth = 1;
            long long int left = 1, right = K;

            while(!(left<=data && data <= right))
            {
                depth++;
                left = left * K + 1;
                right = right * K + K;
            }
        }
    }

    return depth;
}

long long int is_Parent(long long int data)
{
    long long int parent = 0;

    parent = (data-1) / K;

    return parent;
}


long long int is_Dinstance(long long int x, long long int y)
{
    long long int depth_x = 0, depth_y = 0, ans = 0;

    depth_x = is_Depth(x);
    depth_y = is_Depth(y);

    if(depth_x < depth_y)
    {
        swap(depth_x, depth_y);
        swap(x, y);
    }

    if(K==1) ans = depth_x - depth_y;
    else
    {
        long long int gap = depth_x - depth_y;

        ans += gap;
        for(int i = 0; i < gap; i++)
        {
            x = is_Parent(x);
        }

        while(x != y)
        {
            x = is_Parent(x);
            y = is_Parent(y);
            ans += 2;
        }
    }

    return ans;
}


int main(void)
{
    

    
    cin >> N >> K >> Q;

    for (int i = 0; i < Q; i++)
    {
        long long int x, y;
        cin >> x >> y;

        cout << is_Dinstance(x-1, y-1) << endl;
    }


}