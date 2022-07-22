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
#define out(x, v) for (auto&(a) : (b)) cout << x << " ";
#define FOR(i, n) for ((ll)i=0; (i) < (n); (++i) )
#define FORR(i, n) for ((ll)i=1; (i) <= (n); (++i) )
#define all(v) v.begin(), v.end()
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

void calc()
{
    ll n; cin >> n;
    string s;
    cin >> s;
    ll freq[27] = {0};
    freq[s[0] - 'A']++;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            if (freq[s[i] - 'A'] != 0) {
                cout << "NO";
                return;
            }
            else {
                freq[s[i] - 'A']++;
            }

        }
    }
    cout << "YES";
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
        //cout << "Case #" << z << ": ";
        calc();
        cout << '\n';
    }

    return 0;
}
