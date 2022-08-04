#include <iostream>
#include <stack>
using namespace std;

#define endl "\n"

bool check_brackets(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        // if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        s.push(str[i]);

        if (s.size() > 1)
        {
            if (str[i] == ')')
            {
                if (s.top() - 1 == '(')
                {
                    s.pop();
                    s.pop();
                }
            }

            if (str[i] == '}')
            {
                if (s.top() - 2 == '{')
                {
                    s.pop();
                    s.pop();
                }
            }

            if (str[i] == ']')
            {
                if (s.top() - 2 == '[')
                {
                    s.pop();
                    s.pop();
                }
            }
        }
    }
    if (s.empty())
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