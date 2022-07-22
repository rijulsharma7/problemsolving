#include<iostream>
using namespace std;
long long calcTopDown(int n, long long* dp)
{
	if (n <= 0) return 0;
	if (dp[n] != 0) return dp[n];
	return dp[n] = calcTopDown(n - 1, dp) + (n - 1) * calcTopDown(n - 2, dp);
}
long long calcBottomUP(int n)
{

	long long dp[n + 1] = {0};
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
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
		int n;
		cin >> n;
		long long dp[n + 1] = {0};
		dp[1] = 1;
		dp[2] = 2;
		cout << calcTopDown(n, dp) << '\n';
		cout << calcBottomUP(n) << '\n';
	}
	return 0;
}