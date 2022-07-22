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


void solve(ll n)
{
    ll k, ll d;
    cin >> k >> d;
    ll a[n];
    ll s =0;
    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    s /= k;
    if(s > d) return d;
    else return s;
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
        ll n;
        cin >> n; 
        
        //solve(n);
        cout << solve(n);
        
        cout << '\n';
        
    }
	
    return 0;
}
