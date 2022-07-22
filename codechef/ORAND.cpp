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
    ll n, m;
    cin >> n >> m;

    vl vn(n), vm(m);
    for(ll i=0; i<n; i++) cin >> vn[i];
    for(ll i=0; i<m; i++) cin >> vm[i];

    vl v(1e6*2,0);
    v[0] = 1;
    queue <ll> q;
    q.push(0);

    while(1)
    {
        ll e = q.front();
        q.pop();
        for(auto x : vn)
        {
            ll y = e|x;
            if(v[y] != 1)
            {
                v[y] = 1;
                q.push(y);
            }
        }
        for(auto x : vm)
        {
            ll y = e&x;
            if(v[y] != 1)
            {
                v[y] = 1;
                q.push(y);
            }
        }
        if(q.empty()) break;
    }
    
    ll cnt = 0;
    for(auto x : v) if(x == 1) cnt++;
    cout << cnt;
    
    return;
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