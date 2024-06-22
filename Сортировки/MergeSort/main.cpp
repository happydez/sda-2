#include <iostream>
#include <vector>

using namespace std;

void PrintData(int* data, int N);

int* merge(int* left, int ln, int* right, int rn)
{
    int i = 0, j = 0;

    auto result = new int[ln + rn];

    while ((i < ln) || (j < rn))
    {
        if ((j == rn) || ((i < ln) && (left[i] < right[j])))
        {
            result[i + j] = left[i];
            i++;
        }
        else
        {
            result[i + j] = right[j];
            j++;
        }
    }

    return result;
}

int* mergeSort(int* data, int N)
{
    if (N <= 1)
    {
        return data;
    }

    auto left = new int[N / 2];

    for (int i = 0; i < N / 2; i++)
    {
        left[i] = data[i];
    }

    auto right = new int[N - N / 2];

    int j = 0;
    for (int i = N / 2; i < N; i++, j++)
    {
        right[j] = data[i];
    }

    left = mergeSort(left, N / 2);
    right = mergeSort(right, N - N / 2);

    auto result = merge(left, N / 2, right, N - N / 2);

    delete[] left;
    delete[] right;

    return result;
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

    data = mergeSort(data, N);

    PrintData(data, N);

    delete[] data;

    return 0;
}
