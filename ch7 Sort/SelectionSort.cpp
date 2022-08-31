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
    int tmp = 0, least = 0;

    Show(arr);

    for(int i = 0; i < 9; i++)
    {
        least = i;
        
        for(int j = i+1; j < 10; j++)
        {
            if(arr[j] < arr[least])
            {
                least = j;
            }
        }

        if(i != least)
        {
            int tmp = arr[i];
            arr[i] = arr[least];
            arr[least] = tmp;
        }
        Show(arr);
    }

    Show(arr);
}