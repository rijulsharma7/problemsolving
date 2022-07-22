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
    vl a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll res = 0, cnt = 0;
    vl check(n, -1);
    for (ll i = 30; i >= 0; i--) {
        bool f = true;
        rep(j, n) {
            if (check[j] == -1 && (!(a[j] >> i) & 1) && !((b[j] >> i) & 1)) {f = 0; break;}
            else
            {
                if (check[j] == 1) f = ((f & (b[j] >> i) & 1));
                else f = ((f & (a[j] >> i) & 1));
            }
        }
        if (!f) continue;
        ll id = 1;
        rep(j, n) {
            if (check[j] == -1)
            {
                if ( ((a[j] >> i) & 1) && ((b[j] >> i) & 1) ) {}
                else if (((a[j] >> i) & 1))check[j] = 0;
                else if (((b[j] >> i) & 1))check[j] = 1, cnt++;
                else {
                    id = 0;
                    break;
                }
            }
            else
            {
                if (check[j] == 1) id = ((id & (b[j] >> i) & 1));
                else id = ((id & (a[j] >> i) & 1));
            }

        }
        res += (id * (1ll << i));
    }
    cout << res << " " << cnt;

    // ll p[n][31], q[n][31], mat[n][31]; bool f = true;
    // rep(i, n)
    // {
    //     rep(j, 31)
    //     {
    //         p[i][j] = 0; q[i][j] = 0; mat[i][j];
    //     }
    // }
    // rep(i, n)
    // {
    //     ll x = a[i];
    //     ll j = 0;
    //     while (x)
    //     {
    //         p[i][j] = x & 1;
    //         j++;
    //         x = x >> 1;
    //     }
    // }
    // rep(i, n)
    // {
    //     ll x = b[i];
    //     ll j = 0;
    //     while (x)
    //     {
    //         q[i][j] = x & 1;
    //         j++;
    //         x = x >> 1;
    //     }
    // }
    // bool flip[n] = {false};
    // // rep(i, n)
    // // {
    // //     rep(j, 31)
    // //     {
    // //         cout << p[i][j] << " ";
    // //     }
    // //     cout << endl;
    // // }

    // ll res = INT_MIN, pq = INT_MIN;


    // rep(i, n) rep(j, 31) mat[i][j] = p[i][j] | q[i][j];
    // rep(i, n) rep(j, 31) mat[i][j] = p[i - 1][j] | q[i][j];

    // ll id = -1;
    // for (ll i = 30; i >= 0; i--) if (mat[n - 1][i] == n) {id = i; f = false; break;}

    // if (f) cout << "0 0";
    // else
    // {
    //     ll res = 0, cnt = 0, idx = id;
    //     while (id >= 0)
    //     {
    //         bool flag = false;
    //         rep(i, n)
    //         {
    //             if (!flips[i])
    //             {
    //                 if (p[i][id] != 1)
    //                 {
    //                     bool f = false;
    //                     for (ll j = id; j <= idx; j++)
    //                     {
    //                         if (p[i][j] > q[i][j]) {f = true; break;}
    //                     }
    //                     if (!f && q[i][id] == 1)
    //                     {
    //                         cnt++;
    //                         flips[i] = true;
    //                     }
    //                 }
    //             }
    //             else if (q[i][id] != 1) {flag = true; break;}
    //         }
    //         if (!flag) res = res + pow(2, id);
    //         id--;
    //     }

    //     cout << res << " " << cnt;
    // }

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
    cin >> t;
    repp(z, t)
    {
        //cout << "Case #" << z << ": ";
        calc();
        cout << '\n';
    }

    return 0;
}
