#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
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
#define rep(a, b) for (auto&(a) : (b))
#define fi get<0>
#define se get<1>
#define th get<2>
#define mp make_pair
#define mt make_tuple
#define pb push_back
ll inf = 1e18;
ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}

ll solve(vl v, ll i, ll n, ll s, ll p)
{
    if (p == s) return p;
    if (p > s || i == n) return -1;
    return max( solve(v, i + 1, n, s - v[i], p * v[i]), solve(v, i + 1, n, s, p) );
}

void calc(int z)
{
    ll n;
    cin >> n;
    vl v;
    ll s = 0;
    while (n--)
    {
        ll x, y;
        cin >> x >> y;
        while (y--)
        {
            v.push_back(x);
            s += x;
        }
    }
    ll p = 1;
    ll res = max(solve(v, 0, v.size(), s, p), 0ll);
    cout << "Case #" << z << ": " << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int z = 1; z <= t; z++)
    {
        calc(z);
        cout << '\n';
    }

    return 0;
}
