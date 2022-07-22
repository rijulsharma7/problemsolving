#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
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
#define aut(a, b) for (auto&(a) : (b))
#define out(x, v) for (auto&(x) : (v)) cout << x << " ";
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

ll solve(vl &v1, vl &v2, ll n, ll m, ll dp[5005][5005])
{
	if (n == 0) return 0;
	if (m == 0) return INT_MAX;
	if (dp[n][m] != -1) return dp[n][m];
	return dp[n][m] = min( abs(v1[n - 1] - v2[m - 1]) + solve(v1, v2, n - 1, m - 1, dp), solve(v1, v2, n, m - 1, dp) );
}

void calc()
{
	ll n;
	cin >> n;
	ll a[n];
	vl v1, v2;
	rep(i, n)
	{
		cin >> a[i];
		if (a[i] == 1) v1.pb(i);
		else v2.pb(i);
	}
	ll dp[5005][5005];
	memset(dp, -1, sizeof(dp));
	if (v1.empty()) cout << 0;
	else cout << solve(v1, v2, v1.size(), v2.size(), dp);

}

int main()
{
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