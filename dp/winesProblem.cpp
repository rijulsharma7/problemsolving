#include<bits/stdc++.h>
using namespace std;

int profitTopDown(int n, int a[], int y, int start, int end, int dp[100][100])
{
    if(start > end) return 0;
    if(dp[start][end] != 0) return dp[start][end];
    return dp[start][end] = max(a[start]*y + profitTopDown(n ,a, y+1, start+1, end, dp), a[end]*y + profitTopDown(n, a, y+1, start, end-1, dp));
}

int profitBottomUp(int n, int a[], int dp[100][100])
{
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(i == j) dp[i][j] = a[i]*n;
	
	int y = n - 1;
    for(int k=1; k<n; k++)
	{
		int i = 0, j = k;
		while(j < n)
		{
			dp[i][j] = max(dp[i][j-1] + a[j]*y, dp[i+1][j] + a[i]*y);
            i++;j++;
		}
		y--;
	}
    //for(int i=0; i<n; i++) {for(int j=0; j<n; j++) cout << dp[i][j] << " "; cout<< '\n';}
	return dp[0][n-1];
}

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++) cin >> a[i];
    int dp[100][100] = {0};
	cout << profitTopDown(n, a, 1, 0, n-1, dp) << '\n';
    cout << profitBottomUp(n, a, dp) << '\n';
}