#include<bits/stdc++.h>
using namespace std;

bool validBfs(int n, vector<int> sequence , vector<vector<int>> edges)
{
    unordered_map<int, int> m;
    for(int i=0; i<sequence.size(); i++) m[sequence[i]-1]=i;
    vector<int> v[n];
    for(auto x:edges)
    {
        v[x[0]-1].push_back(x[1]-1);
        v[x[1]-1].push_back(x[0]-1);
    }
    for(int i=0; i<n; i++)
    {
        vector<pair<int, int>> y;
        for(auto x:v[i])
        {
            y.push_back({m[x], x});
        }
        sort(y.begin(), y.end());
        for(int j=0; j<v[i].size(); j++)
        {
            v[i][j]=y[j].second;
        }
    }
    bool visited[n]={0};
    int dist[n]={0};
    int parent[n];
    for(int i=0; i<n; i++) parent[i]=-1;
    parent[0]=0;
    queue<int> q;
    q.push(0);
    visited[0]=true;
    vector<int> d;
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        d.push_back(f+1);
        for(auto x:v[f])
        {
            if(visited[x]) continue;
            dist[x]=dist[f]+1;
            q.push(x);
            parent[x]=f;
            visited[x]=true;
        }
    }
    
    return d==sequence;
}
int main() {
	// your code goes here
    int  n; cin>>n;
    vector<vector<int>> edges;
    for(int i=0; i<n-1; i++)
    {
        int x,y; cin>>x>>y;
        vector<int> v={x, y};
        edges.push_back(v);
    }
    vector<int> s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    if(validBfs(n, s, edges)) cout<<"Yes";
    else cout<<"No";
	return 0;
}

