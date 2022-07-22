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
ll r = 0;
void dfs(ll v, bool visited[], list<ll>* adj, vl w)
{
    visited[v] = true;
    r++;
    for (auto x : adj[v])
        if (!visited[x] && w[v - 1] < w[x - 1])
            dfs(x, visited, adj, w);
}

ll sc(ll n, list<ll>* adj, vl w, ll l)
{
    bool* visited = new bool[n + 1];
    rep(v, n + 1)
    visited[v] = false;
    ll res = 0;
    ll cnt = 0;
    while (cnt < n) {
        if (visited[l] == false) {
            dfs(l, visited, adj, w);
            res += (r * (r - 1) / 2);
            r = 0;
        }
        l = (l + 1) % n;
        l++; cnt++;
    }
    delete[] visited;
    return res;
}

void calc()
{
    ll n;
    cin >> n;
    vl p(n - 1), v(n);
    list<ll> adj[n + 1];
    rep(i, n - 1)
    {
        cin >> p[i];
        adj[p[i]].pb(i + 2);
        adj[i + 2].pb(p[i]);
    }
    rep(i, n) cin >> v[i];
    aut(x, adj)
    {
        aut(y, x) cout << y << " ";
        cout << '\n';
    }

    ll l = -1, r = -1;
    repp(i, n)
    {
        if (adj[i].size())
        {
            if (l == -1) r = i;
            else l = i;
        }
    }
    ll ans = max(sc(n, adj, v, l), sc(n, adj, v, r));

    cout << ans;
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
