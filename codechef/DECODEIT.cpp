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

void solve(ll n)
{
    string s;
    cin >> s;
    char a[16] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'};
    int begin = 0;
    int end = 15;
    for(int i=0; i<s.length(); )
    {
        if(s[i++] == '0') end = (end+begin) / 2;
        else begin = ( (begin+end) / 2 ) + 1;

        if(s[i++] == '0') end = (end+begin) / 2;
        else begin = ( (begin+end) / 2 ) + 1;

        if(s[i++] == '0') end = (end+begin) / 2;
        else begin = ( (begin+end) / 2 ) + 1;

        if(s[i++] == '0') end = (end+begin) / 2;
        else begin = ( (begin+end) / 2 ) + 1;

        cout << a[begin];
        begin = 0;
        end = 15;
    }
}

//ll solve(ll n)

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    
    while(t--)
    {
        ll n;
        cin >> n; 
        
        solve(n);
        //cout << solve(n);
        
        cout << '\n';
        
    }
	
    return 0;
}
