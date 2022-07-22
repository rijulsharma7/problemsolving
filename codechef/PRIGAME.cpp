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

void seive_prime(ll *arr, ll size)
{
    for(ll i=3; i<size; i+=2) arr[i] = 1;

    for( ll i=3; i<size; i+=2 )
    {
        if( arr[i] == 1 )
        {
            for( ll j=i*i; j<size; j+=i )
            {
                arr[j] = 0;
            }
        }
    }

    arr[2] = 1;
    arr[0] = arr[1] = 0;
    return;
}

void count_prime(ll* arr, ll size)
{
    ll cnt = 0;
    for(ll i=2; i<size; i++)
    {
        if(arr[i] == 1) cnt++;
        arr[i] = cnt;
    }
}

void calc(ll* arr)
{

    ll x, y;
    cin >> x >> y;

    if(arr[x] > y) cout << "Divyam";
    else cout << "Chef";    
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    ll arr[1000005] = {0};
    ll size = sizeof(arr)/sizeof(ll);
    seive_prime(arr, size);
    count_prime(arr, size);
    
    int t = 1;
    cin >> t;
    
    while(t--)
    {
        calc(arr);
        cout << '\n';
    }
    
    return 0;
}
