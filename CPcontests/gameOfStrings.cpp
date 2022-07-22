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

void calc(bool* arr, int idx)
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
    if(o > e) arr[idx] = false;
    else arr[idx] = true;
}

bool chk(int* arr, int n, int x)
{
    for(int i=0; i<n; i++) if(arr[i] == x) return true;
    return false;
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    int n = t;
    bool arr[t] = {false};
    int idx = 0;
    while(n--)
    {
        calc(arr, idx);
        idx++;
        //cout << '\n';
    }
    int m;
    cin >> m;
    int resA = 0, resB = 0;
    while(m--)
    {
        int z = t/2;
        int ans[z];
        for(int i=0; i<z; i++) cin >> ans[i];
        //for(int i=0; i<z; i++) cout << ans[i] << " ";
        int a = 0, b = 0;
        for(int i=0; i<t; i++)
        {
            if( chk(ans, z, i+1) and arr[i]) a++;
            else if( !chk(ans, z, i+1) and arr[i]) b++;
        }
        //cout << a << " " << b << '\n';
        if(a > b) resA++;
        else if(a < b) resB++;
    }
    //for(int i=0; i<t; i++) cout << arr[i] << " ";
    //cout << '\n';
    //cout << resB << " " << resA << '\n';
    if(resA > resB) cout << "Ayushi " << resA;
    else if(resA < resB) cout << "Ayush " << resB;
    else cout << "Draw ";
    return 0;
}
