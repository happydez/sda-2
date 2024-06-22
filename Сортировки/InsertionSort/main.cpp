#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(int* data, int N)
{
    for (int i = 1; i < N; i++)
    {
        int j = i;
        while (j > 0 && (data[j] < data[j - 1]))
        {
            swap(data[j], data[j - 1]);
            j--;
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
    auto data = new int[N]{ 5, 4, 3, 2, 1 };

    PrintData(data, N);

    InsertionSort(data, N);

    PrintData(data, N);

    delete[] data;

    return 0;
}
