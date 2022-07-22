#include<bits/stdc++.h> 
using namespace std; 

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vii = vector<pi>;
using vll = vector<pl>;

// took reference from 
// https://www.geeksforgeeks.org/connected-components-in-an-undirected-graph/
// which was publically available before the start of the contest !!

ll rpp = 0;
ll mod = 998244353;

bool compare(ll a, ll b) {return a > b;}

class Graph {
    int V; // No. of vertices
 
    // Pointer to an array containing adjacency lists
    list<int>* adj;
 
    // A function used by DFS
    void DFSUtil(int v, bool visited[]);
 
public:
    Graph(int V); // Constructor
    ~Graph();
    void addEdge(int v, int w);
    void connectedComponents();
};
 
// Method to print connected components in an
// undirected graph
void Graph::connectedComponents()
{
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;
 
    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            // print all reachable vertices
            // from v
            DFSUtil(v, visited);
            rpp++;
 
            //cout << "\n";
        }
    }
    delete[] visited;
}
 
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    //cout << v << " ";
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
Graph::~Graph() { delete[] adj; }
 
// method to add an undirected edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

ll powLL(ll x, ll n)
{
    ll result = 1;
    while(n)
    {
        if (n & 1) result = result * x % mod;
        n = n / 2;
        x = x * x % mod;
    }
    return result;
}

void calc()
{
    ll c, n ,m;
    cin >> c >> n >> m;
    Graph g(n);
    for(ll i=0; i<c; i++)
    {
        ll x; cin >> x;
        ll prev = -1;
        while(x--)
        {
            ll l, r;
            cin >> l >> r;
            l--; r--;
            if(prev != -1) g.addEdge(prev, l);
            prev = r;
            for(ll i=l;i<r;i++)  g.addEdge(i, r);
        }
    }
    g.connectedComponents();
    m %= mod;
    rpp %= mod;
    ll res = powLL(m, rpp);
    res %= mod;
    cout << res;
    rpp = 0;
    return;
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while(t--)
    {
        calc();
        cout << '\n';
    }
    
    return 0;
}
