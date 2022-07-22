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
    ll n;
    cin >> n;
    ll a[n];
    for(ll i=0; i<n; i++) cin >> a[i];
    ll min = a[0];
    bool flag = true, f = false;
    for(ll i=0; i<n-1; i++)
    {
        if(a[i] != a[i+1]) f = true;
        if(a[i] < a[i+1]) 
        {
            flag = false;
            break;
        }
    }
    if(!flag && f) cout << "YES";
    else cout << "NO";
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
