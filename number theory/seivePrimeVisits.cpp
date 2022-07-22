#include<bits/stdc++.h>
using namespace std;
#define ll long long

void seive_prime( int *arr, ll size )
{
	for( ll i=3; i<size; i+=2 )
	{
		arr[i] = 1;
	}

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

void primeVisits ( ll *p, int *a, ll size )
{
	ll j = 0;

    for ( ll i=1; i<size; i++)
    {
    	if( a[i] == 1 )
    	{
    		p[j++] = i;
    	}
    }

    return;
}

int main()
{
	int arr[100005] = {0};
	ll size = sizeof(arr)/sizeof(int);

	seive_prime( arr, size );

	ll primes[100005] = {0};
	primeVisits( primes, arr, size );

	int t;
	cin>>t;
	while( t-- )
	{
		ll a;
		ll b;
		cin>>a>>b;

		cout<< ( primes[b] - primes[a-1] );

	    cout<<'\n';
	}

	return 0;

}