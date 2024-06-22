#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& visited, int vertex)
{
    visited[vertex] = 1;

    for (int to : graph[vertex])
    {
        if (!visited[to])
        {
            dfs(graph, visited, to);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector<vector<int>> graph(vertexCount);

    for (int i = 0; i < edgeCount; i++)
    {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int start, finish;
    cin >> start >> finish;
    start--;
    finish--;

    vector<int> visited(vertexCount);
    
    dfs(graph, visited, start);

    if (visited[finish])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
