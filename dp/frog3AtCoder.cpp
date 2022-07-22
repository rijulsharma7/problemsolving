#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;
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
#define mem(dp) memset(dp, -1, sizeof(dp));
#define aut(a, b) for (auto&(a) : (b))
#define out(x, v) for (auto&(x) : (v)) cout << x << " ";
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

ll sq(ll n) { return n * n; }

ll bottomUp(int *a, int n, ll k)
{
    ll lookup[n] = {0};
    rep(i, n)
    {
        if (i == 0) continue;
        lookup[i] = inf;
        for (int j = i + 1; j < n; ++j)
        {
            if (i - j < 0) continue;
            lookup[i] = min(lookup[i], sq(abs(a[i] - a[j])) + lookup[i - j] + k);
        }
    }
    //rep(i, n) cout << lookup[i] << " ";
    return lookup[n - 1];
}

void calc()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    rep(i, n) cin >> a[i];

    cout << bottomUp(a, n, k) << '\n';
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
        // cout << '\n';
    }

    return 0;
}
