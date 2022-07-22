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
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    ll s = 0, ones = 0;
    for(ll i=0; i<n; i++) 
    {
        cin >> arr[i];
        if(i < k) s += arr[i];
        if(arr[i] == 1) ones++;
    }
    ll i = 0, j = k-1, ans = s;
    while(j < n-1)
    {
        i++;j++;
        if(arr[i-1] == 1) s--;
        if(arr[j] == 1) s++;
        ans = min(s, ans);
    }
    cout << (ans*(ans+1)/2) + ones - ans;
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
