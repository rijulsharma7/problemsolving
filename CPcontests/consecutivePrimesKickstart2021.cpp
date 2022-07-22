
// took reference from
// https://www.geeksforgeeks.org/segmented-sieve/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
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
#define rep(a, b) for (auto&(a) : (b))
#define fi get<0>
#define se get<1>
#define th get<2>
#define mp make_pair
#define mt make_tuple
#define pb push_back
ll inf = 1e18;
ll mod = 1e9 + 7;
bool compare(ll a, ll b) {return a > b;}
ll gcd(ll a , ll b) {if (b == 0) return a; a %= b; return gcd(b, a);}

ll primes[99999999];
ll sz = 0;

void sieve(ll range, vector<ll> &prime)
{
    vector<bool> mark(range + 1, true);

    for (ll p = 2; p * p < range; p++)
    {
        if (mark[p] == true)
        {
            for (ll i = p * p; i < range; i += p)
                mark[i] = false;
        }
    }

    for (ll p = 2; p < range; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
            primes[sz++] = p;
        }
    }
}

void segmentedSieve(ll n)
{
    ll range = floor(sqrt(n)) + 1;
    vector<ll> prime;
    prime.reserve(range);
    sieve(range, prime);

    ll down = range;
    ll up = 2 * range;

    while (down < n)
    {
        if (up >= n)
            up = n;

        bool mark[range + 1];
        memset(mark, true, sizeof(mark));

        for (ll i = 0; i < prime.size(); i++)
        {
            ll loLim = floor(down / prime[i]) * prime[i];
            if (loLim < down)
                loLim += prime[i];

            for (ll j = loLim; j < up; j += prime[i])
                mark[j - down] = false;
        }

        for (ll i = down; i < up; i++)
            if (mark[i - down] == true)
                primes[sz++] = i;

        down = down + range;
        up = up + range;
    }
}

void calc(int z)
{
    cout << "Case #" << z << ": ";
    ll n;
    cin >> n;
    auto it = lower_bound(primes, primes + sz, sqrt(n));
    int idx = it - primes;
    //cout << idx << " " << primes[idx] << '\n';
    while (primes[idx] * primes[idx + 1] > n)
    {
        idx--;
    }
    //cout << idx << " " << primes[idx] << '\n';
    cout << primes[idx] * primes[idx + 1];
}

int main()
{
    segmentedSieve(1111111111);

    int t = 1;
    cin >> t;
    for (int z = 1; z <= t; z++)
    {
        calc(z);
        cout << '\n';
    }

    return 0;
}
