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
#define out(v) for (auto&(x) : (v)) cout << x;
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
#define mp make_pair
#define mt make_tuple
#define pb push_back
ll inf = 1e18; ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}
ll digit(ll n) {return floor(log10(n) + 1);}

void calc()
{
    ll n; cin>>n;
    string s; cin>>s;
    vl r;
    bool f = true;
    aut(x, s)
    {
        if(x!='9') f=false;
        r.pb(('9'-x));
    }
    if(f) 
    {
        rep(i, n-1) cout<<1;
        cout<<2;
    }
    else if(s[0]=='9')
    {
        vl res; 
        // cout<<res<<" ";
        rep(i, n-1) res.pb(1);
        res.pb(2);
        vl re(n);
        ll c=0;
        // out(r);
        // cout<<'\n'; out(res) cout<<'\n';
        rev(i, n)
        {
            ll x = (int) res[i];
            ll y = (int) r[i];
            // cout<<x<<" "<<y<<" "<<x+y<<"\n";
            ll z = x+y+c;
            re[i]=z%10;
            z/=10;
            c=z%10;
        }
        out(re);
    }
    else out(r);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    repp(z, t)
    {
        //cout << "Case #" << z << ": ";
        calc();
        cout << '\n';
    }

    return 0;
}
