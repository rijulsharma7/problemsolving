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

void rev(ll* arr, ll i, ll j)
{
	while(i < j)
	{
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	return;
}

void calc(int tmp)
{
	ll n;
	cin >> n;
	ll arr[n];
	for(ll i=0; i<n; i++) cin >> arr[i];
	ll res = 0;

	for(ll i=0; i<n-1; i++)
	{
		ll min = INT_MAX, idx = -1;
		for(ll j=i; j<n; j++)
		{
			if(arr[j] < min) 
			{
				min = arr[j];
				idx = j;
			}
		}
		//cout << idx << " " << min << '\n';
		rev(arr, i, idx);
		res += idx - i + 1;
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
