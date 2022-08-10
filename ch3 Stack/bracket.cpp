#include <iostream>
#include <stack>
using namespace std;
#define endl "\n"

bool check_brackets(string str)
{
    stack<char> s;
    s.push(0);
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            s.push(str[i]);

        if (str[i] == ')')
        {
            if (s.top() == '(') s.pop();
            else return false;
        }

        if (str[i] == '}')
        {
            if (s.top() == '{') s.pop();
            else return false;
        }

        if (str[i] == ']')
        {
            if (s.top() == '[') s.pop();
            else return false;
        }
    }

    if (s.top() == 0)
        return true;
    else
        return false;
}

int main(void)
{
    int c;
    cin >> c;

    for (int i = 0; i < c; i++)
    {
        string a;
        cin >> a;

        if (check_brackets(a))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
