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
ll gcd(ll a , ll b) {if (b == 0) return a; a %= b; return gcd(b, a);}
ll p[33];

void calc(int z)
{
    ll n, q;
    cin >> n >> q;
    ll a[n], res = 0;
    ll arr[33] = {0};
    for (ll i = 0; i < n; i++) {cin >> a[i]; res |= a[i];}
    cout << res << '\n';
    for (int i = 0; i < n; i++)
    {
        ll num = a[i];
        ll j = 0;
        while (num > 0)
        {
            arr[j] += num & 1;
            num = num >> 1;
            j++;
        }
    }
    // for(auto x : arr) cout << x << " ";
    while (q--)
    {
        ll x, v;
        cin >> x >> v;
        ll j = 0;
        ll num = a[x - 1];
        while (num > 0)
        {
            arr[j] -= num & 1;
            num = num >> 1;
            j++;
        }
        num = v;
        j = 0;
        while (num > 0)
        {
            arr[j] += num & 1;
            num = num >> 1;
            j++;
        }
        res = 0;
        for (int i = 0; i < 32; i++) if (arr[i] != 0) res += p[i];
        cout << res << '\n';
        a[x - 1] = v;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 0; i < 33; i++) p[i] = (ll)pow(2, i);
    for (int z = 1; z <= t; z++)
    {
        calc(z);
        //cout << '\n';
    }

    return 0;
}
