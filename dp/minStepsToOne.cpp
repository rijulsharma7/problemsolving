#include<bits/stdc++.h>
using namespace std;

int minStepsTopDown(int n, int* dp)
{
	if(n < 2) return 0;
	if(dp[n] != -1) return dp[n];
	int x = INT_MAX, y = INT_MAX, z;
	if(n % 3 == 0) x = minStepsTopDown(n/3, dp);
	if(n % 2 == 0) y = minStepsTopDown(n/2, dp);
	z = minStepsTopDown(n-1, dp);
	return dp[n] = min(x, min(y, z)) + 1;
}

int minStepsBottomUp(int n, int* dp)
{
	for(int i=2; i<=n; i++)
	{
		int x = INT_MAX, y = INT_MAX, z;
		if(i % 3 == 0) x = dp[i/3];
	    if(i % 2 == 0) y = dp[i/2];
	    z = dp[i-1];
		dp[i] = min(x, min(y, z)) + 1;
	}
	return dp[n];
}

int main()
{
	int n;
	cin >> n;
	
	int dp[n+1];
    memset(dp,-1,sizeof(dp));
	dp[0] = dp[1] = 0;

	cout << minStepsTopDown(n, dp) << '\n';
	cout << minStepsBottomUp(n, dp) << '\n';

	return 0;
}