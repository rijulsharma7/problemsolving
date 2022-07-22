#include <iostream>
using namespace std;
using ll = long long;
ll M = 1e9 + 7;

ll tilesTopDown(int n, int m, ll* dp) {
	if (n < m) return 1;
	if (dp[n] != -1) return dp[n];
	ll op1 = tilesTopDown(n - 1, m, dp);
	ll op2 = tilesTopDown(n - m, m, dp);
	return dp[n] = (op1 + op2) % M;
}

ll tilesBottomUp(int n, int m, ll* dp)
{
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i < m) dp[i] = 1;
		else if (i == m) dp[i] = 2;
		else dp[i] = dp[i - 1] + dp[i - m];
		dp[i] %= M;
	}
	return dp[n];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		ll dp[n + 1];
		for (int i = 0; i <= n; i++) dp[i] = -1;
		//cout << tilesTopDown(n, m, dp) << '\n';
		cout << tilesBottomUp(n, m, dp) << '\n';
		//for(auto x : dp) cout << x << " ";
		//cout << '\n';
	}
}