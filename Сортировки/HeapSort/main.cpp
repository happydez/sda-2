#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Heapify(int* heap, int N, int start = 0)
{
    if (start < N)
    {
        while ((2 * start + 1) < N)
        {
            int j = 2 * start + 1;

            if ((2 * start + 2) < N && (heap[j] > heap[2 * start + 2]))
            {
                j = 2 * start + 2;
            }

            if (heap[start] < heap[j])
            {
                break;
            }
            else
            {
                swap(heap[start], heap[j]);
                start = j;
            }
        }
    }
}

void HeapSort(int* heap, int N, int start = 0, bool rvr = true)
{
    for (int i = N / 2; i >= 0; i--)
    {
        Heapify(heap, N, i);
    }

    for (int i = N - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        Heapify(heap, i, 0);
    }

    if (rvr)
    {
        reverse(heap, heap + N);
    }
}

void PrintData(int* data, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << data[i] << " ";
    }

    cout << endl;
}

int main()
{
    const int N = 5;
    auto data = new int[N]{ 7, 1, 3, 2, 5 };

    PrintData(data, N);

    HeapSort(data, N);

    PrintData(data, N);

    delete[] data;

    return 0;
}
