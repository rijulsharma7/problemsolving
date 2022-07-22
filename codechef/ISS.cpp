#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, b) for (ll (i) = 1; (i) < (b); ++(i) )
#define n 5e6
std::vector<ll> phi(10000007, 0);
std::vector<ll> v(10000007, 0);

// took reference from
// https://www.geeksforgeeks.org/eulers-totient-function-for-all-numbers-smaller-than-or-equal-to-n/
// which was publically available before the start of the contest !!

void computeTotient()
{
    // Create and initialize an array to store
    // phi or totient values
    //long long phi[n+1];
    for (int i = 1; i <= n; i++)
        phi[i] = i; // indicates not evaluated yet
    // and initializes for product
    // formula.

    // Compute other Phi values
    for (int p = 2; p <= n; p++)
    {
        // If phi[p] is not computed already,
        // then number p is prime
        if (phi[p] == p)
        {
            // Phi of a prime number p is
            // always equal to p-1.
            phi[p] = p - 1;

            // Update phi values of all
            // multiples of p
            for (int i = 2 * p; i <= n; i += p)
            {
                // Add contribution of p to its
                // multiple i by multiplying with
                // (1 - 1/p)
                phi[i] = (phi[i] / p) * (p - 1);
            }
        }
    }
    // Print precomputed phi values
    // for (int i=1; i<=n; i++)
    // cout << "Totient of " << i << " is "
    //     << phi[i] << endl;
}

void precompute()
{
    computeTotient();
    phi[0] = 1;
    v[0] = 0;
    rep(i, n) {
        phi[i]++;
        v[i] = i - 1;
    }

    rep(a, n)
    {
        int counter = 2;
        ll b = counter * a;
        while (b < n)
        {

            ll sol = phi[counter];
            sol /= 2;
            sol *= a;
            v[b] += sol;
            counter++;
            b = counter * a;
        }
    }

    // for (int i = 0; i < n; i++) cout << phi[i] << " ";
    // cout << '\n';
    // for (int i = 0; i < n; i++) cout << v[i] << " ";
    // cout << '\n';

}

ll sq(ll k) { return k * k; }

void calc()
{
    ll k;
    cin >> k;
    ll sol = (k + sq(2 * k + 1) ) - (k + sq(2 * k) );
    cout << v[sol];
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

    precompute();

    int t = 1;
    cin >> t;
    rep(z, t + 1)
    {
        //cout << "Case #" << z << ": ";
        calc();
        cout << '\n';
    }

    return 0;
}
