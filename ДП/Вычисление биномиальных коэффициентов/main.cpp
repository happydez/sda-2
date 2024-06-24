#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define N 1000

int Binomial(int k, int n)
{
    vector<vector<int>> C(N, vector<int>(N));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
            {
                C[i][j] = 1;
            }
            else
            {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }

    return C[n][k];
}

int main()
{
    int k, n;
    cin >> k >> n;

    cout << Binomial(k, n) << endl;


    return 0;
}