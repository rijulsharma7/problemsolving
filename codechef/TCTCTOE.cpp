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

void calc()
{
	char mat[3][3];
	ll s = 0, x = 0, o = 0;
	rep(i, 3)
	{
		rep(j, 3)
		{
			cin >> mat[i][j];
			if (mat[i][j] == '_') s++;
			else if (mat[i][j] == 'X') x++;
			else o++;
		}
	}

	ll a = 0, b = 0;
	rep(i, 3)
	{
		char c = '!';
		rep(j, 3)
		{
			if (mat[i][j] == '_') break;
			if (c == '!') c = mat[i][j];
			else if (c == 'X')
			{
				if (mat[i][j] == 'O') break;
			}
			else
			{
				if (mat[i][j] == 'X') break;
			}
			if (j == 2)
			{
				if (mat[i][j] == 'X') a++;
				else b++;
			}
		}
	}
	rep(j, 3)
	{
		char c = '!';
		rep(i, 3)
		{
			if (mat[i][j] == '_') break;
			if (c == '!') c = mat[i][j];
			else if (c == 'X')
			{
				if (mat[i][j] == 'O') break;
			}
			else
			{
				if (mat[i][j] == 'X') break;
			}
			if (i == 2)
			{
				if (mat[i][j] == 'X') a++;
				else b++;
			}
		}
	}

	if (mat[0][0] == mat[1][1] && mat[0][0] == mat[2][2])
	{
		if (mat[0][0] == 'X') a++;
		else if (mat[0][0] == 'O') b++;
	}

	if (mat[0][2] == mat[1][1] && mat[0][2] == mat[2][0])
	{
		if (mat[0][2] == 'X') a++;
		else if (mat[0][2] == 'O') b++;
	}

// 	cout << a << " " << b << " " << s << '\n';

	if (o <= x && x - o <= 1)
	{
		if ((a == 1 && b == 0 && x - o == 1) || (b == 1 && a == 0 && x == o)) cout << 1;
		else if (s == 0 && a == 0 && b == 0 && x - o == 1) cout << 1;
		else if (a == 2 && s == 0 && b == 0 && x - o == 1) cout << 1;
		else if (s > 0 && a == 0 && b == 0) cout << 2;
		else cout << 3;
	}
	else cout << 3;

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
