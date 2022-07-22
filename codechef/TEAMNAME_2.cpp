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
    vector<pair<char, vector<string>>> vp;
    unordered_map<char, vector<string>> m;
    
    for(ll i=0; i<n; i++) 
    {
        string s, ss; 
        cin >> s;
        v.push_back(s);
        ss = s.substr(1,s.length());
        m[s[0]].push_back(ss);
    }
    //for (auto x : m) cout << x.first << " " << x.second << endl; 
    for(auto x : m) vp.push_back({get<0>(x),get<1>(x)});
    
    ll res = 0;
    unordered_set<string> s;
    for(ll i=0; i<vp.size()-1; i++)
    {
        for(ll k=0; k<(get<1>(vp[i])).size(); k++) s.insert(get<1>(vp[i])[k]);
        for(ll j=i+1; j<vp.size(); j++)
        {
            ll t = 0;
            for(ll k=0; k<(get<1>(vp[j])).size(); k++) if(s.count(get<1>(vp[j])[k])) t++;
            res += (get<1>(vp[i]).size() - t)*(get<1>(vp[j]).size() - t);
        }
        s.clear();
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