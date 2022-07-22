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
    string s;
    ll x, y;
    cin >> x >> y >> s;
    ll n = s.length();

    ll res = 0;
    ll i = 0;
    while(i < n)
    {
        if(s[i]!='?' && i>0)
        {
             if(s[i]==s[i-1]){ 
             }
             else if(s[i]=='C') res += y;
             else res += x;
                i++;
                continue;
        }
        else if(s[i]=='?')
        {
            ll j;
              for( j=i; j<n; j++){
                  if(s[j]!='?') break;
              }
              if(j==n) break;
              if(i>0){
               if(s[j]==s[i-1]){
              }
              else if(s[j]=='C') res += y;
               else if(s[j]=='J') res += x;
               
            }
            
            i=j+1;
            continue;
        }
        i++;
    }

    cout << "Case #" << tmp << ": " <<res;
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
