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

void calc(int tmp)
{
    ll n, c;
    cin >> n >> c;
    if(c < n-1) 
    {
        cout << "Case #" << tmp << ": " << "IMPOSSIBLE";
        return;
    }
    ll arr[n];
    for(ll i=0; i<n; i++) arr[i] = i+1;
    c -= n-1;
    ll i = n-2;

    while(c > 0 && i >= 0)
    {
        ll x = n-1 - i;
        if(c >= x)
        {
            c -= x;
            reverse(arr+i,arr+n);
        }
        else
        {
            reverse(arr+i,arr+i+c+1);
            c = 0;
        }
        i--;
    }

    if(c == 0)
    {
        cout << "Case #" << tmp << ": ";
        for(auto x : arr) cout << x << " ";
    } 
    else cout << "Case #" << tmp << ": " << "IMPOSSIBLE";
    return;
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    int tmp = 1;
    
    while(t--)
    {
        calc(tmp);
        cout << '\n';
        tmp++;
    }
    
    return 0;
}
