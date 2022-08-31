#include <iostream>
using namespace std;
#define endl "\n";

void BubbleSort()
{

}

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
    int tmp = 0;
    cout << "Before sorting:    ";
    Show(arr);

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    cout << "After being sorted: ";
    Show(arr);
}