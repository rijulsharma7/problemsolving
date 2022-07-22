#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void seive_prime( ll a, ll b )
{
	ll arr[b] = {0};

    arr[0] = arr[1] = 0;
    arr[2] = 1;
    
    for( ll i=3; i<b; i+=2 )
	{ 
		arr[i] = 1;
	}

	for( ll i=3; i<b; i+=2 )
	{  
		if( arr[i] == 1 )
		{ 
			for( ll j=i*i; j<b; j+=i )
			{ 
				arr[j] = 0;
			}
		}
	}

	for( ll k=a; k<b; k++ )
	{  
		if( arr[k] == 1 )
		{  
			cout<< k <<" ";
		}
	}
	cout<<'\n';
	return;
}

signed main()
{
	
	ll t;
	cin>>t;
	while ( t-- )
	{
		ll a, b;
		cin>>a>>b;
		seive_prime( a, b+1 );
	}

	return 0;

}