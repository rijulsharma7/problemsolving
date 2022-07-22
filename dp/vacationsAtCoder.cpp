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

int topDown(viii &v, int n, int i, int dp[][4], int prev)
{
    if (i == n) return 0;
    if (dp[i][prev] != -1) return dp[i][prev];

    int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;

    if (prev != 1) op1 = fi(v[i]) + topDown(v, n, i + 1, dp, 1);
    if (prev != 2) op2 = se(v[i]) + topDown(v, n, i + 1, dp, 2);
    if (prev != 3) op3 = th(v[i]) + topDown(v, n, i + 1, dp, 3);

    return dp[i][prev] = max(op1, max(op2, op3));
}

int bottomUp(viii &v, int n)
{
    int dp[n][3];
    mem(dp);
    dp[0][0] = fi(v[0]);
    dp[0][1] = se(v[0]);
    dp[0][2] = th(v[0]);
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = fi(v[i]) + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = se(v[i]) + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = th(v[i]) + max(dp[i - 1][1], dp[i - 1][0]);
    }
    return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}

void calc()
{
    viii v;
    int n;
    cin >> n;
    rep(i, n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.pb(mt(a, b, c));
    }
    // int dp[n][4];
    // mem(dp);
    // cout << topDown(v, n, 0, dp, 0) << '\n';
    cout << bottomUp(v, n) << '\n';
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
