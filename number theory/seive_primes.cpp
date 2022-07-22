#include<bits/stdc++.h>
using namespace std;
#define ll long long

void seive_prime( int *arr, ll size )
{
	for(ll i=3; i<size; i+=2) arr[i] = 1;

	for(ll i=3; i*i<size; i+=2)	if(arr[i] == 1)	for(ll j=i*i; j<size; j+=i) arr[j] = 0;

	arr[2] = 1;
	arr[0] = arr[1] = 0;
}

int main()
{
	int arr[1000000] = {0};
	ll size = sizeof(arr)/sizeof(int);

	seive_prime(arr, size);

	int n;
	cin>>n;

	int primes[n];
	int i = 0;
	int j = 0;
	while( i < n ) 
	{
		if( arr[j] == 1 )
		{
			primes[i++] = j;
		}
		j++;
	}

	for(int k=0; k<n; k++){
		cout<<primes[k]<<" ";
	}

	return 0;

}