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
    ll n, q;
    cin >> n >> q;
    uml m;
    for (ll i = 1; i <= n; i++)
    {
        ll x; cin >> x;
        if (m[x] == 0) m[x] = i;
    }
    //for(int i=1;i<=50;i++) cout << m[i] << " ";
    while (q--)
    {
        ll x; cin >> x;
        cout << m[x] << " ";
        for (int i = 1; i <= 50; i++) if (i != x && m[i] != 0 && m[i] < m[x]) m[i]++;
        m[x] = 1;
    }
}

int main()
{
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
