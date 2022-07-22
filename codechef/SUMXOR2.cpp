#include<bits/stdc++.h> 
using namespace std; 

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vii = vector<pi>;
using vll = vector<pl>;

bool compare(ll a, ll b) {return a > b;}

//** took reference from
// https://www.geeksforgeeks.org/queries-of-ncrp-in-o1-time-complexity/?ref=rp
// which was publically available before the start of the contest **

#define M 998244353
const int N = 1000001;

ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1];
ll fact[N + 1];
 
void inverseOfNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)  naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}

void inverseOfFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)  factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
 
void factorial(ll p)
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++)  fact[i] = (fact[i - 1] * i) % p;
}

ll nCr(ll N, ll R, ll p) 
{
    if(N < R) return 0;
    if( (N - R) < R) R = N - R;
    if(R == 0) return 1;
    if(R == 1) return N;
    return ((fact[N] * factorialNumInverse[R]) % p * factorialNumInverse[N - R]) % p; 
} 

void calc()
{
    ll n, q;
    cin >> n;
    ll a[n];
    for(ll i=0; i<n; i++) cin >> a[i];
    
    vl v1(33,0);
    vl v2(33,0);
    pair<vl,vl> p(v1, v2);

    for(ll i=0; i<n; i++) 
    {
        ll idx = 0, t = a[i], z = 33;
        while(z--)
        {
            if(t & 1) get<0>(p)[idx]++;
            else get<1>(p)[idx]++;
            idx++;
            t = t >> 1;
        }
    }
    //for(int i=0; i<33; i++) cout << get<0>(p)[i] << " " << get<1>(p)[i] << '\n';

    for(ll i=0; i<n; i++)
    {
        ll ans = 0, m = i+1;
        for(int idx=0; idx<33; idx++)
        {
            if(get<0>(p)[idx] == 0) continue;
            ll sum = 0;
            for(ll k=1; k<=get<0>(p)[idx]; k+=2)
            {
                sum += ((nCr(get<0>(p)[idx], k, M)%M) * (nCr(get<1>(p)[idx], m-k, M))%M) % M ;
                sum %= M;
                // cout << idx << " " << ans << " "<< '\n';
                // cout << nCr(get<0>(p)[idx], k, M) << " " << nCr(get<1>(p)[idx], m-k, M) << " " << (1<<idx) << "\n\n";
            }
            ans += (sum*((1ll<<idx) % M))%M;
            ans %= M;
        }
        a[i] = ans%M;
    }

    for(ll i=1; i<n; i++) a[i] = (a[i] + a[i-1])%M;

    cin >> q;
    while(q--)
    {
        ll t;
        cin >> t;
        cout << a[t-1]%M << '\n';
    }
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    //cin >> t;
    inverseOfNumber(M);
    inverseOfFactorial(M);
    factorial(M);
    
    while(t--)
    {
        calc();
        cout << '\n';
    }
    
    return 0;
}
