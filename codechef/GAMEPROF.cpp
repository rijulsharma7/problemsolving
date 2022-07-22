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
bool comp(tl v1, tl v2)
{
    if (fi(v1) == fi(v2)) return th(v1) > th(v2);
    return fi(v1) < fi(v2);
}
bool compare(tl v1, tl v2)
{
    if (se(v1) == se(v2)) return th(v1) > th(v2);
    return se(v1) < se(v2);
}

void calc(int z)
{
    ll n, k;
    cin >> n >> k;
    vlll v, w;
    for (ll q = 0; q < n; q++)
    {
        ll x, y, val;
        cin >> x >> y >> val;
        v.pb({x, y, val});
        w.pb({x, y, val});
    }
    sort(v.begin(), v.end(), compare);
    sort(w.begin(), w.end(), comp);
    //rep(x, v) cout << fi(x) << " " << se(x) << " " << th(x) << '\n';
    ll res = 0;
    for (ll i = 0; i < n; i++)
    {
        ll sum = 0;
        for (ll j = n - 1; j >= 0; j--)
        {
            if (se(w[j]) <= se(v[i]))
            {
                sum += th(w[j]);
                res = max(res, sum - (k * (se(v[i]) - fi(w[j]))) );
            }
        }
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
    //cin >> t;
    for (int z = 1; z <= t; z++)
    {
        calc(z);
        cout << '\n';
    }

    return 0;
}
