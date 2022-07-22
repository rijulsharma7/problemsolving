#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
	if( a == 0){
		return b;
	}
	return gcd(b%a, a);
}

int main() {
	long long a;
	long long b;
	cin>>a>>b;
	long long p = a*b;
	cout<< ( a < b ? ( p / gcd(a,b) ) : ( p / gcd(b,a) ) );
	return 0;
}