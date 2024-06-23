#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int V = 4;

int TSP(int graph[][V], int s)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
    {
        if (i != s)
        {
            vertex.push_back(i);
        }
    }

    int minPath = INT_MAX;
    do
    {
        int k = s;
        int currentPathweight = 0;

        for (int i = 0; i < vertex.size(); i++)
        {
            currentPathweight += graph[k][vertex[i]];
            k = vertex[i];
        }

        currentPathweight += graph[k][s];
        minPath = min(minPath, currentPathweight);

    } while (next_permutation(vertex.begin(), vertex.end()));

    return minPath;
}

int main()
{
    int graph[][V] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } 
				     };
					 
    int s = 0;
    cout << TSP(graph, s) << endl;

    return 0;
}