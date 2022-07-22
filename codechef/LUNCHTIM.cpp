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
    ll h[n];
    for(ll i=0; i<n; i++) cin >> h[i];
    ll c[n] = {0};
    stack<pair<ll, ll>> s;
    s.push({0,0})
    for(ll i=1; i<n; i++)
    {
        if(h[s.top().first] == h[i])
        {
            s.push({i, s.top().second+1});
        }
        else if(h[s.top().first] > h[i]) s.push({i, 0});
        else 
        {
            ll max = s.top().second;
            ll idx = s.top().first;
            c[idx] = max;
            s.pop();
            while(!s.empty() && h[s.top().first] < h[i])
            {
                if( h[s.top().first] == h[idx]) 
                {
                    c[s.top().first] = max;
                    s.pop();
                    continue;
                }
                else
                {
                    max = s.top().second;
                    idx = s.top().first;
                    c[idx] = max;
                    s.pop();
                }
            }
            if(s.empty()) s.push({i, 0});
            else if(h[s.top().first] == h[i]) s.push({i, s.top().second+1});
            else s.push({i, 0});
        }
    }
    if(!s.empty())
    {
        ll max = s.top().second;
        ll idx = s.top().first;
        c[idx] = max;
        s.pop();
        while(!s.empty() )
        {
            if( h[s.top().first] == h[idx]) 
            {
                c[s.top().first] = max;
                s.pop();
                continue;
            }
            else
            {
                max = s.top().second;
                idx = s.top().first;
                c[idx] = max;
                s.pop();
            }
        }
    }
    
    for(auto x : c) cout << x << " ";

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
