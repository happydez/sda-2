#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int BinarySearch(const vector<int>& data, int x)
{
    int len = data.size();

    int l = -1, r = len;

    while (r > l + 1)
    {
        int m = (l + r) / 2;

        if (data[m] >= x)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }

    return (r == len) ? -1 : r;
}

int BinarySearchRecur(const vector<int>& data, int x, int l, int r)
{
    if (r > l + 1)
    {
        int m = (l + r) / 2;

        if (data[m] >= x)
        {
            r = m;
        }
        else
        {
            l = m;
        }

        return BinarySearchRecur(data, x, l, r);
    }
    else 
    {
        return (r == data.size()) ? -1 : r;
    }
}

int main()
{

    vector<int> data = { 1, 2, 3, 4, 5 };

    cout << BinarySearch(data, 1) << endl;
    cout << BinarySearch(data, 5) << endl;
    cout << BinarySearch(data, 3) << endl;

    cout << endl;

    cout << BinarySearchRecur(data, 1, -1, data.size()) << endl;
    cout << BinarySearchRecur(data, 5, -1, data.size()) << endl;
    cout << BinarySearchRecur(data, 3, -1, data.size()) << endl;

    return 0;
}