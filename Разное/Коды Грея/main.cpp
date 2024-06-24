#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<string> grayCode(int n)
{
    if (n == 1)
    {
        vector<string> v;
        
        v.push_back("0");
        v.push_back("1");

        return v;
    }
    else
    {
        vector<string> v;
        auto prev = grayCode(n - 1);

        for (int i = 0; i < prev.size(); i++)
        {
            v.push_back("0" + prev[i]);
        }

        for (int i = prev.size() - 1; i > -1; i--)
        {
            v.push_back("1" + prev[i]);
        }

        return v;
    }
}

int main()
{
    int n = 4;
    auto v = grayCode(n);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}