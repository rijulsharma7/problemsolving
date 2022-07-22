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
    n*=2;
    vl a(n); rep(i, n) cin>>a[i];
    ll o=0, e=0;
    bool f=false;
    vl v;
    rep(i, n)
    {
        if(a[i]&1) o++;
        else e++;
        ll c=0; f=false;
        while(a[i])
        {
            if(a[i]&1) 
            {
                f=true;
                break;
            }
            c++;
            a[i]=a[i]/2;
        }
        if(c and f) v.pb(c);
    }
    // cout<<o<<" "<<e<<'\n';
    // out(s);
    sort(all(v)); 
    if(o==e) cout<<0;
    else if(o>e) cout<<(o-e)/2;
    else
    {
        ll x=(e-o)/2;
        ll r=0;
        // out(s);
        rep(i, x) r+= v[i];
        cout<<r;
    }
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
        cout << '\n';
    }

    return 0;
}
