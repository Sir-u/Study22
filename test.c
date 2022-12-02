#include <stdio.h>

int tempA = 5;
char tempB[10] = {"hello"};

void SubNum(int a, int b)
{
    int c;
    c = a - b;
    printf("%d\n", c);
}

int main()
{
    int tempC = 3;

    int solution = tempA + tempC;
    printf("%d\n", solution);
    printf("%s\n", tempB);
    SubNum(tempA, tempC);

    return 0;   
}