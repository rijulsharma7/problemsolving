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

ll lb(vl v, ll x)
{
    return lower_bound(v.begin(), v.end(), -1*x) - v.begin();
}

ll ub(vl v, ll x)
{
    return upper_bound(v.begin(), v.end(), -1*x) - v.begin();
}

ll solve(ll n)
{
    vl v[n];
    unordered_map<ll,ll> m;
    for(int i=0; i<n; i++)
    {
        ll m;
        cin >> m;
        while(m--) 
        {
            ll e; 
            cin >> e;
            m[abs(e)]++;
            v[i].push_back(e);
        }
        sort(v[i].begin(), v[i].end());
    }
    ll ans = 0;
    for(auto x : m) if(x.second > 1) ans++;
    for(ll i=0; i<n; i++)
    {
        ll idx = 0;
        for(auto x : v[i])
        {
            if(freq[x] > 1)
            {
                if(x > 0) ans += v[i].size() - idx - 1;
                else ans += idx;
            }
            else
            {
                if(x > 0) ans += lb(v[i],x);
                else ans += ( v[i].size() - ub(v[i],x) );
            }
            idx++;
        }
    }
    return ans;
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
