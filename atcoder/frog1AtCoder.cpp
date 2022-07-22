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
#define mem(dp) memset(dp, -1, sizeof(dp));
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
ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}
ll gcd(ll a , ll b) {if (b == 0) return a; a %= b; return gcd(b, a);}
ll digit(ll n) {return floor(log10(n) + 1);}

int topDown(int *a, int n, int i, int *dp)
{
    if (i >= n) return 0;
    if (dp[i] != -1) return dp[i];

    int op1 = INT_MAX;
    int op2 = INT_MAX;

    if (i < n - 1) op1 = abs(a[i + 1] - a[i]) + topDown(a, n, i + 1, dp);
    else topDown(a, n, i + 1, dp);

    if (i < n - 2) op2 = abs(a[i + 2] - a[i]) + topDown(a, n, i + 2, dp);
    else topDown(a, n, i + 2, dp);

    return dp[i] = min(op1, op2);
}

int bottomUp(int *a, int n)
{
    int lookup[n] = {0};
    rep(i, n)
    {
        if (i == 0) continue;
        int op1 = INT_MAX;
        int op2 = INT_MAX;
        if (i > 1) op1 = abs(a[i] - a[i - 2]) + lookup[i - 2];
        op2 = abs(a[i] - a[i - 1]) + lookup[i - 1];
        lookup[i] = min(op1, op2);
    }
    //rep(i, n) cout << lookup[i] << " ";
    return lookup[n - 1];
}

void calc()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    int dp[n];
    // memset(dp, -1, sizeof(dp));
    mem(dp);
    cout << topDown(a, n, 0, dp) << '\n';
    // cout << bottomUp(a, n) << '\n';
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