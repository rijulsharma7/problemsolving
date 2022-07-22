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
    unordered_set<int> s;
    vl a(n); rep(i, n) cin>>a[i];
    sort(all(a)); 
    ll z=0, sum=0;
    rep(i, n) 
    {
        if(a[i]==0) z++;
        sum += a[i];
        s.insert(a[i]);
        // if(i!=0 and a[i]==a[i-1] and a[i] != 0)
        // {
        //     cout<<"NO";
        //     return;
        // }
    }
    if(z==n || z==n-1 || (z==n-2 && sum==0)) cout<<"YES";
    else if(n <= 10)
    {
        rep(i, n-2)
        {
            for(int j=i+1; j<n-1; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    ll x = a[i]+a[j]+a[k];
                    if(s.find(x)==s.end())
                    {
                        cout<<"NO";
                        return;
                    }
                }
            }
        }
        cout<<"YES";
    }
    else cout<<"NO";
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
