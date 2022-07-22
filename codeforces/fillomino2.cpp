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


void calc(int z)
{
    ll n;
    cin >> n;

    ll res[503][503] = {0};
    ll a[n];
    for (ll i = 0; i < n; i++) {cin >> a[i]; res[i][i] = a[i];}

    for (ll k = 0; k < n; k++)
    {
        ll num = a[k] - 1;
        ll i = k, j = k;
        while (num)
        {
            if (res[i][j - 1] == 0 && j - 1 >= 0)
            {
                res[i][j - 1] = a[k];
                j--;
                num--;
            }
            else if (res[i + 1][j] == 0 && i + 1 < n)
            {
                res[i + 1][j] = a[k];
                i++;
                num--;
            }
            else if (res[i][j + 1] == 0 && i + 1 < n)
            {
                res[i][j + 1] = a[k];
                j++;
                num--;
            }
            else if (res[i - 1][j] == 0 && i - 1 > 0)
            {
                res[i - 1][j] = a[k];
                i--;
                num--;
            }
        }
    }

    for (ll i = 0; i < n; i++) { {for (ll j = 0; j <= i; j++) cout << res[i][j] << " ";} cout << '\n';}


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
        //cout << "Case #" << z << ": ";
        cout << '\n';
    }

    return 0;
}
