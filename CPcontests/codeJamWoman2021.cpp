#include <bits/stdc++.h>
using namespace std;

// took reference from
// https://www.geeksforgeeks.org/minimum-number-of-edges-between-two-vertices-of-a-graph-using-dfs/?ref=rp

class Graph
{
    int V;
    list<int>* adj;
    void minEdgeDFSUtil(vector<bool>& visited, int src, int des, int& min_num_of_edges, int& edge_count);

public:
    Graph(int V);

    void addEdge(int src, int des);
    void minEdgeDFS(int u, int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int src, int des)
{
    adj[src].push_back(des);
    adj[des].push_back(src);
}

void Graph::minEdgeDFSUtil(vector<bool>& visited, int src, int des, int& min_num_of_edges, int& edge_count)
{
    visited[src] = true;
    if (src == des)
    {
        if (min_num_of_edges > edge_count) min_num_of_edges = edge_count;
    }

    else
    {

        list<int>::iterator i;

        for (i = adj[src].begin(); i != adj[src].end(); i++)
        {
            int v = *i;

            if (!visited[v])
            {
                edge_count++;

                minEdgeDFSUtil(visited, v, des, min_num_of_edges, edge_count);
            }
        }
    }
    visited[src] = false;
    edge_count--;
}
void Graph::minEdgeDFS(int u, int v)
{
    vector<bool> visited(V, false);
    int min_num_of_edges = INT_MAX;
    int edge_count = 0;

    minEdgeDFSUtil(visited, u, v, min_num_of_edges, edge_count);
    cout << min_num_of_edges - 1 << " ";
}

int main()
{
    int tt;
    cin >> tt;
    for (int z = 1; z <= tt; z++)
    {
        cout << "Case #" << z << ": ";
        int n, m;
        cin >> n >> m;
        int p;
        cin >> p;
        Graph g(n + m);
        bool flag = true;
        for (int i = 0; i < (n + m); i++)
        {
            for (int j = 0; j < (n + m); j++)
            {
                char c;
                cin >> c;
                if (c == 'Y')
                {
                    g.addEdge(i, j);
                    if (i != j) flag = false;
                }
            }
        }
        while (p--)
        {
            int u, v;
            cin >> u >> v;
            if (flag) cout << "-1 ";
            else g.minEdgeDFS(u - 1, v - 1);
        }
        cout << '\n';

    }
    return 0;
}
