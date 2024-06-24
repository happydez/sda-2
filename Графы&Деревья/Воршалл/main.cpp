#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF INT_MAX

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int vertexs, edges;
    cin >> vertexs >> edges;

    vector<vector<int>> graph(vertexs, vector<int>(vertexs, 0));

    for (int i = 0; i < edges; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1][v2] = 1;
    }

    for (int v = 0; v < vertexs; v++)
    {
        for (int a = 0; a < vertexs; a++)
        {
            for (int b = 0; b < vertexs; b++)
            {
                /*
                * v - вспомогательная вершина, через которую может существовать
                * путь из a в b через вершину v. Если путь уже существует то мы ставим 1,
                * иначе проверяем что существует путь через вершину v: a -> v -> b. В таком
                * случае, путь существует только если существуют пути из a -> v (graph[a][v])
                * и v -> b (graph[b][v])
                */
                graph[a][b] = graph[a][b] || (graph[a][v] && graph[v][b]);
            }
        }
    }

    for (int i = 0; i < vertexs; i++)
    {
        for (int j = 0; j < vertexs; j++)
        {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}