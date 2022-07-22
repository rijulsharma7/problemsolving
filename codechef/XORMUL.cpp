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
    ll n, a, b; cin>>n>>a>>b;
    ll aa=a, bb=b;
    bool f = true;
    vl v(n, 0), v1(n, 0), v2(n, 0);
    ll i=n-1;
    while(a)
    {
        v1[i] += a&1;
        i--;
        a>>=1;
    }
    // out(v);
    i=n-1;
    while(b)
    {
        v2[i] += b&1;
        i--;
        b>>=1;
    }
    ll vv; 
    ll x=0, res=0;
    rev(i, n)
    {
        if(v1[i]==v2[i])
        {
            v[i] = (v1[i]+1)%2;
            res += v[i]*(ll)(pow(2, x));
            x++;
        }
        else
        {
            res += (ll)(pow(2, x));
            vv = (ll)(pow(2, x));
            x++;
            
        }
    }
    // rep(k, vv.size()-1) res+=vv[k];
    cout<<res-vv;
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
