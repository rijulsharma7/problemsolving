#include<iostream>
#include<climits>
using namespace std;
#define long long int ll;
int main() {
	long int n;
	int y=2,x=1;
	cin>>n;
	ll=INT_MAX;
	for(;y<ll;y++){
		while(x<y){
			if(y*y== x*x + n*n){
				cout<<x<<" "<<y;
				break;
			}
            x++;
		}
			if(y*y== x*x + n*n){
				break;
			}
	}
		if(y*y!= x*x + n*n){
			cout<<"-1";
		}
	return 0;
}