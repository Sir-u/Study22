// ����
// ���õ� �����̴� ���� ���� ���� ������ �ϰ� �ִ�. �ƺ��� ������ ������ �л����� �� �����ߴ��� ������ ���ؼ� Ȯ���غ���.
// N���� ���� �ٸ� ���� ������ ����� �迭 A�� �ִ�.
// ���� ���ķ� �迭 A�� �������� ������ ��� ���� �������� �迭 A�� �迭 B�� ���� ��찡 �߻��ϴ��� Ȯ���� ����.
// �ʱ� ���� �迭 A�� ���� �������� �߻� ������ ���� ��������.
// ũ�Ⱑ N�� �迭�� ���� ���� ���� �ǻ� �ڵ�� ������ ����.

// insertion_sort(A[1..N]) { # A[1..N]�� �������� �����Ѵ�.
//     for i <- 2 to N {
//         loc = i - 1;
//         newItem = A[i];

//         # �� �������� A[1..i-1]�� �̹� ���ĵǾ� �ִ� ����
//         while (1 <= loc and newItem < A[loc]) {
//             A[loc + 1] <- A[loc];
//             loc--;
//         }
//         if (loc + 1 != i) then A[loc + 1] = newItem;
//     }
// }

// �Է�
// ù° �ٿ� �迭 A, B�� ũ�� N(5 �� N �� 10,000)�� �־�����.
// ���� �ٿ� ���� �ٸ� �迭 A�� ���� A1, A2, ..., AN�� �־�����. (1 �� Ai �� 109)
// ���� �ٿ� �迭 B�� ���� B1, B2, ..., BN�� �־�����. (1 �� Bi �� 109)

// ���
// ���� ���ķ� �迭 A�� �������� �����ϴ� �������� �迭 A�� �迭 B�� ���� ��찡 �߻��ϸ� 1, �ƴϸ� 0�� ����Ѵ�.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl "\n";

int main()
{
    int n;
    cin >> n;
    
    // int* arrA = new int[n];
    // int* arrB = new int[n];
    vector<int> arrA;
    vector<int> arrB;

    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arrA.push_back(num);
    }

    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arrB.push_back(num);
    }

    if(arrA == arrB)
    {
        cout << "aaaa" << endl;
    }

    //for(int i = 1; i < n; i++)



    // delete[] arrA;
    // delete[] arrB;
}