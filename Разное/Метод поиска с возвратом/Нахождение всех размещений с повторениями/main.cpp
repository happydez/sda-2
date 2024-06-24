#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// backtracking
void generatePermutationsWithRepetition(const vector<int>& elements, vector<int>& currentPerm, int k)
{
    if (currentPerm.size() == k)
    {
        for (auto e : currentPerm)
        {
            cout << e;
        }

        cout << endl;

        return;
    }

    for (int i = 0; i < elements.size(); i++)
    {
        currentPerm.push_back(elements[i]);
        generatePermutationsWithRepetition(elements, currentPerm, k);
        currentPerm.pop_back();
    }
}

int main()
{
    int k = 2;
    vector<int> elements = { 1, 2, 3 };

    vector<int> current_permutation;

    generatePermutationsWithRepetition(elements, current_permutation, k);

    return 0;
}