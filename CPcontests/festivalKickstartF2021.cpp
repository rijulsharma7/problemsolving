#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
using ml = map<ll, bool>;
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
    multiset<ll, greater<ll>> g;
    multiset<ll> p;
    ll d, n, k;
    cin>>d>>n>>k;
    vlll v;
    rep(i, n)
    {
        ll x, y, z;
        cin>>x>>y>>z;
        v.push_back({y, x, 0});
        v.push_back({z+1, x, 1});
    }
    sort(all(v));
    ll res = 0, a = 0, b = 0, cnt = 0;
    aut(x, v)
    {
        ll s = se(x);
        if(th(x) == 0)
        {
            if(p.size() < k)
            {
                a += s;
                p.insert(s);
            }
            else
            {
                if (*p.begin() < s) // min from largest k
                {
                    a -= *p.begin();
                    a += s;
                    g.insert(*p.begin());
                    p.erase(p.begin());
                    p.insert(s);
                }
                else
                {
                    g.insert(s); // element less than minimum from k largest elements
                }
                // a += s;
                // p.insert(s);
                // a -= *p.begin();
                // b += *p.begin();
                // g.insert(*p.begin());
                // p.erase(p.begin());
            }
            cnt++;
        }
        else if(th(x) == 1)
        {
            if(!g.empty() && *g.begin()>=s)
            {
                g.erase(g.find(s));
                b -= s;
            }
            else
            {
                a -= s;
                p.erase(p.find(s));
                if(!g.empty())
                {
                    p.insert(*g.begin());
                    a += *g.begin();
                    b -= *g.begin();
                    g.erase(g.begin());
                }
            }
            // if(cnt <= k)
            // {
            //     a -= s;
            //     p.erase(p.find(s));
            // }
            // else
            // {
            //     ll ele = *p.begin();
            //     if(s >= ele)
            //     {
            //         a -= s;
            //         p.erase(p.find(s));
            //         if(!g.empty())
            //         {
            //             p.insert(*g.begin());
            //             a += *g.begin();
            //             b -= *g.begin();
            //             g.erase(g.begin());
            //         }
            //     }
            //     else if(s < ele)
            //     {
            //         g.erase(g.find(s));
            //         b -= s;
            //     }
            // }
            cnt--;
        }
        cout << a << endl;
        res = max(res, a);
        //  cout << p.size() << " " << cnt << endl;
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
    repp(z, t)
    {
        cout << "Case #" << z << ": ";
        calc();
        cout << '\n';
    }

    return 0;
}
