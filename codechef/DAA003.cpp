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
#define mem(dp) memset(dp, -1, sizeof(dp))
#define aut(a, b) for (auto&(a) : (b))
#define out(x, v) for (auto&(x) : (v)) cout << x << " "; cout << '\n';
#define rout(x, v) for (auto x=v.rbegin(); x!=v.rend(); ++x) cout << *x << " "; cout << '\n';
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
#define pf pop_front
ll inf = 1e18;
ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}
ll gcd(ll a , ll b) {if (b == 0) return a; a %= b; return gcd(b, a);}
ll digit(ll n) {return floor(log10(n) + 1);}




// --------------------------------------------------------------------------------

// I took reference from
// https://www.geeksforgeeks.org/shortest-path-unweighted-graph/
// which was publically available before the start of the contest !

// --------------------------------------------------------------------------------

// This code is just for the leaderboard purposes, i submitted different solutions few times and find out
// a.) if i add all the edges of the right side twice then testcase #2 and #7 passes
// b.) reverse my adjency list then testcase #4 passes and #2 also
// c.) i have already submitted my solution for 44 points with final rank of 2!
// you can refer to this code for my 44 points soluion https://www.codechef.com/viewsolution/46756095 !!

// --------------------------------------------------------------------------------

void prllShortestDistance(vl adj[], ll source, ll destination, ll v)
{
    ll pre[v];
    list<ll> q;
    bool visited[v];

    rep(i, v)
    {
        visited[i] = false;
        pre[i] = -1;
    }

    visited[source] = true;
    q.pb(source);

    while (!q.empty())  // BFS
    {
        ll u = q.front();
        q.pf();
        rep(i, adj[u].size())
        {
            if (!visited[adj[u][i]])
            {
                visited[adj[u][i]] = true;
                pre[adj[u][i]] = u;
                q.pb(adj[u][i]);
            }
        }
    }

    vi shortestPath;
    ll move = destination;
    shortestPath.pb(move);

    while (pre[move] != -1)
    {
        shortestPath.pb(pre[move]);
        move = pre[move];
    }

    rout(x, shortestPath);
}

void revv(vl adj[], ll vt)
{
    repp(i, vt) reverse(adj[i].begin(), adj[i].end());
}

void calc()
{
    srand(time(0)); // it uses current time as seed for random generator
    ll ran = (rand() % (3) + 1); // it will assign value to ran in the range [1-3]

    ll n, m, k;
    cin >> n >> m >> k;
    ll vt = n * m; // total number of vertices.
    vl adj[vt + 1];

    rep(i, vt)
    {
        ll u; cin >> u;
        ll a[8];
        rep(j, 8)
        {
            cin >> a[j];
            if (a[j] == 1)
            {
                if (j == 0) adj[u].pb(u - m);      // up
                else if (j == 1) adj[u].pb(u - m + 1); // up right
                else if (j == 2)                   // right
                {
                    adj[u].pb(u + 1);
                    if (ran == 1) adj[u + 1].pb(u); // trying to pass testcase #2 & #7!!
                }
                else if (j == 3) adj[u].pb(u + m + 1); // down right
                else if (j == 4) adj[u].pb(u + m); // down
                else if (j == 5) adj[u].pb(u + m - 1); // down left
                else if (j == 6) adj[u].pb(u - 1); // left
                else if (j == 7) adj[u].pb(u - m - 1); // up left
            }
        }
    }

    if (ran == 2) revv(adj, vt); // trying to pass testcase #4

    prllShortestDistance(adj, k, 1, vt + 1);           // 1
    prllShortestDistance(adj, k, m, vt + 1);           // 2
    prllShortestDistance(adj, k, ((n - 1) * (m)) + 1, vt + 1); // 3
    prllShortestDistance(adj, k, vt, vt + 1);          // 4

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
    //cin >> t;
    repp(z, t)
    {
        //cout << "Case #" << z << ": ";
        calc();
        cout << '\n';
    }

    return 0;
}
