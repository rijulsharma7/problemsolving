#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int no;
	while(n>0){
		cin>>no;
		int r;
		int ans=0;
		int p=1;
		while(no>0){
			 r=no%10;
			ans=ans+r*p;
			p=p*2;
			no=no/10;
		}
		cout<<ans<<endl;
		n=n-1;
	}
	return 0;
}