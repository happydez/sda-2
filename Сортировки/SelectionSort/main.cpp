#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SelectionSort(int* data, int N)
{
    int minIndex;

    for (int i = 0; i < N - 1; i++)
    {
        minIndex = i;

        for (int j = i + 1; j < N; j++)
        {
            if (data[j] < data[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swap(data[minIndex], data[i]);
        }
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

    SelectionSort(data, N);

    PrintData(data, N);

    delete[] data;

    return 0;
}
