#include<bits/stdc++.h>
using namespace std;

using ll = long long;
bool compare(ll a, ll b) {return a > b;}

ll calcTopDown(ll s, ll n , ll* a, ll dp[500][100])
{
    if (n < 0 || s < 0) return 0;
    if (s == 0) return 1;
    if (dp[s][n] != 0) return dp[s][n];
    return dp[s][n] = calcTopDown(s, n - 1, a, dp) + calcTopDown(s - a[n], n, a, dp);
}

ll calcBottomUp(ll s, ll n, ll* a)
{
    ll dp[s + 1][n];
    for (ll i = 0; i < n; i++) dp[0][n] = 1;

    for (ll i = 1; i <= s; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (s - a[j] > 0) dp[i][j] += dp[i][s - a[j]];
            if (j > 1) dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[s][n - 1];
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
    for (int z = 1; z <= t; z++)
    {
        ll n, m;
        cin >> n >> m;
        ll a[m];
        for (ll i = 0; i < m; i++) cin >> a[i];
        //dp[500][100] = {{0}};
        //cout << calcTopDown(n, m - 1, a, dp) << '\n';
        cout << calcBottomUp(n, m, a) << '\n';
    }

    return 0;
}