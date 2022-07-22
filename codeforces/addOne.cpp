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
ll cnt = 0;

ml freq(int N)
{
    ml map;
    cnt = 0;
    int r;
    while (N)
    {
        r = N % 10;
        map[r]++;
        cnt++;
        N = N / 10;
    }
    return map;
}

void calc(int z)
{
    ll n, m;
    cin >> n >> m;
    ml map = freq(n);
    ml m2, mm;
    if (m < 10) mm = map;
    ll k = m / 10;
    ll res = cnt % mod;
    while (k--)
    {
        for (int i = 0; i < 10; i++)
        {
            res += ( map[i] * k) % mod;
            m2[(i + 1) % 10] += map[i];
            mm[i] += map[i];
        }
        map = m2;
    }
    k = m % 10;
    for (int i = 10 - k; i < 10; i++) res += mm[i] % mod;
    cout << res;
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
