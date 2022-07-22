#include<bits/stdc++.h>
using namespace std;

int minCoinTopDown(int n, int coins[], int size, int* dp)
{
	if(n == 0) return 0;
	if(dp[n] != 0) return dp[n];

    int res = INT_MAX; 
	for(int i=0; i<size; i++)
	{
		if(n - coins[i] >= 0)
		{
		    int ans = minCoinTopDown(n-coins[i], coins, size, dp);
		    res = min(res, ans+1);
	    }
	}
	return dp[n] = res;
}

int minCoinBottomUp(int n, int coins[], int size, int* dp)
{
	for(int i=1; i<=n; i++)
	{
		int res = INT_MAX;
		for(int j=0; j<size; j++)
		{
			if(i - coins[j] >= 0)
			{
				int ans = dp[i-coins[j]];
				res = min(res, ans+1);
			}
		}
		dp[i] = res;
	}
	return dp[n];
}

int main()
{
	int n;
	cin >> n;
	int coins[] = {1, 7, 10};
	int size = sizeof(coins)/sizeof(int);
	int dp[n+1] = {0};
	cout << minCoinTopDown(n, coins, size, dp) << '\n';
	cout << minCoinBottomUp(n, coins, size, dp) << '\n';
}