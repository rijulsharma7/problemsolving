#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
using ml = map<ll, ll>;
using uml = unordered_map<ll, ll>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;
using vll = vector<pl>;
using vlll = vector<tl>;
using pq = priority_queue <ll, vl, greater<ll>>;
using gq = priority_queue <ll>;
#define mem(dp) memset(dp, -1, sizeof(dp))
#define aut(a, b) for (auto&(a) : (b))
#define out(v) for (auto&(x) : (v)) cout << x << " "; cout << '\n';
#define rep(i, n) for (ll (i) = 0; (i) < (n); ++(i) )
#define repp(i, n) for (ll (i) = 1; (i) <= (n); ++(i) )
#define rev(i, n) for (ll (i) = n-1; (i) >= 0; --(i) )
#define revv(i, n) for (ll (i) = n; (i) > 0; --(i) )
#define all(v) v.begin(), v.end()
#define fi get<0>
#define se get<1>
#define th get<2>
#define F first
#define S second
#define mp 
#define mt make_tuple
#define pb push_back
ll inf = 1e18; ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}
ll digit(ll n) {return floor(log10(n) + 1);}


void calc()
{
    ll n; cin>>n;
    vl v(n, 0);
    set<ll> ss;
    vll vec;
    rep(i, n)
    {
        ll x, y;
        cin>>x>>y;
        --x;--y;
        vec.pb({x, 0});
        vec.pb({y, 1});
        if(i>=x and i<=y) ss.insert(i+1);
    }
    sort(all(vec)); 
    // aut(x, vec) cout<<x.F+1<<" "<<x.S<<'\n';
    ll cnt=0;
    for(ll i=0; i<vec.size(); i++)
    {
        ll x=vec[i].first, y=vec[i].second;
        // cout<<x+1<<" "<<y<<" "<<cnt<<'\n';
        if(y==0)
        {
            if(i>0) for(int j=vec[i-1].first+1; j<x; j++) v[j]=cnt;
            cnt++;
            v[x]=cnt;
        }
        else if(vec[i-1].first==x and vec[i-1].second==1) 
        {
            cnt--;
        }
        else
        {
            for(int j=vec[i-1].first+1; j<=x; j++)
            {
                v[j]=cnt;
            }
            cnt--;
        }
    }
    // out(v);
    set<ll> s;
    ll b=INT_MIN;
    for(ll i=0; i<v.size(); i++) 
    {
        if(v[i]>b and ss.find(i+1)==ss.end())
        {
            s.clear();
            s.insert(i+1);
            b=v[i];
        }
        else if(v[i]==b)
        {
            if(ss.find(i+1)==ss.end()) s.insert(i+1);
        }
    }
    cout<<s.size()<<'\n';
    for(auto x:s) cout<<x<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    repp(z, t)
    {
        //cout << "Case #" << z << ": ";
        calc();
        // cout << '\n';
    }

    return 0;
}
