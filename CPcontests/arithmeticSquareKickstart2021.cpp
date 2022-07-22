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
// #define mp make_pair
#define mt make_tuple
#define pb push_back
ll inf = 1e18;
ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}
ll gcd(ll a , ll b) {if (b == 0) return a; a %= b; return gcd(b, a);}
ll digit(ll n) {return floor(log10(n) + 1);}

void calc()
{
    ll res = 0;
    ll mat[3][3];
    rep(i, 3)
    {
        rep(j, 3)
        {
            if (i == 1 && j == 1) mat[i][j] = -1;
            else cin >> mat[i][j];
        }
    }

    uml mp;
    if ((mat[0][1] + mat[2][1]) % 2 == 0) mp[((mat[0][1] + mat[2][1]) / 2)]++;
    if ((mat[1][0] + mat[1][2]) % 2 == 0) mp[((mat[1][0] + mat[1][2]) / 2)]++;
    if ((mat[0][0] + mat[2][2]) % 2 == 0) mp[((mat[0][0] + mat[2][2]) / 2)]++;
    if ((mat[0][2] + mat[2][0]) % 2 == 0) mp[((mat[0][2] + mat[2][0]) / 2)]++;
    ll element = 0;
    ll maxi = 0;
    aut(x, mp)
    {
        if (x.S > maxi) {
            maxi = x.S;
            element = x.F;
        }
    }
    mat[1][1] = element;

    rep(i, 3)
    {
        if ((mat[i][0] + mat[i][2]) & 1) continue;
        if (mat[i][1] == ((mat[i][0] + mat[i][2]) / 2)) res++;
    }
    rep(i, 3)
    {
        if ((mat[0][i] + mat[2][i]) & 1) continue;
        if (mat[1][i] == ((mat[0][i] + mat[2][i]) / 2)) res++;
    }
    if ((mat[0][0] + mat[2][2]) % 2 == 0)
    {
        if (mat[1][1] == ((mat[0][0] + mat[2][2]) / 2) ) res++;
    }
    if ((mat[0][2] + mat[2][0]) % 2 == 0)
    {
        if (mat[1][1] == ((mat[0][2] + mat[2][0]) / 2) ) res++;
    }

    cout << res;
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
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
