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

ll calc()
{
    ll n;
    cin >> n;

    if (n == -1) return -7;

    ll a[n], sum = 0;
    rep(i, n) {cin >> a[i]; sum += a[i];}
    if (sum % n) return -1;

    // ll cs[n]; cs[0] = a[0];
    // for (ll i = 1; i < n; i++) cs[i] = cs[i - 1] + a[i];

    // ll res = INT_MIN, k = sum / n;
    // rep(i, n - 1)
    // {
    //     ll s1 = cs[i];
    //     ll s = (i + 1) * k;
    //     ll s2 = abs(s - s1);
    //     res = max(res, s2);
    // }

    ll k = sum / n, res = INT_MIN, ans = 0;

    rep(i, n)
    {
        ans += a[i];
        ll load = k * (i + 1);
        res = max(res, abs(ans - load));
    }

    return res;
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
    // cin >> t;
    while (1)
    {
        //cout << "Case #" << z << ": ";
        ll res = calc();
        if (res == -7) break;
        cout << res;
        cout << '\n';
    }

    return 0;
}
