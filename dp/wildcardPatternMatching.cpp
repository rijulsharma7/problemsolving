#include<bits/stdc++.h>
using namespace std;

int match(string s, int n, string p, int m, int dp[500][500])
{
	if (n == 0 && m == 0)
		return 1;
	if (m == 0)
		return 0;

	if (n == 0)
	{
		while (m > 0)
		{
			if (p[m - 1] != '*')
				return 0;
			m--;
		}
		return 1;
	}

	if (dp[n][m] != -1)
		return dp[n][m];

	if (p[m - 1] == '*')
		return dp[n][m] = match(s, n - 1, p, m, dp) || match(s, n, p, m - 1, dp);

	else if (p[m - 1] == '?')
		return dp[n][m] = match(s, n - 1, p, m - 1, dp);

	else if (s[n - 1] == p[m - 1])
		return dp[n][m] = match(s, n - 1, p, m - 1, dp);

	else
		return dp[n][m] = 0;

}

int matchh(string s, int n, string p, int m)
{
	bool dp[n + 1][m + 1];
	dp[0][0] = true;

	for (int i = 1; i < n + 1; i++) dp[i][0] = false;
	for (int j = 1; j < m + 1; j++)
	{
		if (p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
		else dp[0][j] = false;
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (p[j - 1] == '*') dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
			else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = false;
		}
	}

	return dp[n][m];
}

bool solve(string s, string p)
{
	int dp[500][500];
	memset(dp, -1, sizeof dp);

	int n = s.size();
	int m = p.size();

	//int ans = match(s, n, p, m, dp);
	bool ans = matchh(s, n, p, m);

	if (ans)
		return true;
	else
		return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1, s2;
	cin >> s1 >> s2;

	if (solve(s1, s2)) cout << "YES\n";
	else cout << " NO\n";
	return 0;
}