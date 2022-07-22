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
    string s;
    cin >> s;
    ll freq[27] = {0};
    for(ll i=0; i<s.length(); i++) freq[s[i]-'a']++;
    ll e = 0, o = 0; 
    for(int i=0; i<27; i++)
    {
        if(freq[i] == 0) continue;
        if(freq[i] == 1) o++;
        else if(freq[i]%2 && freq[i] > 3) e += (freq[i] - 3)/2;
        else if(freq[i]%2 == 0) e += freq[i]/2;
    }
    if(o > e) cout << "NO";
    else cout << "YES";
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
