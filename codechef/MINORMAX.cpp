#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
using ml = map<ll, ll>;
using uml = unordered_map<ll, ll>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;
using vll = vector<pl>;
using vlll = vector<tl>;
using pq = priority_queue <ll, vl, greater<ll>>;
using gq = priority_queue <ll>;
#define mem(dp) memset(dp, -1, sizeof(dp))
#define aut(a, b) for (auto&(a) : (b))
#define out(v) for (auto&(x) : (v)) cout << x << " "; cout << '\n';
#define rep(i, n) for (ll (i) = 0; (i) < (n); ++(i) )
#define repp(i, n) for (ll (i) = 1; (i) <= (n); ++(i) )
#define rev(i, n) for (ll (i) = n-1; (i) >= 0; --(i) )
#define revv(i, n) for (ll (i) = n; (i) > 0; --(i) )
#define all(v) v.begin(), v.end()
#define fi get<0>
#define se get<1>
#define th get<2>
#define F first
#define S second
#define mp 
#define mt make_tuple
#define pb push_back
ll inf = 1e18; ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}
ll digit(ll n) {return floor(log10(n) + 1);}

void calc()
{
    ll n;
    cin>>n;
    ll a[n];
    rep(i, n) cin>>a[i];
    bool f = false;
    ll min=INT_MAX, max=INT_MIN;
    rep(i, n)
    {
        if(a[i]<min) min = a[i];
        if(a[i]>max) max = a[i];
        if(a[i] != max && a[i] != min) f=true;
    }
    if(f) cout<<"NO";
    else cout<<"YES";
}

int main()
{
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
