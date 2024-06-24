#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 2^n
void generateSet(int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << j + 1;
            }
        }

        cout << endl;
    }
}

// 2^n + nlog(n) + n
void generateSortedSet(int n)
{
    vector<int> nums;

    for (int i = 0; i < (1 << n); i++)
    {
        int num = 0;

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                num = num * 10 + (j + 1);
            }
        }

        nums.push_back(num);
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
}

int main()
{
    int n = 4;

    //generateSet(n);
    //generateSortedSet(n);

    return 0;
}