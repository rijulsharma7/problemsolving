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

void calc(int z)
{
    ll n, k;
    cin >> n >> k;
    if (k == 0)
    {
        for (ll i = 1; i <= n; i++) cout << i << " ";
        return;
    }
    if (n <= 2 * k)
    {
        cout << "-1";
        return;
    }
    vl v[k];
    for (ll i = 0, c = 2; c <= n; i = (i + 1) % k, c++)
    {
        v[i].pb(c);
    }
    for (ll i = 0; i < k; i++)
    {
        rep(x, v[i]) cout << x << " ";
    }
    cout << 1 << " ";

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
