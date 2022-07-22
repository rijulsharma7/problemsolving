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
bool compare(ll a, ll b) {return a > b;}
ll gcd(ll a , ll b) {if (b == 0) return a; a %= b; return gcd(b, a);}
ll digit(ll n) {return floor(log10(n) + 1);}

bool comp(tl p1, tl p2)
{
	if (fi(p1) == fi(p2))
	{
		return se(p1) > se(p2);
	}
	return fi(p1) < fi(p2);
}

void calc()
{
	ll n;
	cin >> n;
	string s;
	cin >> s;

	vector<int> p(n, -1);
	for (int j = 1; j < n; j++) {
		cin >> p[j];
		p[j]--;
	}
	vector<vector<int>> c(n);
	for (int j = 1; j < n; j++) {
		c[p[j]].push_back(j);
	}
	int N = n;
	vector<int> dp(N, 0);
	for (int v = N - 1; v >= 0; v--) {
		if (s[v] == '1') {
			dp[v] = 1;
		}
		for (int w : c[v]) {
			dp[v] += dp[w];
		}
	}

	// vi d(n);
	// for(int k=n-1; k>=0; k--)
	// {
	//     if(c[k].empty()) continue;
	//     d[k] += c[k].size();
	//     aut(x, c[k]) d[k] += d[x];
	// }
	// out(x, d);

	vlll v(n);
	rep(i, n)
	{
		v[i] = mt(p[i], dp[i], i);
	}

	sort(v.begin(), v.end(), comp);
	// aut(x, v) cout << fi(x) << " " << se(x) << " " << th(x) << '\n';
	ll res = 0; p[0] = 0;
	repp(i, n - 1)
	{
		ll x = th(v[i]);
		while (1)
		{
			if (s[p[x]] == '1' || s[x] == '0') break;
			res++;
			s[x] = '0';
			s[p[x]] = '1';
			x = p[x];
		}
	}
	cout << res;
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
		//cout << "Case #" << z << ": ";
		calc();
		cout << '\n';
	}

	return 0;
}
