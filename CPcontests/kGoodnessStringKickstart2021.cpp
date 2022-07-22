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

void calc(int x, int t)
{
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll start = 0, end = n-1, cnt = 0;
    while(start < end)
    {
        if(s[start] != s[end]) cnt++;
        start++;
        end--;
    }
    if(x == t) cout << "Case #" << x << ": " << abs(k - cnt);
    else cout << "Case #" << x << ": " << abs(k - cnt) << " \n";

}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    int tmp = t;
    int x = 1;
    
    while(t--)
    {
        calc(x, tmp);
        x++;
    }

	
    return 0;
}
