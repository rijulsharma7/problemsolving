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
    ll r, cc, k;
    cin >> r >> cc >> k;
    ll a, b, c , d;
    cin >> a >> b >> c >> d;
    ll x = abs(a - c) + 1;
    ll y = abs(b - d) + 1;
    if (k == 1)
    {
        ll res = x * (y + 1);
        res += y * (x + 1);
        a--; b--; c--; d--; r--; cc--;
        vll v(4);
        v.pb({a, b});
        v.pb({c, b});
        v.pb({c, d});
        v.pb({a, d});
        ll ans = 0;
        if (b == 0) ans += c - a + 1;
        if (a == 0) ans += d - b + 1;
        if (c == r) ans += d - b + 1;
        if (d == cc) ans += c - a + 1;

        ll p = min(a, b);
        p = min(p, (r - c));
        p = min(p, (cc - d));
        // cout << res << " " << p << " " << ans << '\n';
        cout << (res + p - ans);
    }
    else
    {
        cout << -1;
    }
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
        cout << "Case #" << z << ": ";
        calc();
        cout << '\n';
    }

    return 0;
}
