#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 4;

using Item = pair<int, int>;

int KnapsackBruteForce(vector<Item> items, int w)
{
    int n = items.size();
    int bestValue = 0;

    for (int i = 0; i < (1 << n); i++)
    {
        int totalWeight = 0;
        int totalValue = 0;

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                totalWeight = items[j].second;
                totalValue = items[j].first;
            }
        }

        if ((totalWeight <= w) && (totalValue > bestValue))
        {
            bestValue = totalValue;
        }
    }

    return (bestValue == 0) ? -1 : bestValue;
}

int main()
{
    int w = 10;
    vector<Item> items = { {1, 2}, {4, 3}, {5, 6}, {6, 7} };

    cout << KnapsackBruteForce(items, w) << endl;

    return 0;
}