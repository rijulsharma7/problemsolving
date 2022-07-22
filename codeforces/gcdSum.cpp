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

ll sumN(ll n)
{
    ll s = 0;
    while(n > 0)
    {
        s += n%10;
        n /= 10;
    }
    return s;
}

void calc()
{
    ll n;
    cin >> n;
    ll s = sumN(n);
    ll res = __gcd(n, s);
    if(res > 1) cout << n;
    else
    {
        while(res <= 1)
        {
            n++;
            s = sumN(n);
            res = __gcd(n, s);
        }
        cout << n;
    }
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while(t--)
    {
        calc();
        cout << '\n';
    }
    
    return 0;
}
