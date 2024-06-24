#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int AssignmentBruteForce(vector<int> tasks, vector<vector<int>>& costs, vector<int>& bestCombination)
{
    int minCost = INT_MAX;
    int rows = costs.size();

    do
    {
        int currentCost = 0;

        for (int i = 0; i < rows; i++)
        {
            currentCost += costs[i][tasks[i] - 1];
        }

        if (currentCost < minCost)
        {
            minCost = currentCost;
            bestCombination = tasks;
        }

    } while (next_permutation(tasks.begin(), tasks.end()));

    return minCost;
}

int main()
{
    // i - employee
    // tasks[i] - task
    // costs[employeeId][tasks[employeeId] - 1] - task cost
    vector<int> tasks = { 1, 2, 3, 4 };

    vector<vector<int>> costs =
    {
        { 9, 2, 7, 8 },
        { 6, 4, 3, 7 },
        { 5, 8, 1, 8 },
        { 7, 6, 9, 4 }
    };


    vector<int> bestCombination = { 1, 2, 3, 4 };

    int minCost = AssignmentBruteForce(tasks, costs, bestCombination);

    cout << "minCost = " << minCost << endl;
    
    cout << "bestCombination: ";
    for (auto bc : bestCombination)
    {
        cout << bc << " ";
    }

    cout << endl;

    return 0;
}