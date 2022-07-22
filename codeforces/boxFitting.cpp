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

int powerOfTwo(ll n)
{
    int cnt = -1;
    while(n)
    {
        n = n >> 1;
        cnt++;
    }
    return cnt;
}

void calc(ll* p)
{
    ll n, w;
    cin >> n >> w;
    ll a[n], arr[33] = {0};
    for(ll i=0; i<n; i++) 
    {
        cin >> a[i];
        arr[powerOfTwo(a[i])]++;
    }
    //for(auto x : arr) cout << x << " ";
    ll res = 0;
    while(n > 0)
    {
        ll x = w;
        while(x > 0 && n > 0)
        {
            for(int i=32; i>=0; i--)
            {
                if(arr[i] > 0) 
                {
                    if( (x - p[i]) >= 0) 
                    {
                        x -= p[i];
                        arr[i]--;
                        n--;
                        break;
                    }
                }
            }
        }
        res++;
    }
    cout << res;
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    ll p[33];
    for(int i=0; i<33; i++) p[i] = 1ll<<i;
    
    while(t--)
    {
        calc(p);
        cout << '\n';
    }
	
    return 0;
}
