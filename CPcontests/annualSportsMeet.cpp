#include <bits/stdc++.h> 
using namespace std; 

class Graph 
{ 
	int V; 
	int adj[100][100]; 
public: 
	Graph(int V) 
    {
        this->V = V;
        for(int i=0; i<V; i++) for(int j=0; j<V; j++) {if(j != i) adj[i][j] = true; else adj[i][j] = false;}
    } 
	void deleteEdge(int v, int w); 
	void greedyColoring(); 
}; 

void Graph::deleteEdge(int v, int w) 
{ 
	adj[v][w] = false; 
	adj[w][v] = false;
} 

void Graph::greedyColoring() 
{ 
	int result[V]; 
    int res = INT_MIN;

	result[0] = 0; 
	for (int u = 1; u < V; u++) result[u] = -1;

	bool available[V]; 
	for (int cr = 0; cr < V; cr++) 	available[cr] = false; 

	for (int u = 1; u < V; u++) 
	{ 
		for (int i = 0; i != V; ++i) if(adj[u][i]) if(result[i] != -1) available[result[i]] = true;
		int cr; 
		for (cr = 0; cr < V; cr++) if (available[cr] == false) break; 
        res = max(res, cr);
		result[u] = cr;
		for (int i = 0; i != V; ++i) if(adj[u][i]) if(result[i] != -1) available[result[i]] = false;
	} 
    cout << res+1;
} 

signed main() 
{ 
    int n;
    cin >> n;
	Graph g(n); 
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        g.deleteEdge(a, b);
    }
	g.greedyColoring(); 

	return 0; 
} 
