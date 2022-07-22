#include <iostream>
using namespace std;
using ll = long long;

ll countOccurrenceTopDown(string a, string b, int n, int m, ll dp[100][100])
{
	if (m < 0) return 1;
	if (n < 0) return 0;
	if (dp[n][m] != -1) return dp[n][m];
	if (a[n] == b[m])
		return dp[n][m] = (countOccurrenceTopDown(a, b, n - 1, m - 1, dp) + countOccurrenceTopDown(a, b, n - 1, m, dp));
	else
		return dp[n][m] = countOccurrenceTopDown(a, b, n - 1, m, dp);
}

ll countOccurrenceBottomUp(string a, string b, int n, int m)
{
	ll dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) dp[i][j] = -1;
	for (int i = 0; i <= m; i++) dp[0][i] = 0;
	for (int i = 0; i <= n; i++) dp[i][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j];
		}
	}
	return dp[n][m];
}

int main()
{
	string a, b;
	cin >> a >> b;
	int n = a.size();
	int m = b.size();
	ll dp[100][100];
	for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) dp[i][j] = -1;
	cout << countOccurrenceTopDown(a, b, n - 1, m - 1, dp) << '\n';
	cout << countOccurrenceBottomUp(a, b, n, m) << '\n';
}