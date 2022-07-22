#include<bits/stdc++.h> 
using namespace std; 

using ll = long long;
using vi = vector<ll>;
using vl = vector<ll>;
using pi = pair<ll, ll>;
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
    unordered_set<ll> s;
    for(ll i=0; i<=n-2; i++)
    {
        ll j = i+1;
        ll m1 = max(a[j], a[i]);
        ll m2 = min(a[j], a[i]);
        j++;
        s.insert(m1 - m2);
        while(j < n)
        {
            if(a[j] > m1) 
            {
                m2 = m1;
                m1 = a[j];
            }
            else if(a[j] > m2) m2 = a[j];
            s.insert(m1 - m2);
            j++;
        }
    }
    cout << s.size();
}

signed main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t = 1;
    cin >> t;
    
    while(t--)
    {
        calc();
        cout << '\n';
    }
    
    return 0;
}
