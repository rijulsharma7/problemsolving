#include<bits/stdc++.h> 
using namespace std; 

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vii = vector<pi>;
using vll = vector<pl>;

bool compare(ll a, ll b){ return a > b; }

// **I took help from 
// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
// which was publically available before the start of the contest !! **

ll minDiff(vl v)
{
    ll sum = 0; 
    for (auto x : v) sum += x;

    bool dp[v.size()+1][sum+1];
 
    for (ll i = 0; i <= v.size(); i++) dp[i][0] = 1;
 
    for (ll i = 1; i <= sum; i++) dp[0][i] = 0;
 
    for (ll i=1; i<=v.size(); i++)
    {
        for (ll j=1; j<=sum; j++)
        {
            dp[i][j] = dp[i-1][j];
            if (v[i-1] <= j) dp[i][j] |= dp[i-1][j-v[i-1]];
        }
    }

    ll diff = INT_MAX;
    for (ll j=sum/2; j>=0; j--)
    {
        if (dp[v.size()][j])
        {
            diff = sum-2*j;
            break;
        }
    }

    return diff;
}

ll solve(ll n, ll k)
{
    ll a[n];
    for(ll i=0; i<n; i++) cin >> a[i];
    if(n == 1) return -1;
    sort(a,a+n,compare);
    ll s = 0, i;
    vl v;
    for(i=0; i<n; i++)
    {
        v.push_back(a[i]);
        s += a[i];
        if(s >= 2*k && i != 0) 
        {
            i++;
            break;
        }
    }
    //cout<<endl<<i<<endl;
    ll diff = minDiff(v);
    if( (s - diff) >= 2*k ) return v.size();
    ll cnt = 0;
    while(i != n)
    {
        diff -= a[i];
        s += a[i];
        cnt++;
        if( (s - diff) >= 2*k ) return v.size() + cnt;
        i++;
    }
    if( (s - diff) >= 2*k ) return v.size() + cnt;
    return -1;
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
        ll n, k;
        cin >> n >> k; 
        
        //solve(n);
        cout << solve(n,k);
        
        cout << '\n';
        
    }
    
    return 0;
}
