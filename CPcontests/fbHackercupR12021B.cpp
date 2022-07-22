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
#define out(v) for (auto&(x) : (v)) cout << x << " "; cout << '\n';
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

void calc()
{
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n + m - 1 > a || n + m - 1 > b)
    {
        cout << "Impossible\n";
        return;
    }
    cout << "Possible\n";
    if (n == 2 && m == 2)
    {
        ll mat[n][m];
        rep(i, n) rep(j, m) mat[i][j] = 1;
        mat[0][0] = a - 2; mat[0][1] = b - 2;
        rep(i, n) {
            rep(j, m) cout << mat[i][j] << " "; cout << '\n';
        }
    }
    else
    {
        ll x = a - n - m + 3, y = b - n - m + 3;
        ll mat[n][m];
        rep(i, n) rep(j, m) mat[i][j] = 1;
        mat[0][0] = x / 2;
        mat[n - 1][m - 1] = x - (x / 2);
        mat[0][m - 1] = y / 2;
        mat[n - 1][0] = y - (y / 2);
        rep(i, n) {
            rep(j, m) cout << mat[i][j] << " "; cout << '\n';
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("tcc.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    repp(z, t)
    {
        cout << "Case #" << z << ": ";
        calc();
        // cout << '\n';
    }

    return 0;
}
