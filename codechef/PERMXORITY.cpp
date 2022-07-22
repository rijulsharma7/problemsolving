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
    if(n&1)
    {
        revv(i, n) cout<<i<<" ";
    }
    else if(n==4)
    {
        cout<<1<<" "<<4<<" "<<2<<" "<<3;
    }
    else if(n == 6)
    {
        cout<<5<<" "<<2<<" "<<3<<" "<<6<<" "<<4<<" "<<1;
    }
    else if(n==2)
    {
        cout<<-1;
    }
    else
    {
        vl a, b, c;
        ll x = 1, y, z;
        while(x<=n) 
        {
            a.pb(x); x+=3;
        }
        x = 2;
        while(x<=n) 
        {
            b.pb(x); x+=3;
        }
        x = 3;
        while(x<=n) 
        {
            c.pb(x); x+=3;
        }
        x = a[a.size()-1], y = b[b.size()-1], z = c[c.size()-1];
        // cout<<x<<y<<z<<'\n';
        if(abs(x-y) == 2)
        {
            if(x>y)
            {
                rep(i, a.size())
                {
                    cout<<a[i]<<" ";
                }
                rev(i, b.size())
                {
                    cout<<b[i]<<" ";
                }
            }
            else
            {
                rep(i, b.size())
                {
                    cout<<b[i]<<" ";
                }
                rev(i, a.size())
                {
                    cout<<a[i]<<" ";
                }
            }
            rep(i, c.size())
            {
                cout<<c[i]<<" ";
            }
        }
        else if(abs(x-z) == 2)
        {
            rep(i, a.size())
            {
                cout<<a[i]<<" ";
            }
            rev(i, c.size())
            {
                cout<<c[i]<<" ";
            }
            rep(i, b.size())
            {
                cout<<b[i]<<" ";
            }
        }
        else if(abs(z-y) == 2)
        {
            rep(i, c.size())
            {
                cout<<c[i]<<" ";
            }
            rev(i, b.size())
            {
                cout<<b[i]<<" ";
            }
            rep(i, a.size())
            {
                cout<<a[i]<<" ";
            }
        }
        else cout<<-1;
        
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
