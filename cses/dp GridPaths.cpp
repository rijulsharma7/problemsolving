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
#define mp make_pair
#define mt make_tuple
#define pb push_back
ll inf = 1e18; ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}
ll digit(ll n) {return floor(log10(n) + 1);}

void calc()
{
	ll n; cin>>n;
	vs mat(n);
	rep(i, n) cin >> mat[i];
	ll res[n][n];
	rep(i, n) rep(j, n) res[i][j] = 0ll;
	if(mat[0][0] == '*')
	{
		cout << 0ll;
		return;
	}
	else
	{
		res[0][0] = 1ll;
	}
	rep(i, n) 
	{
		if (mat[i][0] == '*' || (i != 0 && (mat[i-1][0] == '*' || res[i-1][0] == 0) )) res[i][0] = 0ll;
		else res[i][0] = 1ll;
	}
	rep(i, n) 
	{
		if (mat[0][i] == '*' || (i != 0 && (mat[0][i-1] == '*' || res[0][i-1] == 0) )) res[0][i] = 0ll;
		else res[0][i] = 1ll;
	}
	repp(i, n-1)
	{
		repp(j, n-1)
		{
			if (mat[i][j] == '*') res[i][j] = 0ll;
			else res[i][j] = ( (mat[i-1][j]=='*' ? 0 : res[i-1][j]%mod) + (mat[i][j-1]=='*' ? 0 : res[i][j-1]%mod) )%mod;
		}
	}
	// repp(i, n-1)
	// {
	// 	repp(j, n-1)
	// 	{
	// 		if (mat[i][j] == '*') res[i][j] = 0ll;
	// 		else 
	// 		{
	// 			if(i >= 1 && mat[i-1][j] != '*') 
	// 			{
	// 				res[i][j] += res[i-1][j]%mod;
	// 				res[i][j] %= mod;
	// 			}
	// 			if(j >= 1 && mat[i][j-1] != '*')
	// 			{
	// 				res[i][j] += res[i][j-1]%mod;
	// 				res[i][j] %= mod;
	// 			}
	// 		}
	// 	}
	// }
	// rep(i, n) {rep(j, n) cout<<res[i][j]<<" "; cout<<'\n';}cout<<'\n';
	cout << res[n-1][n-1]%mod;
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
    // cin >> t;
    repp(z, t)
    {
        //cout << "Case #" << z << ": ";
        calc();
        cout << '\n';
    }

    return 0;
}
