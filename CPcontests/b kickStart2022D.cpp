#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;using vvl = vector<vl>;using vs = vector<string>;
using ml = map<ll, ll>;using uml = unordered_map<ll, ll>;
using pl = pair<ll, ll>;using tl = tuple<ll, ll, ll>;
using vll = vector<pl>;using vlll = vector<tl>;
using pq = priority_queue <ll, vl, greater<ll>>;using gq = priority_queue <ll>;
#define mem(dp) memset(dp, -1, sizeof(dp))
#define aut(a, b) for (auto&(a) : (b))
#define out(v) for (auto&(x) : (v)) cout << x << " "; cout << '\n';
#define rep(i, n) for (ll (i) = 0; (i) < (n); ++(i) )
#define repp(i, n) for (ll (i) = 1; (i) <= (n); ++(i) )
#define rev(i, n) for (ll (i) = n-1; (i) >= 0; --(i) )
#define revv(i, n) for (ll (i) = n; (i) > 0; --(i) )
#define inc(v) rep(i, v.size()) cin>>v[i];
#define dec(v) rep(i, v.size()) cout<<v[i]<<" ";
#define inp(n) ll n; cin>>n;
#define all(v) v.begin(), v.end()
#define fi get<0>
#define se get<1>
#define th get<2>
#define F first
#define S second
// #define mp make_pair
#define mt make_tuple
#define pb push_back
ll inf = 1e18; ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}
ll digit(ll n) {return floor(log10(n) + 1);}

map<pair<pl, pl>, ll> mp;

ll rec(ll i, ll n, ll j, ll m, vl &a, vl &b, ll k)
{
    // base
    if(k==0) return 0;
    if(i>n or j>m) return 0;

    if(mp.find({{i, n}, {j, m}}) != mp.end()) return mp[{{i, n}, {j, m}}];

    ll z,x,c,v;
    z=a[i]+rec(i+1, n, j, m, a, b, k-1);
    x=a[n]+rec(i, n-1, j, m, a, b, k-1);
    c=b[j]+rec(i, n, j+1, m, a, b, k-1);
    v=b[m]+rec(i, n, j, m-1, a, b, k-1);
    ll res = max(z, max(x, max(c, v)));
    mp[{{i, n}, {j, m}}]=res;
    return res;
}

ll maxSum(vl &arr, ll k, ll n)
{
    ll curr = 0;
    ll maxx = 0;
 
    for (ll i = 0; i < k; i++)
        curr += arr[i];
 
    maxx = curr;
 
    ll j = n - 1;
    for (ll i = k - 1; i >= 0; i--) {
        curr = curr + arr[j] - arr[i];
        maxx = max(curr, maxx);
        j--;
    }
    return maxx;
}

void calc()
{
    inp(n); vl a(n); inc(a);
    inp(m); vl b(m); inc(b);
    inp(k); ll res=0;
    for(ll i=0; i<k+1; i++)
    {
        ll x = 0;
        if(i<=n) x=maxSum(a, i, n);
        ll y=0;
        if((k-i)<=m) y=maxSum(b, k-i, m);
        res = max(res, x+y);
    }
    cout<<res;
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
