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
    ll n,m; cin>>n>>m;
    int cnt=1, p=1;
    int mat[n][m];
    bool f=false;
    if(n>m)
    {
        swap(n, m);
        f=true;
    }
    rep(i, n)
    {
        int x;
        if(i==0)
        {
            x=1;
        }
        else
        {
            x=p+2;
        }
        rep(j, m)
        {
            if(j==0) p=x;
            mat[i][j]=x;
            x+=cnt;
        }
        cnt+=2;
    }
    if(f)
    {
        rep(j, m)
        {
            rep(i, n)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
    else
    {
        rep(i, n)
        {
            rep(j, m)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
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
        // cout << '\n';
    }

    return 0;
}
