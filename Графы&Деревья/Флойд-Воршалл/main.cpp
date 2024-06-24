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

    vector<vector<int>> dist(vertexs, vector<int>(vertexs, INF));

    for (int i = 0; i < vertexs; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < edges; i++)
    {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;

        dist[v1][v2] = min(dist[v1][v2], weight);
    }

    for (int v = 0; v < vertexs; v++)
    {
        for (int a = 0; a < vertexs; a++)
        {
            for (int b = 0; b < vertexs; b++)
            {
                /*
                * v - вспомогательная вершина, через которую либо можно
                * пройти от a до b, либо нельзя. Поэтому в начале мы смотрим,
                * существует ли путь и далее, если путь существует, мы выбираем
                * наименьший между прямым путем и путем через вершину v.
                * То есть min(a -> b, a -> v -> b)
                */
                if (dist[a][v] != INF && dist[v][b] != INF &&
                    dist[a][b] > dist[a][v] + dist[v][b])
                {
                    dist[a][b] = dist[a][v] + dist[v][b];
                }
            }
        }
    }

    for (int i = 0; i < vertexs; i++)
    {
        for (int j = 0; j < vertexs; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF" << " ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }

        cout << endl;
    }

    return 0;
}