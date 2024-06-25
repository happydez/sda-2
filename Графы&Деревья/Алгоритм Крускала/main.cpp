#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge
{
    public:
        int src, dest, weight;
};

class Graph
{
    public:
        int V, E;
        vector<Edge> edges;

        Graph(int V)
        {
            this->V = V;
            this->E = 0;
        }

        void addEdge(int src, int dest, int w)
        {
            edges.push_back({ src, dest,w });
            this->E++;
        }

        int find(vector<int>& parent, int i)
        {
            if (parent[i] == i)
            {
                return i;
            }

            return find(parent, parent[i]);
        }

        void Union(vector<int>& parent, vector<int>& rank, int x, int y)
        {
            int xp = find(parent, x);
            int yp = find(parent, y);

            if (rank[xp] < rank[yp])
            {
                parent[xp] = yp;
            }
            else if (rank[xp] > rank[yp])
            {
                parent[yp] = xp;
            }
            else
            {
                parent[yp] = xp;
                rank[xp]++;
            }
        }

        void KruskalMST()
        {
            sort(edges.begin(), edges.end(), [](Edge x, Edge y) {
                return x.weight < y.weight;
            });

            vector<int> parent(V);
            vector<int> rank(V, 0);

            for (int i = 0; i < V; i++)
            {
                parent[i] = i;
            }

            vector<Edge> result;
            int e = 0, i = 0;

            while (e < V - 1 && i < edges.size())
            {
                Edge nextEdge = edges[i++];

                int x = find(parent, nextEdge.src);
                int y = find(parent, nextEdge.dest);

                if (x != y)
                {
                    result.push_back(nextEdge);
                    Union(parent, rank, x, y);
                    e++;
                }
            }

            cout << "Edge \tWeight\n";
            for (auto edge : result)
            {
                cout << edge.src << " - " << edge.dest << " \t" << edge.weight << " \n";
            }
        }
};

int main() {
    //vector<vector<int>> graph = {
    //    //1  2  3  4  5  6
    //    { 0, 6, 1, 5, 0, 0 },
    //    { 6, 0, 5, 0, 3, 0 },
    //    { 1, 5, 0, 5, 6, 4 },
    //    { 5, 0, 5, 0, 0, 2 },
    //    { 0, 3, 6, 0, 0, 6 },
    //    { 0, 0, 4, 2, 6, 0 }
    //};

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

    int vertexs = graph.size();

    Graph g(vertexs);

    for (int i = 0; i < vertexs; i++) {
        for (int j = i + 1; j < vertexs; j++) {
            if (graph[i][j] != 0) {
                g.addEdge(i, j, graph[i][j]);
            }
        }
    }

    g.KruskalMST();

    return 0;
}
