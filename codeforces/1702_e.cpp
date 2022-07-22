#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;using vvl = vector<vl>;using vs = vector<string>;
using ml = map<ll, ll>;using uml = unordered_map<ll, ll>;
using pl = pair<ll, ll>;using tl = tuple<ll, ll, ll>;
using vll = vector<pl>;using vlll = vector<tl>;
using pq = priority_queue <ll, vl, greater<ll>>;using gq = priority_queue <ll>;
#define mem(dp) memset(dp, -1, sizeof(dp))
#define aut(a, b) for (auto&(a) : (b))
#define out(v) for (auto&(x) : (v)) cout << x << " "; cout << '\n';
#define rep(i, n) for (ll (i) = 0; (i) < (n); ++(i) )
#define repp(i, n) for (ll (i) = 1; (i) <= (n); ++(i) )
#define rev(i, n) for (ll (i) = n-1; (i) >= 0; --(i) )
#define revv(i, n) for (ll (i) = n; (i) > 0; --(i) )
#define inc(v) rep(i, v.size()) cin>>v[i];
#define dec(v) rep(i, v.size()) cout<<v[i]<<" ";
#define inp(n) ll n; cin>>n;
#define all(v) v.begin(), v.end()
#define fi get<0>
#define se get<1>
#define th get<2>
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
ll inf = 1e18; ll mod = 1e9 + 7;
bool compare(pl a, pl b) {return a.F > b.F;}
ll digit(ll n) {return floor(log10(n) + 1);}

bool containsOdd(vvl G, int src, int V)
{
    vl col(V, -1);
    col[src] = 1;
    queue <ll> q;
    q.push(src);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for(auto v:G[u])
        {
            if (col[v] == -1)
            {
                col[v] = 1 - col[u];
                q.push(v);
            }
            else if (col[v] == col[u])
                return false;
        }
    }
   
    return true;
}

bool oddCycle(vvl &v, ll src, vl &visited)
{
    visited[src]=0;
    queue<ll> q; q.push(src);
    while(!q.empty())
    {
        ll f=q.front();
        q.pop();
        aut(x, v[f])
        {
            if(visited[x]==-1)
            {
                visited[x]=(visited[f]+1)%2;
                q.push(x);
            }
            else if(visited[x]==visited[f])
            {
                return false;
            }
        }
    }
    return true;
}

void calc()
{
    inp(k);
    vvl v(k);
    rep(i, k)
    {
        inp(x); inp(y);
        x--; y--;
        v[x].pb(y); v[y].pb(x);
    }

    vl visited(k, -1);
    bool flag=true;
    rep(i, k)
    {
        if(visited[i]==-1)
        {
            flag = flag and oddCycle(v, i, visited);
            if(!flag) break;
        }
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    repp(z, t)
    {
        //cout << "Case #" << z << ": ";
        calc();
        cout << '\n';
    }

    return 0;
}
