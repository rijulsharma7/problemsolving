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
#define mem(dp) memset(dp, -1, sizeof(dp))
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

void sortRow(vvl &v, ll i, ll startCol, ll endCol) {

    vl vv;
    for (ll k = startCol; k <= endCol; k++) vv.pb(v[i][k]);

    sort(vv.begin(), vv.end());

    ll it = 0;
    for (ll k = startCol; k <= endCol; k++) v[i][k] = vv[it++];

    return;
}

void sortCol(vvl &v, ll j, ll startRow, ll endRow)
{
    vl vv;
    for (ll k = startRow; k <= endRow; k++) vv.pb(v[k][j]);

    sort(vv.begin(), vv.end());

    ll it = 0;
    for (ll k = startRow; k <= endRow; k++) v[k][j] = vv[it++];

    return;
}

void merge(vvl &v, ll startRow, ll endRow, ll startCol, ll endCol)
{
    for (ll i = startRow; i <= endRow; i++)
        sortRow(v, i, startCol, endCol);

    for (ll j = startCol; j <= endCol; j++)
        sortCol(v, j, startRow, endRow);

    return;
}

void solve(vvl &v, ll er, ll ec, ll sr = 0, ll sc = 0)
{
    if (sr >= er && sc >= ec) return;

    ll midRow = (sr + er) / 2;
    ll midCol = (sc + ec) / 2;

    solve(v, midRow, midCol, sr, sc); // case 1
    solve(v, er, midCol, midRow + 1, sc); // case 2
    solve(v, midRow, ec, sr, midCol + 1); // case 3
    solve(v, er, ec, midRow + 1, midCol + 1); // case 4

    merge(v, sr, er, sc, ec);
    return;
}

void calc()
{
    ll m, n;
    cin >> m >> n;
    vvl v;
    rep(i, m)
    {
        vl vv;
        rep(j, n)
        {
            ll xx; cin >> xx;
            vv.pb(xx);
        }
        v.pb(vv);
    }

    solve(v, m - 1, n - 1);

    for (auto x : v) out(y, x);

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
    repp(z, t)
    {
        //cout << "Case #" << z << ": ";
        calc();
        cout << '\n';
    }

    return 0;
}
