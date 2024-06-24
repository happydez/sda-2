#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF INT_MAX

using namespace std;

pair<vector<int>, vector<int>> bfs(vector<vector<int>>& graph, int start)
{
    vector<int> dist(graph.size(), INF);
    vector<int> from(graph.size(), -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (auto to : graph[v])
        {
            if (dist[to] > dist[v] + 1)
            {
                dist[to] = dist[v] + 1;
                from[to] = v;
                q.push(to);
            }
        }
    }

    return pair<vector<int>, vector<int>>(dist, from);
}

vector<int> getPath(vector<int>& from, int finish)
{
    vector<int> path;

    for (int v = finish; v != -1; v = from[v])
    {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    return path;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int vertexs, edges;
    cin >> vertexs >> edges;

    vector<vector<int>> graph(vertexs);

    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    int start = 0;
    auto result = bfs(graph, 0);
    
    auto dist = result.first;
    auto from = result.second;

    // backtracking
    for (auto v : getPath(from, 4))
    {
        cout << v << " ";
    }

    cout << endl;

    return 0;
}