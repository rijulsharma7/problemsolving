#include<bits/stdc++.h>
using namespace std;

long long minDistance(string str1, int n1, string str2, int n2, long long dp[500][500])
{
	if (n1 == 0) return n2;
	if (n2 == 0) return n1;

	if (dp[n1][n2] != -1) return dp[n1][n2];

	if (str1[n1 - 1] == str2[n2 - 1])
		return dp[n1][n2] = minDistance(str1, n1 - 1, str2, n2 - 1, dp);
	else
	{
		long long op1, op2, op3;
		op1 = minDistance(str1, n1, str2, n2 - 1, dp); // insert
		op2 = minDistance(str1, n1 - 1, str2, n2, dp); // remove
		op3 = minDistance(str1, n1 - 1, str2, n2 - 1, dp); // replace

		return dp[n1][n2] = 1 + min(op1, min(op2, op3));
	}
}

long long minDistancee(string str1, int n, string str2, int m, long long dp[500][500])
{
	for (int i = 0; i < n + 1; i++) dp[i][0] = i;
	for (int i = 0; i < m + 1; i++) dp[0][i] = i;

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
		}
	}
	return dp[n][m];
}

long long solve(string str1, string str2)
{
	long long dp[500][500];
	memset(dp, 0, sizeof dp);

	int n1 = str1.size();
	int n2 = str2.size();

	// long long ans = minDistance(str1, n1, str2, n2, dp);
	long long ans = minDistancee(str1, n1, str2, n2, dp);
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1, s2;
	cin >> s1 >> s2;

	cout << solve(s1, s2);
	return 0;
}