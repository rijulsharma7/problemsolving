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
    int n;
    cin >> n;
    int w[n+1], l[n+1];
    for(int i=1; i<=n; i++) cin >> w[i];
    for(int i=1; i<=n; i++) cin >> l[i];

    vector<tuple<int,int,int>> v;
    v.push_back({0,0,0});
    for(int i=1; i<=n; i++) v.push_back({w[i],i,l[i]});
    sort(v.begin(), v.end());
    //for(auto x : v) cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << '\n';
    
    int prev = get<1>(v[1]), res = 0;
    for(int i=2; i<=n; i++)
    {
        int idx = get<1>(v[i]);
        while(idx <= prev)
        {
            idx += get<2>(v[i]);
            res++;
        }
        prev = idx;
    }
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
