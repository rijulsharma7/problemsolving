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
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;

    int arr[1001];
    for(int i=0; i<1001; i++) arr[i] = i*i;
    
    while(t--)
    {
        for(int i=1; i<1001; i++)
        {
            cout << arr[i] << '\n';
            cout << flush;
            int k;
            cin >> k;
            if(k != 0) break;
        }
    }
	
    return 0;
}
