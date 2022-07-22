#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
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

int sum(vi v, int i, int j)
{
    int res = 0;
    for (int k = i; k < j; k++) res += v[k];
    return res;
}

int calc(vi a, int s, int e, int k)
{
    if (e - s + 1 < k)
    {
        return 0;
    }
    int res = INT_MIN;
    for (int i = 0; i <= k; i++)
    {
        int ans = sum(a, s, s + i) + sum(a, e - k + i + 1, e + 1);
        int op = INT_MAX;
        for (int j = 0; j <= k; j++)
        {
            op = min(op, calc(a, s + i + j, e - k + i - k + j, k));
        }
        res = max(res, ans + op);
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

    int n, k;
    cin >> n >> k;
    vi v(n, 0);
    rep(i, n) cin >> v[i];
    cout << calc(v, 0, n - 1, k);

    return 0;
}