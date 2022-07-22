#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
using mi = map<int, int>;
using ml = map<ll, ll>;
using umi = unordered_map<int, int>;
using uml = unordered_map<ll, ll>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ti = tuple<int, int, int>;
using tl = tuple<ll, ll, ll>;
using vii = vector<pi>;
using viii = vector<ti>;
using vll = vector<pl>;
using vlll = vector<tl>;
using pq = priority_queue <ll, vl, greater<ll>>;
using gq = priority_queue <ll>;
#define mem(dp) memset(dp, -1, sizeof(dp))
#define aut(a, b) for (auto&(a) : (b))
#define out(x, v) for (auto&(x) : (v)) cout << x << " "; cout << '\n';
#define rep(i, n) for (ll (i) = 0; (i) < (n); ++(i) )
#define repp(i, n) for (ll (i) = 1; (i) <= (n); ++(i) )
#define all(v) v.begin(), v.end()
#define fi get<0>
#define se get<1>
#define th get<2>
#define F first
#define S second
#define mp make_pair
#define mt make_tuple
#define pb push_back
ll inf = 1e18;
ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}
ll gcd(ll a , ll b) {if (b == 0) return a; a %= b; return gcd(b, a);}
ll digit(ll n) {return floor(log10(n) + 1);}

void calc()
{
    ll k;
    cin >> k;
    vll v;
    while (k--)
    {
        ll a, b;
        cin >> a >> b;
        v.pb({a, b});
    }
    ll n, r, res = 0;
    cin >> n >> r;

    rep(i, v.size()) v[i].F = n - v[i].F;
    sort(all(v));

    // aut(x, v) cout << x.F << " " << x.S << '\n';

    gq p;

    rep(i, v.size())
    {
        // cout << res << " " << r << '\n';
        if (p.empty())
        {
            if (r < v[i].F)
            {
                cout << -1;
                return;
            }
            if (r == v[i].F) {r += v[i].S; res++;}
            else p.push(v[i].S);
            continue;
        }

        if (r < v[i].F)
        {
            while (r < v[i].F)
            {
                if (p.empty())
                {
                    cout << -1;
                    return;
                }
                ll pp = p.top();
                p.pop();
                res++;
                r += pp;
            }
            p.push(v[i].S);
            if (r == v[i].F)
            {
                ll pp = p.top();
                res++;
                p.pop();
                r += pp;
            }
        }
        else if (r == v[i].F)
        {
            p.push(v[i].S);
            ll pp = p.top();
            res++;
            p.pop();
            r += pp;
        }
        else
        {
            p.push(v[i].S);
        }

    }
    while (r < n)
    {
        if (p.empty())
        {
            cout << -1;
            return;
        }

        r += p.top();
        p.pop();
        res++;
    }

    cout << res;

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
