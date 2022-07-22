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
    
    vector<string> v;
    vector<string> vs;
    unordered_map<string,ll> m;
    ll t = 0;
    for(ll i=0; i<n; i++) 
    {
        string s; 
        cin >> s;
        v.push_back(s);
        vs.push_back(s.substr(1,s.length()));
        m[v[i]] = t;
        t++;
    }
    
    //for (auto x : m) cout << x.first << " " << x.second << endl; 
    
    ll res = 0;
    for(ll i=0; i<n-1; i++)
    {
        for(ll j=i+1; j<n; j++)
        {
            if( (v[i][0] == v[j][0]) || (vs[i] == vs[j]) ) continue;
            swap(v[i][0],v[j][0]);
            if(!m.count(v[i]) && !m.count(v[j])) res++;
            swap(v[i][0],v[j][0]);
        }
    }
    
    cout << 2*res;
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
