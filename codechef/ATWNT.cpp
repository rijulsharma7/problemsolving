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
    ll child[n+1] = {0};
    ll parent[n+1] = {0};
    bool check[n+1];
    for(ll u=2; u<=n; u++)
    {
        cin >> parent[u];
        child[parent[u]]++;
    }

    vll v;
    v.push_back({0,0});
    for(ll u=1; u<=n; u++) v.push_back({child[u],parent[u]});

    //for(auto x : v) cout << get<0>(x) << " " << get<1>(x) << '\n';

    ll q;
    cin >> q;
    while(q--)
    {
        ll ans = 0;
        ll weight[n+1] = {0};
        memset(check,true,sizeof(check));
        ll i, w;
        cin >> i >> w;
        if(i == 1) 
        {
            if((w%get<0>(v[1])) != 0) {cout << w << '\n'; continue;} else weight[1] = w/get<0>(v[1]);
            for(ll u=2; u<=n; u++)
            {
                if(!check[get<1>(v[u])])
                {
                   check[u] = false;
                   continue;
                }
                if(get<0>(v[u]) == 0) continue;
                if( (weight[get<1>(v[u])]%get<0>(v[u])) != 0) 
                {
                    ans += weight[get<1>(v[u])];
                    check[u] = false;
                }
                else weight[u] = weight[get<1>(v[u])]/get<0>(v[u]);
                //cout << ans << '\n';
            }
        }
        else
        {
            if(get<0>(v[i]) == 0) { cout << 0 << '\n'; continue; }
            if((w%get<0>(v[i])) != 0) {cout << w << '\n'; continue;} else weight[i] = w/get<0>(v[i]);
            for(ll u=i+1; u<=n; u++)
            {
                if(!check[get<1>(v[u])] || (get<1>(v[u]) < i) )
                {
                   check[u] = false;
                   continue;
                }
                if(get<0>(v[u]) == 0) continue;
                if( (weight[get<1>(v[u])]%get<0>(v[u])) != 0) 
                {
                    ans += weight[get<1>(v[u])];
                    check[u] = false;
                }
                else weight[u] = weight[get<1>(v[u])]/get<0>(v[u]);
            }
        }
        cout << ans << '\n';
    }
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    //cin >> t;
    
    while(t--)
    {
        calc();
        cout << '\n';
    }
    
    return 0;
}
