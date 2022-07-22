#include<bits/stdc++.h> 
using namespace std; 

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vii = vector<pi>;
using vll = vector<pl>;

bool compare(ll a, ll b) {return a > b;}

ll ans(ll *a, ll x, ll y, ll z) { return abs(a[x]-a[y]) + abs(a[z]-a[y]) + abs(a[x]-a[z]); }

void calc()
{
    ll n;
    cin >> n;
    ll a[n];
    for(ll i=0; i<n; i++) cin >> a[i];
    sort(a,a+n);
    
    ll x = 0, y, z = n-1, res = 0;
    for(ll i=1; i<n-1; i++) res = max( res, ans(a,x,i,z) );  
    cout << res;
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
        calc();
        cout << '\n';
    }
	
    return 0;
}
