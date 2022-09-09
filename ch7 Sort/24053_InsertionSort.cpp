// 문제
// 오늘도 서준이는 삽입 정렬 수업 조교를 하고 있다. 아빠가 수업한 내용을 학생들이 잘 이해했는지 문제를 통해서 확인해보자.
// N개의 서로 다른 양의 정수가 저장된 배열 A가 있다.
// 삽입 정렬로 배열 A를 오름차순 정렬할 경우 정렬 과정에서 배열 A가 배열 B와 같은 경우가 발생하는지 확인해 보자.
// 초기 상태 배열 A도 정렬 과정에서 발생 가능한 경우로 생각하자.
// 크기가 N인 배열에 대한 삽입 정렬 의사 코드는 다음과 같다.

// insertion_sort(A[1..N]) { # A[1..N]을 오름차순 정렬한다.
//     for i <- 2 to N {
//         loc = i - 1;
//         newItem = A[i];

//         # 이 지점에서 A[1..i-1]은 이미 정렬되어 있는 상태
//         while (1 <= loc and newItem < A[loc]) {
//             A[loc + 1] <- A[loc];
//             loc--;
//         }
//         if (loc + 1 != i) then A[loc + 1] = newItem;
//     }
// }

// 입력
// 첫째 줄에 배열 A, B의 크기 N(5 ≤ N ≤ 10,000)이 주어진다.
// 다음 줄에 서로 다른 배열 A의 원소 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)
// 다음 줄에 배열 B의 원소 B1, B2, ..., BN이 주어진다. (1 ≤ Bi ≤ 109)

// 출력
// 삽입 정렬로 배열 A를 오름차순 정렬하는 과정에서 배열 A가 배열 B와 같은 경우가 발생하면 1, 아니면 0을 출력한다.


#include <iostream>
#include <vector>
using namespace std;
#define endl "\n";


int main()
{
    int n;
    cin >> n;

    int loc = 0, newItem = 0, ans = 0;
    vector<int> arrA;
    vector<int> arrB;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arrA.push_back(num);
    }

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arrB.push_back(num);
    }

    for (int i = 1; i < n; i++)
    {
        loc = i - 1;
        newItem = arrA[i];

        while (0 <= loc && newItem < arrA[loc])
        {
            arrA[loc + 1] = arrA[loc];
            loc--;
            
            if (arrA == arrB)
            {
                ans = 1;
                break;
            }

            if (loc + 1 != i){
                arrA[loc + 1] = newItem;
            }

            if (arrA == arrB)
            {
                ans = 1;
                break;
            }
        }
    }
    cout << ans;
}