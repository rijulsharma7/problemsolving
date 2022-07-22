#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
using ml = map<ll, ll>;
using uml = unordered_map<ll, ll>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;
using vll = vector<pl>;
using vlll = vector<tl>;
using pq = priority_queue <ll, vl, greater<ll>>;
using gq = priority_queue <ll>;
#define mem(dp) memset(dp, -1, sizeof(dp))
#define aut(a, b) for (auto&(a) : (b))
#define out(v) for (auto&(x) : (v)) cout << x << " "; cout << '\n';
#define rep(i, n) for (ll (i) = 0; (i) < (n); ++(i) )
#define repp(i, n) for (ll (i) = 1; (i) <= (n); ++(i) )
#define rev(i, n) for (ll (i) = n-1; (i) >= 0; --(i) )
#define revv(i, n) for (ll (i) = n; (i) > 0; --(i) )
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
bool compare(ll a, ll b) {return a > b;}
ll digit(ll n) {return floor(log10(n) + 1);}

bool help(ll grid[1005][1005], ll i, ll j, ll n, ll m, ll s, map<tl, bool> mm) 
{
    if(i==n-1 and j==m-1)
    {
        if(s==0) return true;
        else return false;
    }
    // if(dp[i][j][s] != -1) return dp[i][j][s];
    if(mm.find({i, j, s}) != mm.end()) return mm[{i, j, s}];
    bool chk=false;
    if(i<n)
    {
        chk = help(grid, i+1, j, n, m, s+grid[i+1][j], mm);
    }
    if(!chk and j<m) 
    {
        chk = help(grid, i, j+1, n, m, s+grid[i][j+1], mm);
    }
    return mm[{i,j,s}] = chk;
}

void calc()
{
    ll n,m; cin>>n>>m;
    cout<<n<<" "<<m;
    ll grid[1000][1000]; 
    rep(i, n) rep(j, m) cin>>grid[i][j];
    // int dp[1005][1005][1005];
    // rep(i, n+1) rep(j, m+1) rep(k, n*m) dp[i][j][k]=-1;
    map<tl, bool> mm;
    if(help(grid, 0, 0, n, m, grid[0][0], mm)) cout<<"YES";
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
