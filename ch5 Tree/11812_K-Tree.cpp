// ����
// �� ��尡 �ڽ��� �ִ� K�� ���� �� �ִ� Ʈ���� K�� Ʈ����� �Ѵ�.
// �� N���� ���� �̷���� �ִ� K�� Ʈ���� �־�����.

// Ʈ���� "���� ������" ����� �̿��ؼ� �����.
// "���� ������" ����̶�, ���� ���̸� ��� ä�� ��쿡��, ���ο� ���̸� ����� ���̰�,
//�� ���ο� ������ ���� ���� ���ʺ��� ���ʴ�� �߰� �Ѵ�.

// �Ʒ� �׸��� ��� 9���� �̷���� �ִ� 3�� Ʈ���̴�.



// ����� ���� N�� K�� �־����� ��, �� ��� x�� y ������ �Ÿ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

// �Է�
// ù° �ٿ� N (1 �� N �� 1015)�� K (1 �� K �� 1 000), �׸��� �Ÿ��� ���ؾ� �ϴ� ��� ���� ���� Q (1 �� Q �� 100 000)�� �־�����.

// ���� Q�� �ٿ��� �Ÿ��� ���ؾ� �ϴ� �� ��� x�� y�� �־�����. (1 �� x, y �� N, x �� y)

// ���
// �� Q���� ���� ����Ѵ�. �� �ٿ��� �Է����� �־��� �� ��� ������ �Ÿ��� ����Ѵ�.


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