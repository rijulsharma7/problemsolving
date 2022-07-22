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
#define aut(a, b) for (auto&(a) : (b))
#define out(x, v) for (auto&(x) : (v)) cout << x << " ";
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
ll mod = 1000000007;
bool compare(ll a, ll b) {return a > b;}
ll gcd(ll a , ll b) {if (b == 0) return a; a %= b; return gcd(b, a);}
ll digit(ll n) {return floor(log10(n) + 1);}

ll dfs(ll n, ll p, vl adj[100007], vll &dp)
{
    ll sum = 0;

    for (auto x : adj[n])
    {
        if (x == p) continue;

        ll xyz = dfs(x, n, adj, dp);
        fi(dp[n]) += (2 * fi(dp[x])) % mod; // combining parent with children nodes
        fi(dp[n]) %= mod;

        se(dp[n]) += (se(dp[x]) % mod); // counting all sets till parent
        se(dp[n]) %= mod;

        sum += fi(dp[x]); // sum of sets of children for a parent
    }

    for (auto x : adj[n])
    {
        if (x == p) continue;

        // pairing children among themselves
        se(dp[n]) += (fi(dp[x]) * ((sum - fi(dp[x]) + mod) % mod)) % mod;
        se(dp[n]) %= mod;
    }
    return (fi(dp[n]) + se(dp[n])) % mod;
}

void calc()
{
    ll n;
    cin >> n;
    vl adj[100007];
    vll dp(n + 1, mp(1, 0));
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cout << dfs(1, 0, adj, dp);
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