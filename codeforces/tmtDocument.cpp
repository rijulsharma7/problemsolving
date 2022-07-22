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
    bool flag = true;
    ll n;
    cin >> n;
    string str;
    cin >> str;
    ll t = 0, m = 0;
    for (char c : str)
    {
        if (c == 'T') t++;
        else
        {
            m++;
            if (m > t) flag = false;
        }
    }
    if (m * 2 != t) flag = false;
    m = 0; t = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        char c = str[i];
        if (c == 'T') t++;
        else
        {
            m++;
            if (m > t) flag = false;
        }
    }
    if (m * 2 != t) flag = false;
    if (flag) cout << "YES";
    else cout << "NO";
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
