#include<bits/stdc++.h> 
using namespace std; 

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vii = vector<pi>;
using vll = vector<pl>;

#define MOD 998244353

bool compare(ll a, ll b) {return a > b;}

ll gcd(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;
 
    if (a == b) return a;

    if (a > b) return gcd(a%b, b);
    return gcd(b%a, a);
}

ll ncr(ll n, ll r)
{
	ll p = 1, k = 1;

    if (n - r < r) r = n - r;
 
    if (r != 0)
    {
        while (r) 
        {
            p *= n;
            k *= r;

            ll m = gcd(p, k);

            p /= m;
            k /= m;
 
            n--;
            r--;
        }
    }
 
    else p = 1;
 
    return p;
}

ll inverse(ll n, ll m = MOD) 
{ 
    ll x = m;
	ll a = 1, b = 0; 

	while (n > 1) 
    { 
		ll q = n / m; 
		ll t = m; 

		m = n % m;
		n = t; 
		t = b; 

		b = a - q * b; 
		a = t; 
	} 

	if (a < 0)  a += x; 

	return a; 
}  

ll mult_inv(ll p, ll q)
{
    return (p*inverse(q))%MOD;
}

void calc()
{
	ll m, n, k;
	cin >> m >> n >> k;

    if(m == 1)
    {
        ll sum=0;
        for(ll i=0; i<n; i++) sum += (i+1)*ncr(n-1,i)*k*pow(k-1,i);
        cout << mult_inv(sum,pow(k,n));
    }
    else
    {
        ll sum=0;
        for(ll i=0; i<n; i++) sum += (i+1)*ncr(n-1,i)*k*pow(k-1,i);
        cout << mult_inv(sum,pow(k,2*n));
    }

	return;
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    //cin >> t;
    
    while(t--)
    {
        calc();
        cout << '\n';
    }
	
    return 0;
}
