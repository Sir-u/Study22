#include <iostream>
#include <algorithm>
using namespace std;
#define endl "\n";

const int MAX = 100001;

template <typename T>
class Heap
{
private:
    T heap[MAX];
    int heap_size;
    bool state = true; // if true, the heap is empty, otherwise the heap is not empty;
public:
    Heap()
    {
        for (int i = 0; i < MAX; i++)
            heap[i] = 0;
        heap_size = 0;
    }

    bool is_empty()
    {
        if (heap_size == 0)
        {
            return true;
        }
        return false;
    }

    void Push()
    {
        T data;
        cin >> data;
        PushHeap(data);
    }

    void PushHeap(T data)
    {
        int c_index = ++heap_size; // start from the index 1
        int p_index = c_index / 2;

        if (!is_empty())
        {
            while (p_index > 0 && heap[p_index] > data)
            {
                heap[c_index] = heap[p_index];
                c_index = p_index;
                p_index /= 2;
            }
        }
        heap[c_index] = data;
    }

    void Pop()
    {
        if (!is_empty())
        {
            cout << PopHeap() << endl;
        }
        else
        {
            cout << "Heap is empty" << endl;
        }
    }

    T PopHeap()
    {
        T return_value = 0;

        if (!is_empty())
        {
            int p_index = 1;
            int c_index = p_index * 2;
            return_value = heap[1];
            heap[1] = heap[heap_size--];

            while (c_index <= heap_size)
            {
                if (c_index + 1 <= heap_size && heap[c_index + 1] > heap[c_index])
                {
                    c_index++;
                }
                if (heap[c_index] > heap[p_index])
                    break;

                swap(heap[c_index], heap[p_index]);
                p_index /= 2;
                c_index = p_index * 2;
            }
        }

        return return_value;
    }

    void Show()
    {
        if (!is_empty())
        {
            for (int i = 1; i <= heap_size; i++)
            {
                cout << heap[i] << "; ";
            }
        }
        else
        {
            cout << "Heap is empty.";
        }
        cout << endl;
    }
};

int main(void)
{
    Heap<int> Heap;
    string order;

    do
    {
        cin >> order;

        if (order == "push")
            Heap.Push();
        if (order == "pop")
            Heap.Pop();
        if (order == "show")
            Heap.Show();

    } while (order != "end");
}