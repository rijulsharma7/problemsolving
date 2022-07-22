#include<bits/stdc++.h>
using namespace std;

using ll = long long;

bool calcTopDown(string s, ll l, ll r, ll dp[1001][1001])
{
    if (l == r) return true;
    if (l > r) return false;
    if (dp[l][r] != -1) return dp[l][r];
    if (s[l] == s[r])
    {
        if (l + 1 == r) return true;
        else return dp[l][r] = calcTopDown(s, l + 1, r - 1, dp);
    }
    else return false;
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

    ll n;
    cin >> n;
    string s;
    cin >> s;
    //ll dp[1001][1001];
    //for (int i = 0; i < 1005; i++) for (int j = 0; j < 1005; j++) dp[i][j] = -1;
    int lookup[n + 1][n + 1];
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) {if (i == j || i == 0) lookup[i][j] = 1; else lookup[i][j] = -1;}
    for (int i = n; i > 0; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (s[i - 1] != s[j - 1]) lookup[i][j] = 0;
            else
            {
                if (i + 1 > j - 1) lookup[i][j] = 1;
                else if (lookup[i + 1][j - 1] == 1) lookup[i][j] = 1;
                else lookup[i][j] = 0;
            }
        }
    }
    //for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) cout << lookup[i][j] << " ";
    ll m;
    cin >> m;
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        if (lookup[l][r] == 1) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
