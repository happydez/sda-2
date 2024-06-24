#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int nthElement(int* arr, int n, int l, int r, int k)
{
    if (l == r)
    {
        return arr[l];
    }

    int i = l, j = r;
    int x = arr[(l + r) / 2];

    while (i <= j)
    {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }

    if (j - l >= k)
    {
        nthElement(arr, n, l, j, k);
    }
    else
    {
        nthElement(arr, n, j + 1, r, k - (j - l) - 1);
    }

}

int main()
{
    const int N = 9;
    int* arr = new int[N] {4, 1, 10, 9, 7, 12, 8, 2, 15};

    cout << nthElement(arr, N, 0, N - 1, N / 2) << endl;

    return 0;
}