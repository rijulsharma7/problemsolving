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
    string s;
    cin >> s;
    if (n == 1)
    {
        cout << n << '\n';
        cout << s;
        return;
    }
    unordered_map<char, int> m;
    char c;
    bool f = false;
    rep(i, n)
    {
        m[s[i]]++;
        if (s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9')
        {
            f = true;
            c = s[i];
        }
    }
    if (f)
    {
        cout << 1 << '\n';
        cout << c;
        return;
    }

    if (n > 1)
    {
        aut(x, m)
        {
            if (x.second > 1)
            {
                cout << 2 << '\n' << x.F << x.F;
                return;
            }
        }
    }

    if (m.count('2') > 0 && m.count('5') > 0)
    {
        cout << 2 << '\n';
        int cnt = 0;
        rep(i, n)
        {
            if (cnt == 2) return;
            if (s[i] == '2' || s[i] == '5')
            {
                cnt++;
                cout << s[i];
            }
        }
    }
    else if (m.count('2') > 0 && m.count('7') > 0)
    {
        cout << 2 << '\n';
        int cnt = 0;
        rep(i, n)
        {
            if (cnt == 2) return;
            if (s[i] == '2' || s[i] == '7')
            {
                cnt++;
                cout << s[i];
            }
        }
    }
    else if (m.count('7') > 0 && m.count('5') > 0)
    {
        cout << 2 << '\n';
        int cnt = 0;
        rep(i, n)
        {
            if (cnt == 2) return;
            if (s[i] == '7' || s[i] == '5')
            {
                cnt++;
                cout << s[i];
            }
        }
    }
    else
    {
        cout << n << '\n';
        cout << s;
    }


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
    // seive();
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
