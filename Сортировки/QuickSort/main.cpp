#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void QuickSort(int* data, int l, int r)
{
    if (r - l < 1)
    {
        return;
    }

    int i = l, j = r;
    int x = data[(l + r) / 2];

    while (i <= j)
    {
        while (data[i] < x) i++;
        while (data[j] > x) j--;

        if (i <= j)
        {
            swap(data[i], data[j]);
            i++;
            j--;
        }
    }

    if (l < j) QuickSort(data, l, j);
    if (r > i) QuickSort(data, i, r);
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

    QuickSort(data, 0, N - 1);

    PrintData(data, N);

    delete[] data;

    return 0;
}
