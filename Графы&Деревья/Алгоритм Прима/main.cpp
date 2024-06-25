#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF INT_MAX

int nextVertex(vector<int>& weights, vector<bool>& visited)
{
    int minIndex, minWeight = INF;

    for (int i = 0; i < weights.size(); i++)
    {
        if (!visited[i] && weights[i] < minWeight)
        {
            minIndex = i;
            minWeight = weights[i];
        }
    }

    return minIndex;
}

void printMST(const vector<int>& parent, const vector<vector<int>>& graph)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < parent.size(); i++)
    {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }
}

void primMST(vector<vector<int>>& graph)
{
    int len = graph.size();

    vector<int> parent(len, 0);

    vector<int> weights(len, INF);
    vector<bool> visited(len, false);

    weights[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < len - 1; i++)
    {
        int nv = nextVertex(weights, visited);

        visited[nv] = true;

        for (int v = 0; v < graph.size(); v++)
        {
            if ((graph[nv][v] > 0) && (!visited[v]) && (graph[nv][v] < weights[v]))
            {
                weights[v] = graph[nv][v];
                parent[v] = nv;
            }
        }
    }

    printMST(parent, graph);
}
int main()
{   
    vector<vector<int>> graph = {
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 2, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 },
    };

    primMST(graph);

    return 0;
}