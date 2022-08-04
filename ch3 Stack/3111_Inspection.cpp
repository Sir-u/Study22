// ����
// ������ â������������ �Ƿ��� �����ϱ� ���� �Ź��� �˿��Ϸ��� �Ѵ�.

// ����̴� �ؽ�Ʈ T���� A��� �ܾ ������ ���� �˰����� �̿��ؼ� ��� ���ַ��� �Ѵ�.

// 1. T�� A�� ������ �˰����� �����Ѵ�.
// 2. T���� ó�� �����ϴ� A�� ã�� ��, �����Ѵ�.
// 3. T�� A�� ������ �˰����� �����Ѵ�.
// 4. T���� ���������� �����ϴ� A�� ã�� ��, �����Ѵ�.
// 5. 1������ ���ư���.
// ����̴� ������ �����ؾ��ϱ� ������, �˿��� �� �ð��� ����.
// ������� �˿��� ������ִ� ���α׷��� �ۼ��Ͻÿ�. 

// �Է�
// ù° �ٿ� �ܾ� A��, ��° �ٿ� �ؽ�Ʈ T�� �־�����.
//A�� T�� ���ĺ� �ҹ��ڷθ� �̷���� �ְ�, A�� �ִ� 25��, T�� �ִ� 300,000���̴�.

// ���
// �˿��� �� ������ �ؽ�Ʈ�� ����Ѵ�.



#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    deque<char> dq_front; //�տ������� �����ϴ� ��
    deque<char> dq_back; //�ڿ������� �����ϴ� ��

    string a, t;
    cin >> a >> t;

    int front_index = 0, back_index = t.size() - 1; //�� ���� ���� �ε��� �ʱ�ȭ(�� �հ� �� �ڷ� �ʱ�ȭ)

    while(front_index <= back_index) //1������ 5������
    {
        while(front_index <= back_index) //2��
        {
            bool check = false;
            dq_front.push_back(t[front_index++]); // ���� �տ������� ���� ������ �ϳ��� ����
            if(dq_front.size() >= a.size())  // A��ŭ�� ���ڰ� �ִٸ� �� ����
            {
                check = true;
                for (int i = 0; i < a.size(); i++) // A�� ���ٸ� check�� true�� ����
                {
                    if(a[i] != dq_front[dq_front.size()-a.size()+i])
                    {
                        check = false;
                        break;
                    }
                }

                if (check) // T���� Aũ�⸸ŭ, �ٽø��� ã�� A�� ����
                {
                    for(int i = 0; i < a.size(); i++) dq_front.pop_back();
                    break;
                }
            }
        }

        while(front_index <= back_index) // 4��
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
    while(answer.find(a)<300000) // ��ġ�� �������� �߻��ϴ� A�� ����
        answer.erase(answer.find(a), a.size());
    if(!answer.empty()) cout << answer << '\n';
}