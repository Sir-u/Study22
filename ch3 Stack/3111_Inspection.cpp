// 문제
// 김상근은 창영마을에서의 권력을 유지하기 위해 신문을 검열하려고 한다.

// 상근이는 텍스트 T에서 A라는 단어를 다음과 같은 알고리즘을 이용해서 모두 없애려고 한다.

// 1. T에 A가 없으면 알고리즘을 종료한다.
// 2. T에서 처음 등장하는 A를 찾은 뒤, 삭제한다.
// 3. T에 A가 없으면 알고리즘을 종료한다.
// 4. T에서 마지막으로 등장하는 A를 찾은 뒤, 삭제한다.
// 5. 1번으로 돌아간다.
// 상근이는 마을을 지배해야하기 때문에, 검열을 할 시간이 없다.
// 상근이의 검열을 대신해주는 프로그램을 작성하시오. 

// 입력
// 첫째 줄에 단어 A가, 둘째 줄에 텍스트 T가 주어진다.
//A와 T는 알파벳 소문자로만 이루어져 있고, A는 최대 25자, T는 최대 300,000자이다.

// 출력
// 검열을 한 이후의 텍스트를 출력한다.



#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    deque<char> dq_front; //앞에서부터 시작하는 덱
    deque<char> dq_back; //뒤에서부터 시작하는 덱

    string a, t;
    cin >> a >> t;

    int front_index = 0, back_index = t.size() - 1; //각 덱에 대한 인덱스 초기화(맨 앞과 맨 뒤로 초기화)

    while(front_index <= back_index) //1번부터 5번까지
    {
        while(front_index <= back_index) //2번
        {
            bool check = false;
            dq_front.push_back(t[front_index++]); // 문자 앞에서부터 덱의 앞으로 하나씩 삽입
            if(dq_front.size() >= a.size())  // A만큼의 문자가 있다면 비교 시작
            {
                check = true;
                for (int i = 0; i < a.size(); i++) // A와 같다면 check는 true를 유지
                {
                    if(a[i] != dq_front[dq_front.size()-a.size()+i])
                    {
                        check = false;
                        break;
                    }
                }

                if (check) // T에서 A크기만큼, 다시말해 찾은 A를 삭제
                {
                    for(int i = 0; i < a.size(); i++) dq_front.pop_back();
                    break;
                }
            }
        }

        while(front_index <= back_index) // 4번
        {
            dq_back.push_front(t[back_index]);
            back_index--;
            bool check = false;
            if(dq_back.size() >= a.size())
            {
                check = true;
                for (int i = 0; i < a.size(); i++)
                {
                    if (a[i] != dq_back[i])
                    {
                        check = false;
                        break;
                    }
                }
            }
            if (check)
            {
                for(int i = 0; i < a.size(); i++) dq_back.pop_front();
                break;
            }
        }
    }
    string answer;
    for (int i = 0; i < dq_front.size(); i++) answer.push_back(dq_front[i]);
    for (int i = 0; i < dq_back.size(); i++) answer.push_back(dq_back[i]);
    while(answer.find(a)<300000) // 합치는 과정에서 발생하는 A를 삭제
        answer.erase(answer.find(a), a.size());
    if(!answer.empty()) cout << answer << '\n';
}