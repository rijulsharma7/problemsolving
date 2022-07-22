#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
using mi = map<int, int>;
using ml = map<ll, ll>;
using umi = unordered_map<int, int>;
using uml = unordered_map<ll, ll>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ti = tuple<int, int, int>;
using tl = tuple<ll, ll, ll>;
using vii = vector<pi>;
using viii = vector<ti>;
using vll = vector<pl>;
using vlll = vector<tl>;
using pq = priority_queue <ll, vl, greater<ll>>;
using gq = priority_queue <ll>;
#define mem(dp) memset(dp, -1, sizeof(dp))
#define aut(a, b) for (auto&(a) : (b))
#define out(v) for (auto&(x) : (v)) cout << x << " "; cout << '\n';
#define rep(i, n) for (ll (i) = 0; (i) < (n); ++(i) )
#define repp(i, n) for (ll (i) = 1; (i) <= (n); ++(i) )
#define all(v) v.begin(), v.end()
#define fi get<0>
#define se get<1>
#define th get<2>
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
ll inf = 1e18;
ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}
ll gcd(ll a , ll b) {if (b == 0) return a; a %= b; return gcd(b, a);}
ll digit(ll n) {return floor(log10(n) + 1);}

void dfs(ll v, bool visited[], list<ll>* adj)
{
    visited[v] = true;
    for (auto x : adj[v])
        if (!visited[x])
            dfs(x, visited, adj);
}

ll sc(ll n, list<ll>* adj)
{
    bool* visited = new bool[n];
    rep(v, n)
    visited[v] = false;
    ll res = 0;
    rep(v, n) {
        if (visited[v] == false) {
            dfs(v, visited, adj);
            res++;
        }
    }
    delete[] visited;
    return res;
}

void calc()
{
    ll n;
    cin >> n;
    vl v(n);
    rep(i, n) cin >> v[i];

    // list<ll> adj[n];
    // rep(i, n - 1)
    // {
    //     for (ll j = i + 1; j < n; j++)
    //     {
    //         if ((j - i) != (v[j] - v[i]))
    //         {
    //             adj[i].pb(j);
    //             adj[j].pb(i);
    //         }
    //     }
    // }

    uml m;
    rep(i, n) m[v[i] - i - 1]++;

    if (m[v[0] - 1] == n) cout << n;
    else cout << 1;

    // cout << sc(n, adj);

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
