#include <iostream>
using namespace std;
#define endl "\n";

void Show(int arr[])
{
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << "; ";
    }
    cout << endl;
}

int main()
{
    int arr[10] = {22, 2, 46, 27, 16, 5, 49, 24, 13, 9};
    int i, j, tmp = 0;

    Show(arr);

    for(i = 1; i < 10; i++)
    {
        tmp = arr[i];

        for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
        {
            arr[j + 1] = arr[j];
            //Show(arr);
        }

        arr[j + 1] = tmp;
        
        Show(arr);
    }

    Show(arr);
}