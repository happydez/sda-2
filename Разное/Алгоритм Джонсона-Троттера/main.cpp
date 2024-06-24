#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const bool LEFT_ARROW = false;
const bool RIGHT_ARROW = true;

int posMobile(int* a, int n, int mobile)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mobile)
        {
            return i + 1;
        }
    }
}

int nextMobile(int* a, bool* dir, int n)
{
    int prevMobile = 0, mobile = 0;

    for (int i = 0; i < n; i++)
    {
        if (dir[a[i] - 1] == LEFT_ARROW && i != 0)
        {
            if (a[i] > a[i - 1] && a[i] > prevMobile)
            {
                mobile = a[i];
                prevMobile = mobile;
            }
        }

        if (dir[a[i] - 1] == RIGHT_ARROW && i != n - 1)
        {
            if (a[i] > a[i + 1] && a[i] > prevMobile)
            {
                mobile = a[i];
                prevMobile = mobile;
            }
        }
    }

    if (mobile == 0 && prevMobile == 0)
    {
        return 0;
    }

    return mobile;
}

void nextPerm(int* a, bool* dir, int n)
{
    int mobile = nextMobile(a, dir, n);
    int pos = posMobile(a, n, mobile);

    if (dir[a[pos - 1] - 1] == LEFT_ARROW)
    {
        swap(a[pos - 1], a[pos - 2]);
    }
    else if (dir[a[pos - 1] - 1] == RIGHT_ARROW)
    {
        swap(a[pos - 1], a[pos]);
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] > mobile)
        {
            dir[a[i] - 1] = (dir[a[i] - 1] == LEFT_ARROW) ? RIGHT_ARROW : LEFT_ARROW;
        }

        // print permutation
        cout << a[i];
    }

    cout << endl;
}

int factorial(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = res * i;
    }

    return res;
}

void printPerm(int n)
{
    int* a = new int[n];
    bool* dir = new bool[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        cout << a[i];
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        dir[i] = LEFT_ARROW;
    }

    for (int i = 1; i < factorial(n); i++)
    {
        nextPerm(a, dir, n);
    }
}

int main()
{
    int n = 4;

    printPerm(n);

    return 0;
}