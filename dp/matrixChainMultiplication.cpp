#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
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
#define rep(a, b) for (auto&(a) : (b))
#define out(x, v) for (auto&(a) : (b)) cout << x << " ";
#define FOR(i, n) for (ll (i) = 0; (i) < (n); (++i) )
#define FORR(i, n) for (ll (i) = 1; (i) <= (n); (++i) )
#define all(v) v.begin(), v.end()
#define fi get<0>
#define se get<1>
#define th get<2>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define bl '\n'
ll inf = 1e18;
ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}
ll gcd(ll a , ll b) {if (b == 0) return a; a %= b; return gcd(b, a);}

ll topDown(ll *arr, ll i, ll j, ll dp[200][200])
{
    if (dp[i][j] != -1) return dp[i][j];

    if (i == j) return 0;
    ll res = INT_MAX;

    for (ll k = i; k < j; k++)
    {
        ll ans = topDown(arr, i, k, dp) + topDown(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
        res = min(res, ans);
    }
    return dp[i][j] = res;
}

ll bottomUp(ll *a, ll n)
{
    ll mat[n + 1][n + 1];

    FORR(i, n) mat[i][i] = 0;

    for (ll c = 2; c <= n; c++)
    {
        for (ll i = 1; i <= n - c + 1; i++)
        {
            ll j = i + c - 1;
            mat[i][j] = 1e18;
            for (ll k = i; k < j; k++)
            {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k + 1][j] + (a[i - 1] * a[k] * a[j]) );
            }
        }
    }
    return mat[1][n - 1];
}

int main()
{
    ll arr[] = { 1, 2, 3, 4, 3 };
    ll n = sizeof(arr) / sizeof(ll);
    //cout << n << " ";

    ll dp[200][200];
    memset(dp, -1, sizeof dp);


    cout << topDown(arr, 1, n - 1, dp) << bl;
    cout << bottomUp(arr, n) << bl;

    return 0;
}
