#include <iostream>
using namespace std;
#define endl "\n";

double cnt = 0;

int fib(int n)
{
    if (n <= 1)
    {
        cnt++;
        return n;
    }
    else
    {
        cnt++;
        return fib(n - 1) + fib(n - 2);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    fib(n);

    printf("%.0f\n", cnt);
}