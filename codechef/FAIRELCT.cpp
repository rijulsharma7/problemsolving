#include<bits/stdc++.h> 
using namespace std; 

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vii = vector<pi>;
using vll = vector<pl>;

bool compare(ll a, ll b)
{
    return a > b;
}

ll solve(ll n, ll m)
{
    ll a[n];
    ll b[m];
    ll sa = 0, sb = 0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        sa += a[i];
    }
    for(int i=0; i<m; i++)
    {
        cin >> b[i];
        sb += b[i];
    }
    if(sa > sb) return 0;
    sort(a,a+n);
    sort(b,b+m,compare);
    ll i = 0, j = 0, cnt = 0;
    while(i < n-1 && j < m-1)
    {
        cnt++;
        sa -= a[i];
        sa += b[j];
        sb -= b[j];
        sb += a[i];
        i++;
        j++;
        if(sa > sb) return cnt;
    }
    return -1;
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while(t--)
    {
        ll n, m;
        cin >> n >> m; 
        
        //solve(n);
        cout << solve(n,m);
        
        cout << '\n';
        
    }
	
    return 0;
}
