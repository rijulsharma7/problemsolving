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

bool comp(tl a, tl b)
{
  if (se(a) == se(b))
  {
    ll x = fi(a) / se(a);
    ll y = fi(b) / se(b);
    return x < y;
  }
  return se(a) > se(b);
}

void calc()
{
  ll res, s, n;
  cin >> res >> s >> n;
  ll a[s];
  rep(i, s) cin >> a[i];
  vlll v(n, mt(0, 0, 0));
  rep(i, n)
  {
    ll x, y;
    cin >> x >> y;
    v[i] = mt(x, y, i + 1);
  }
  sort(v.begin(), v.end(), comp);
  // aut(x, v) cout << fi(x) << " " << se(x) << " " << th(x) << "\n";

  rep(i, s)
  {
    if (a[i] >= res)
    {
      cout << 0 << '\n';
      return;
    }
    ll cnt = 0, id = 0;
    set<ll> ss;
    while (a[i] <= res)
    {
      a[i] += fi(v[id]);
      ss.insert(th(v[id]));
      id++;
      cnt++;
    }
    cout << cnt << " ";
    out(x, ss);
    id = 0;
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
  //cin >> t;
  repp(z, t)
  {
    //cout << "Case #" << z << ": ";
    calc();
    cout << '\n';
  }

  return 0;
}
