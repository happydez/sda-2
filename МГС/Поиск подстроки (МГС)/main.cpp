#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool BruteForceStringMatch(const char* str, const char* substr)
{
    int strLen = strlen(str);
    int substrLen = strlen(substr);

    if (substrLen > strLen)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < strLen - substrLen + 1; i++)
        {
            bool isSubstr = true;

            for (int j = 0; j < substrLen; j++)
            {
                if (substr[j] != str[i + j])
                {
                    isSubstr = false;
                    break;
                }
            }

            if (isSubstr) return true;
        }
    }

    return false;
}

int main()
{
    cout << (BruteForceStringMatch("Hello World!", "World") ? "YES" : "NO") << endl;
    cout << (BruteForceStringMatch("Hello World!", "World!") ? "YES" : "NO") << endl;
    cout << (BruteForceStringMatch("Hello World!", "World@") ? "YES" : "NO") << endl;
    cout << (BruteForceStringMatch("Hello World!", "ello Wor") ? "YES" : "NO") << endl;

    return 0;
}
