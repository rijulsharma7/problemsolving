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
    ll n;
    cin >> n;
    char a[n][n];
    rep(i, n) rep(j, n) cin >> a[i][j];
    set<pl> s;
    ll res = INT_MAX, cnt = 0;

    rep(i, n)
    {
        bool f = true;
        int c = 0, id = -1;
        rep(j, n)
        {
            if (a[i][j] == 'O') { f = false; break; }
            if (a[i][j] == '.') {c++; id = j;}
        }
        if (f)
        {
            if (res > c && c != 0)
            {
                res = c;
                cnt = 1;
                if (res == 1) s.insert({i, id});
            }
            else if (res == c)
            {
                cnt++;
                if (res == 1) s.insert({i, id});
            }
        }
    }
    // cout << res << " " << cnt << '\n';
    rep(i, n)
    {
        bool f = true;
        int c = 0, id = -1;
        rep(j, n)
        {
            if (a[j][i] == 'O') { f = false; break; }
            if (a[j][i] == '.') {c++; id = j;}
        }
        if (f)
        {
            if (res > c && c != 0)
            {
                res = c;
                cnt = 1;
                if (res == 1) s.insert({id, i});
            }
            else if (res == c)
            {
                cnt++;
                if (res == 1) s.insert({id, i});
            }
        }
    }

    if (cnt != 0)
    {
        if (res == 1)  {cout << res << " " << s.size(); s.clear();}
        else  cout << res << " " << cnt;
    }
    else cout << "Impossible";

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xss.txt", "r", stdin);
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
        cout << '\n';
    }

    return 0;
}
