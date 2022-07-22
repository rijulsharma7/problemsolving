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
#define fi get<0>
#define se get<1>
#define th get<2>
#define mp make_pair
#define mt make_tuple
#define pb push_back
ll inf = 1e18;
ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}

ll calcTopDown(int n, int l, ll dp[95][2])
{
    if (n == 1)
    {
        if (l == 0) return 2;
        else return 1;
    }
    if (dp[n][l] != -1) return dp[n][l];
    if (l == 0) return dp[n][l] = (calcTopDown(n - 1, 0, dp) + calcTopDown(n - 1, 1, dp)) ;
    else return dp[n][l] = calcTopDown(n - 1, 0, dp);
}

ll calcBottomUp(int n)
{
    ll lookup[n + 1][2];
    lookup[0][0] = 1;
    lookup[1][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        lookup[0][i] = lookup[0][i - 1] + lookup[1][i - 1];
        lookup[1][i] = lookup[0][i - 1];
    }
    return lookup[0][n];
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
    for (int z = 1; z <= t; z++)
    {
        int n;
        cin >> n;
        ll dp[95][2];
        for (int i = 0; i <= n; i++) for (int j = 0; j < 2; j++) dp[i][j] = -1;
        cout << calcTopDown(n, 0, dp) << '\n';
        cout << calcBottomUp(n) << '\n';
    }

    return 0;
}
