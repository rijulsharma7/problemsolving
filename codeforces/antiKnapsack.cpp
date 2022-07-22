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

void calc()
{
    ll n, k;
    cin >> n >> k;
    cout << (n - 1 - (k - 1)/ 2) << '\n';
    for(ll i=k+1; i<=n; i++) cout << i << " ";
    for(ll i=(k-1)/2+1; i<k; i++) cout << i << " ";
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
