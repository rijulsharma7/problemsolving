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
    ll n; cin>>n;
    ll nums[n]; rep(i, n) cin>>nums[i];
    ll left[n],right[n];
    ll sol[n];
    left[0]=nums[0];
    right[n-1]=nums[n-1];
    for(int i=1; i<n; i++){
        left[i]=__gcd(left[i-1],nums[i]);
    }
    for(int i=n-2; i>=0; i--){
        right[i]=__gcd(right[i+1],nums[i]);
    }
    for(int i=1; i<n-1; i++){
        sol[i]=__gcd(left[i-1],right[i+1]);
    }
    sol[0]=right[1];
    sol[n-1]=left[n-2];
    int res=0;
    for(int i=0; i<n; i++)
    {
        // cout<<sol[i]<<" ";
        if(sol[i]!=1) res++;
    }
    cout<<res;
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
