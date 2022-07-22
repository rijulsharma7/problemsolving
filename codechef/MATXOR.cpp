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

void calc()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll mx = max(m, n);
    ll mn = min(m, n);
    ll s = m+n;
    ll arr[s+1], j = 1;
    arr[0] = 0;
    for(ll i=1;i<s;i++)
    {
        if(i <= mn) arr[i] = i;
        else if(i > mn && i <= mx) arr[i] = mn;
        else 
        {
            arr[i] = mn - j;
            j++;
        }
    }
    j = 1;
    ll res = 0;
    for(ll i=k+2; i<=k+s; i++)
    {
        if(arr[j]%2 != 0) res ^= i;
        j++;
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
    
    while(t--)
    {
        calc();
        cout << '\n';
    }
    
    return 0;
}
