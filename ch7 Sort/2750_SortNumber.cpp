// ����
// N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

// �Է�
// ù° �ٿ� ���� ���� N(1 �� N �� 1,000)�� �־�����.
// ��° �ٺ��� N���� �ٿ��� �� �־�����.
// �� ���� ������ 1,000���� �۰ų� ���� �����̴�.
// ���� �ߺ����� �ʴ´�.

// ���
// ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.

#include <iostream>
#include <algorithm>
using namespace std;
#define endl "\n";

int main()
{
    int n;
    cin >> n;

    int* arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);
    
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;
}