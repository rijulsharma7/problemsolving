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
bool compare(pl a, pl b) {return a.S > b.S;}
ll gcd(ll a , ll b) {if (b == 0) return a; a %= b; return gcd(b, a);}
ll digit(ll n) {return floor(log10(n) + 1);}

bool flag = false;

bool check(string a, string b)
{
    // cout << a <<" " << b << '\n';
    rep(i, a.length())
    {
        if (a[i] == b[i]) return false;
    }
    return true;
}

void permute(string s , string a, string x)
{
    if (flag) return;
    if (s.length() == 0)
    {
        bool f = check(x, a);
        if (f) { cout << a; flag = true;}
        return;
    }
    for (int i = 0 ; i < s.length() ; i++)
    {
        char c = s[i];
        string left = s.substr(0, i);
        string right = s.substr(i + 1);
        string r = left + right;
        permute(r , a + c, x);
    }

}

void calc()
{
    string s;
    cin >> s;
    ll n = s.length();
    ll freq[27] = {0};
    map<ll, vl> m;
    rep(i, s.length())
    {
        int x = s[i] - 'a';
        freq[x]++;
        m[s[i] - 'a'].pb(i);
    }

    // rep(i, 27) cout << freq[i] << " ";

    bool f = true;
    ll maxx = INT_MIN;
    rep(i, 27)
    {
        if (freq[i] > n / 2) f = false;
        maxx = max(freq[i], maxx);
    }
    if (!f) cout << "IMPOSSIBLE";
    else
    {
        vll v;
        rep(i, 27)
        {
            v.pb({i, freq[i]});
        }
        // aut(x, v)
        // {
        //     cout << x.F << " " << x.S << '\n';
        // } cout << '\n';
        sort(all(v), compare);
        // string ss = "";
        // flag = false;
        // permute(s, ss, s);
        // rep(i, 4)
        // {
        //     pl x = v[i];
        //     cout << x.F << " " << x.S << '\n';
        // }

        vl a(n, -1);
        ll y = 0, i = 0;
        aut(x, v)
        {
            ll cnt = x.S, id = x.F;
            while (y < n - 1)
            {
                if (cnt == 0) break;
                char c = id + 'a';
                if (a[i] == -1 && a[i] != id && s[i] != c)
                {
                    // cout << id << " " << i << " " << a[i] << " ";
                    // cout << id << '\n';
                    a[i] = id;
                    // cout << a[i] << '\n';
                    cnt--;
                    y++;
                }
                i = (i + 1) % n;
            }
            if (y == n - 1 && cnt == 1)
            {
                // cout << id << '\n';
                char c = id + 'a';
                int prev = -1;
                rep(j, n)
                {
                    if (a[j] == -1) prev = j;
                    if (a[j] == -1 && a[j] != id && s[j] != c)
                    {
                        a[j] = id;
                        cnt--;
                        y++;
                    }
                }
                if (y == n) break;

                rep(j, n)
                {
                    if (cnt == 0) break;
                    if (j == prev) continue;
                    char c = a[j] + 'a';
                    if (s[prev] != c)
                    {
                        a[prev] = a[j];
                        a[j] = id;
                        cnt--;
                    }
                }
            }
        }

        // out(x, a);
        string ss = s;
        rep(i, s.length())
        {
            if (a[i] == 0) ss[i] = 'a';
            else ss[i] = a[i] + 'a';
        }
        cout << ss;
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
