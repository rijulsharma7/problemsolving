#include<bits/stdc++.h> 
using namespace std; 

int fibonacci(int n)
{
    if(n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int fiboTopDown(int n, int* dp)
{
    if(n <= 1) return dp[n];
    if(dp[n] != 0) return dp[n];
    dp[n] = fiboTopDown(n-1, dp) + fiboTopDown(n-2, dp);
    return dp[n];
}

int fiboBottomUp(int n, int* dp)
{
    for(int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

int fiboSpaceOptimisation(int n)
{
    if(n <= 1) return n;
    int a = 0, b = 1, res;
    for(int i = 2; i <= n; i++)
    {
        res = a + b;
        a = b;
        b = res;
    }
    return res;
}

int fiboFormula(int n)
{ 
    int res = round( pow( ( ( sqrt(5) + 1) / 2) , n) / sqrt(5) ); 
    return res;
}

int main() 
{ 
    
    int t;
    cin >> t;

    int dp[100] = {0};
    dp[1] = 1;

    cout << fibonacci(t) << endl;
    cout << fiboTopDown(t, dp) << endl;
    cout << fiboBottomUp(t, dp) << endl;
    cout << fiboSpaceOptimisation(t) << endl;
    cout << fiboFormula(t) << endl;
	
    return 0;
}
